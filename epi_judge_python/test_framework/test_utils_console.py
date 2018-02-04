# @library
from test_framework.console_color import ConsoleColor, print_std_out_colored
from test_framework.platform import use_tty_output
from test_framework.test_output import TestOutput
from test_framework.test_result import TestResult
from test_framework.test_timer import duration_to_string, avg_and_median_from_durations


def escape_newline(s):
    return s.replace('\n', '\\n').replace('\r', '\\r')


def return_caret_if_tty_output():
    if use_tty_output():
        print('\r', end='')
    else:
        print('\n', end='')


_print_test_result_values = {
    TestResult.PASSED: ('PASSED', ConsoleColor.FG_GREEN),
    TestResult.FAILED: ('FAILED', ConsoleColor.FG_RED),
    TestResult.TIMEOUT: ('TIMEOUT', ConsoleColor.FG_BLUE),
    TestResult.UNKNOWN_EXCEPTION: ('UNHANDLED EXCEPTION', ConsoleColor.FG_RED),
    TestResult.STACK_OVERFLOW: ('STACK OVERFLOW', ConsoleColor.FG_RED)
}


def print_test_result(test_result):
    if test_result in _print_test_result_values:
        print_std_out_colored(_print_test_result_values[test_result][1],
                              _print_test_result_values[test_result][0])
    else:
        raise RuntimeError('Unknown TestResult')


def print_test_info(test_result, test_nr, total_tests, diagnostic, timer):
    diagnostic = diagnostic.rstrip('\n')

    return_caret_if_tty_output()

    total_tests_str = str(total_tests)
    print('Test ', end='')
    print_test_result(test_result)
    print(
        ' ({:>{test_nr_w}}/{})'.format(
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


def gen_spaces(count):
    return ' ' * count


def print_failed_test(param_names, arguments, test_output, test_explanation,
                      res_printer):
    expected_str = 'expected'
    result_str = 'result'
    explanation_str = 'explanation'

    has_expected = test_output and test_output.expected is not TestOutput.EMPTY_OBJECT
    has_result = test_output and test_output.result is not TestOutput.EMPTY_OBJECT
    has_explanation = test_explanation not in {'TODO', ''}

    max_col_size = \
        len(explanation_str) if has_explanation else \
            len(expected_str) if has_expected else \
                len(result_str) if has_result else \
                    0

    for param in param_names:
        if len(param) > max_col_size:
            max_col_size = len(param)

    for (name, value) in zip(param_names, arguments):
        print('\t{}: {}{}'.format(name, gen_spaces(max_col_size - len(name)),
                                  escape_newline(str(value))))

    if has_expected or has_result:
        expected = test_output.expected
        result = test_output.result
        if res_printer:
            (expected, result) = res_printer(expected, result)

        if has_expected:
            print('\t{}: {}{}'.format(
                expected_str, gen_spaces(max_col_size - len(expected_str)),
                escape_newline(str(expected))))
        if has_result:
            print('\t{}: {}{}'.format(
                result_str, gen_spaces(max_col_size - len(result_str)),
                escape_newline(str(result))))
    if has_explanation:
        print('\t{}: {}{}'.format(
            explanation_str, gen_spaces(max_col_size - len(explanation_str)),
            test_explanation))


def print_post_run_stats(tests_passed, total_tests, durations):
    if durations:
        avg_median = avg_and_median_from_durations(durations)
        print(
            'Average running time: {}\n'
            'Median running time:  {}\n'.format(
                duration_to_string(avg_median[0]),
                duration_to_string(avg_median[1])),
            end='')
    if tests_passed < total_tests:
        print('*** You\'ve passed {}/{} tests. ***'.format(
            tests_passed, total_tests))
    else:
        print('*** You\'ve passed ALL tests. Congratulations! ***')
