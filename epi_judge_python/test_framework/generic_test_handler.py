# @library
import inspect

from test_framework.test_output import TestOutput
from test_framework.test_timer import TestTimer
from test_framework.test_utils_deserialization import get_string_parser_for_type

from test_framework import test_utils


class GenericTestHandler:
    """
    The central class in generic test runner framework.

    It is responsible for constructing string deserializers
    basing on the test data header and
    executing tests on the provided function (which includes
    the deserialization of the provided arguments and the expected value,
    invocation of the target function with these arguments and
    comparison of the computed result with the expected value).

    parse_signature() and run_test() raise RuntimeError
    in case of any error or assertion failure. This exception
    terminates testing and, consequently, the test program.

    If tested function throws TestFailureException or StackOverflowError,
    the current test is raise as failed and the execution goes on.
    In case of any other exception raised by the tested function,
    the test program is terminated.
    """

    def __init__(self, func, comp):
        self._func = func
        self._has_timer_hook = test_utils.has_timer_hook(func)
        self._param_parsers = []
        self._param_names = [
            p.name
            for p in inspect.signature(self._func).parameters.values()
            if p.default is inspect.Parameter.empty
        ][1 if self._has_timer_hook else 0:]
        self._comp = comp

    def parse_signature(self, signature):
        """
        This method initializes type parsers
        for all tested function arguments and expected value,
        basing on test data signature (see get_string_parser_for_type()).

        :param signature: the header from a test data file.
        :type signature: List[str]
        """
        if len(signature) != len(self._param_names) + 1:
            raise RuntimeError("Signature parameter count mismatch")

        signature = [test_utils.filter_bracket_comments(s) for s in signature]

        for param in signature[:-1]:
            self._param_parsers.append(get_string_parser_for_type(param))

        if any(p is None for p in self._param_parsers):
            raise RuntimeError("Argument can't be of type void")

        self._ret_value_parser = get_string_parser_for_type(signature[-1])

    def run_test(self, test_args):
        """
        This method is invoked for each row in a test data file (except the header).
        It deserializes the list of arguments and calls the user function with them.

        :param test_args: serialized arguments
        :return: list, that contains [result of comparison of expected and result, expected, result].
                 Two last entries are omitted in case of the void return type
        """
        args = [
            parser(x)
            for parser, x in zip(self._param_parsers,
                                 test_args[:-1 if not self.expected_is_void()
                                           else len(test_args)])
        ]
        timer = TestTimer()
        if self._has_timer_hook:
            args = [timer] + args

        if not self.expected_is_void():
            expected = self._ret_value_parser(test_args[-1])

            timer.start()
            result = self._func(*args)
            timer.stop()

            return TestOutput(
                self._comp(expected, result), timer, expected, result)
        else:
            timer.start()
            self._func(*args)
            timer.stop()

            return TestOutput(True, timer)

    def expected_is_void(self):
        return self._ret_value_parser is None

    def param_names(self):
        return self._param_names
