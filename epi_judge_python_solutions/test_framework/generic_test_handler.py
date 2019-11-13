import inspect
import json
import math

from test_framework import test_utils
from test_framework.binary_tree_utils import (assert_equal_binary_trees,
                                              is_object_tree_type)
from test_framework.serialization_traits import VoidTrait, get_trait
from test_framework.test_failure import PropertyName, TestFailure
from test_framework.test_output import TestOutput
from test_framework.test_utils import (filter_bracket_comments,
                                       has_executor_hook)
from test_framework.timed_executor import TimedExecutor


class GenericTestHandler:
    """
    The central class in generic test runner framework.

    It is responsible for constructing string deserializers basing on the test
    data header and executing tests on the provided function (which includes
    the deserialization of the provided arguments and the expected value,
    invocation of the target function with these arguments and comparison of
    the computed result with the expected value).

    parse_signature() and run_test() raise RuntimeError in case of any error
    or assertion failure. This exception terminates testing and, consequently,
    the test program.

    If tested function throws TestFailure or StackOverflowError,
    the current test is raise as failed and the execution goes on.
    In case of any other exception raised by the tested function,
    the test program is terminated.
    """
    def __init__(self, func, comp):
        self._func = func
        self._has_executor_hook = has_executor_hook(func)
        self._param_traits = None
        self._param_names = [
            p.name for p in inspect.signature(self._func).parameters.values()
            if p.default is inspect.Parameter.empty
        ][1 if self._has_executor_hook else 0:]
        self._comp = comp
        self._ret_value_trait = None

    def parse_signature(self, signature):
        """
        This method initializes type parsers for all tested function arguments
        and expected value, basing on test data signature (see get_trait()).

        :param signature: the header from a test data file.
        :type signature: List[str]
        """
        if len(signature) != len(self._param_names) + 1:
            raise RuntimeError("Signature parameter count mismatch")

        signature = [filter_bracket_comments(s) for s in signature]

        self._param_traits = [get_trait(param) for param in signature[:-1]]

        if any(isinstance(p, VoidTrait) for p in self._param_traits):
            raise RuntimeError("Argument can't be of type void")

        self._ret_value_trait = get_trait(signature[-1])

    def run_test(self, timeout_seconds, metrics_override, test_args):
        """
        This method is invoked for each row in a test data file (except the header).
        It deserializes the list of arguments and calls the user function with them.

        :param timeout_seconds: number of seconds to timeout
        :param metrics_override: metrics transformation for customizing metrics calculation
        :param test_args: serialized arguments
        :return: list, that contains [result of comparison of expected and result, expected, result].
                 Two last entries are omitted in case of the void return type
        """
        expected_param_count = len(
            self._param_traits) + (0 if self.expected_is_void() else 1)
        if len(test_args) != expected_param_count:
            raise RuntimeError(
                'Invalid argument count: expected {}, actual {}'.format(
                    expected_param_count, len(test_args)))

        parsed = [
            param_trait.parse(json.loads(test_arg))
            for param_trait, test_arg in zip(self._param_traits, test_args)
        ]

        metrics = self.calculate_metrics(parsed)
        metrics = metrics_override(metrics, *parsed)

        executor = TimedExecutor(timeout_seconds)
        if self._has_executor_hook:
            result = self._func(executor, *parsed)
        else:
            result = executor.run(lambda: self._func(*parsed))

        if not self.expected_is_void():
            expected = self._ret_value_trait.parse(json.loads(test_args[-1]))
            self._assert_results_equal(expected, result)

        return TestOutput(executor.get_timer(), metrics)

    def _assert_results_equal(self, expected, result):
        if self._comp is not None:
            comparison_result = self._comp(expected, result)
        elif expected is None:
            comparison_result = result is None
        elif isinstance(expected, float) or isinstance(result, float):
            comparison_result = math.isclose(expected, result)
        elif is_object_tree_type(expected) or is_object_tree_type(result):
            assert_equal_binary_trees(expected, result)
            return
        else:
            comparison_result = expected == result

        if not comparison_result:
            raise TestFailure()\
                .with_property(PropertyName.EXPECTED, expected)\
                .with_property(PropertyName.RESULT, result)

    def metric_names(self):
        return test_utils.flatten_list(
            param_trait.get_metric_names(param_name) for param_trait,
            param_name in zip(self._param_traits, self._param_names))

    def calculate_metrics(self, params):
        return test_utils.flatten_list(
            param_trait.get_metrics(param)
            for param_trait, param in zip(self._param_traits, params))

    def expected_is_void(self):
        return self._ret_value_trait.is_void()

    def param_names(self):
        return self._param_names
