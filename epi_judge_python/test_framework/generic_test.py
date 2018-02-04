# @library
import sys

from os import path

from test_framework.generic_test_handler import GenericTestHandler
from test_framework.test_config import TestConfig
from test_framework.test_failure_exception import TestFailureException
from test_framework.test_output import TestOutput
from test_framework.test_result import TestResult
from test_framework.test_timer import TestTimer
from test_framework.test_utils import equal_to, split_tsv_file, invoke_with_timeout
from test_framework.test_utils_console import print_test_info, print_failed_test, print_post_run_stats
from test_framework.timeout_exception import TimeoutException


def generic_test_main(test_data_file,
                      test_func,
                      comparator=equal_to,
                      res_printer=None):
    """
    The main test starter.
    :param test_data_file - file with test data
    :param test_func - function to be tested
    :param comparator - custom comparator. A function that accepts
        (expected, computed result) and returns a boolean value
    :param res_printer - function for customized printing
    """
    try:
        commandline_args = sys.argv[1:]
        config = TestConfig.from_command_line(test_data_file, commandline_args)

        test_handler = GenericTestHandler(test_func, comparator=comparator)
        run_tests(test_handler, config, res_printer)
    except RuntimeError as e:
        print(
            '\nCritical error({}): {}'.format(e.__class__.__name__, e),
            file=sys.stderr)


def run_tests(handler, config, res_printer):
    test_data = split_tsv_file(
        path.join(config.test_data_dir, config.test_data_file))
    handler.parse_signature(test_data[0])

    test_nr = 0
    tests_passed = 0
    total_tests = len(test_data) - 1
    durations = []

    for test_case in test_data[1:]:
        test_nr += 1

        # Since the last field of test_data is test_explanation, which is not
        # used for running test, we extract that here.
        test_explanation = test_case.pop()

        result = TestResult.FAILED
        test_output = None
        diagnostic = ''

        try:
            test_output = invoke_with_timeout(
                config.timeout, lambda: handler.run_test(test_case))
            result = TestResult.PASSED if test_output.comparison_result \
                else TestResult.FAILED
        except TestFailureException as exc:
            result = TestResult.FAILED
            diagnostic = str(exc)
        except TimeoutException:
            result = TestResult.TIMEOUT
        except RecursionError:
            result = TestResult.STACK_OVERFLOW
        except RuntimeError:
            raise
        except Exception as exc:
            result = TestResult.UNKNOWN_EXCEPTION
            diagnostic = exc.__class__.__name__ + ': ' + str(exc)

        if test_output is None:
            test_output = TestOutput(False, TestTimer())
            # Append expected value if execution ended due to an exception
            if not handler.expected_is_void():
                test_output.expected = test_case[-1]

        print_test_info(result, test_nr, total_tests, diagnostic,
                        test_output.timer)

        if result == TestResult.PASSED:
            tests_passed += 1
        if test_output.timer.has_valid_result():
            durations.append(test_output.timer.get_microseconds())

        if result != TestResult.PASSED and config.stop_on_error:
            if not handler.expected_is_void():
                test_case.pop()
            print_failed_test(handler.param_names(), test_case, test_output,
                              test_explanation, res_printer)
            break

    print()

    if config.stop_on_error:
        print_post_run_stats(tests_passed, total_tests, durations)
