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
        self._param_parsers = []
        self._function = func
        self._comp = comp
        self._has_timer_hook = test_utils.has_timer_hook(func)

    def parse_signature(self, header):
        """
        This method initializes type parsers
        for all tested function arguments and expected value,
        basing on test data header (see get_string_parser_for_type()).

        :param header: test data header
        :type header: List[str]
        """
        sig = inspect.signature(self._function)
        min_arg_count = test_utils.nondefault_param_count(sig)
        max_arg_count = sum(1 for _ in sig.parameters)

        if self._has_timer_hook:
            min_arg_count -= 1
            max_arg_count -= 1

        if not (min_arg_count <= (len(header) - 1) <= max_arg_count):
            raise RuntimeError("Signature parameter count mismatch")

        header = [test_utils.filter_bracket_comments(s) for s in header]

        for param in header[:-1]:
            self._param_parsers.append(get_string_parser_for_type(param))

        if any(p is None for p in self._param_parsers):
            raise RuntimeError("Argument can't be of type void")

        self._ret_value_parser = get_string_parser_for_type(header[-1])

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
            result = self._function(*args)
            timer.stop()

            return TestOutput(
                self._comp(expected, result), timer, expected, result)
        else:
            timer.start()
            self._function(*args)
            timer.stop()

            return TestOutput(True, timer)

    def expected_is_void(self):
        return self._ret_value_parser is None
