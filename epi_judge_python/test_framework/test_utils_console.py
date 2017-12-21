# @library
import sys

from test_framework.test_result import TestResult, use_tty_output
from test_framework.test_output import TestOutput
from test_framework.test_timer import duration_to_string


def escape_newline(s):
    return s.replace('\n', '\\n').replace('\r', '\\r')


def return_caret_if_tty_output():
    if use_tty_output():
        print('\r', end='')
    else:
        print('\n', end='')


def print_test_result(test_result, test_nr, total_tests, diagnostic, timer):
    diagnostic = diagnostic.rstrip('\n')

    return_caret_if_tty_output()

    total_tests_str = str(total_tests)
    print(
        'Test {} ({:>{test_nr_w}}/{})'.format(
            test_result,
            test_nr,
            total_tests_str,
            diagnostic,
            test_nr_w=len(total_tests_str)),
        end='',
        flush=True)

    if timer.has_valid_result():
        print(
            ' [{}]'.format(duration_to_string(timer.get_microseconds())),
            end='',
            flush=True)

    if test_result != TestResult.PASSED:
        print(' {}'.format(diagnostic))


def print_failed_test(arguments, test_output, test_explanation, res_printer):
    for (i, a) in enumerate(arguments):
        print('\tArg {}: {}'.format(i + 1, escape_newline(str(a))))

    if not test_output:
        return

    expected = test_output.expected
    result = test_output.result
    if res_printer:
        (expected, result) = res_printer(expected, result)

    if expected is not TestOutput.EMPTY_OBJECT:
        print('\tExpected: {}'.format(escape_newline(str(expected))))
    if result is not TestOutput.EMPTY_OBJECT:
        print('\tResult:   {}'.format(escape_newline(str(result))))
    if test_explanation not in {'TODO', ''}:
        print('\tExplanation: {}'.format(test_explanation))
