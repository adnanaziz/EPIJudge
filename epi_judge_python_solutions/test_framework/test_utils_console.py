
from test_framework.console_color import ConsoleColor, print_std_out_colored
from test_framework.platform import std_out_clear_line, use_tty_output
from test_framework.test_result import TestResult
from test_framework.test_timer import avg_and_median_from_durations, duration_to_string


def escape_newline(s):
    return s.replace('\n', '\\n').replace('\r', '\\r')


def clear_line_if_tty():
    if use_tty_output():
        std_out_clear_line()
    else:
        print(end='\n')


_print_test_result_values = {
    TestResult.PASSED: ('PASSED', ConsoleColor.FG_GREEN), TestResult.FAILED:
    ('FAILED', ConsoleColor.FG_RED), TestResult.TIMEOUT:
    ('TIMEOUT', ConsoleColor.FG_BLUE), TestResult.UNKNOWN_EXCEPTION:
    ('UNHANDLED EXCEPTION',
     ConsoleColor.FG_RED), TestResult.STACK_OVERFLOW: ('STACK OVERFLOW',
                                                       ConsoleColor.FG_RED)
}


def print_test_result(test_result):
    if test_result in _print_test_result_values:
        print_std_out_colored(_print_test_result_values[test_result][1],
                              _print_test_result_values[test_result][0])
    else:
        raise RuntimeError('Unknown TestResult')


def print_test_info(test_result, test_nr, total_tests, diagnostic, timer):
    diagnostic = diagnostic.rstrip('\n')

    caret_at_line_start = print_test_info.__dict__.get('caret_at_line_start',
                                                       True)
    if not caret_at_line_start:
        clear_line_if_tty()

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

    if timer is not None:
        print(
            ' [{}]'.format(duration_to_string(timer.get_microseconds())),
            end='',
            flush=True)

    print_test_info.caret_at_line_start = False

    if test_result != TestResult.PASSED:
        print(' {}'.format(diagnostic), flush=True)
        print_test_info.caret_at_line_start = True


def gen_spaces(count):
    return ' ' * count


def print_failed_test(param_names, arguments, test_failure, res_printer):
    max_col_size = test_failure.get_max_property_name_length()

    for param in param_names:
        if len(param) > max_col_size:
            max_col_size = len(param)

    print_std_out_colored(ConsoleColor.FG_YELLOW, 'Arguments')
    print()

    for (name, value) in zip(param_names, arguments):
        print('\t', end='')
        print_std_out_colored(ConsoleColor.FG_YELLOW, name)
        print(': {}{}'.format(
            gen_spaces(max_col_size - len(name)), escape_newline(str(value))))

    properties = test_failure.get_properties()

    print_std_out_colored(ConsoleColor.FG_YELLOW, '\nFailure info\n')

    for prop in properties:
        if res_printer is not None:
            value = res_printer(prop.raw_name(), prop.value())
        else:
            value = prop.value()
        print('\t', end='')
        print_std_out_colored(ConsoleColor.FG_YELLOW, prop.name())
        print(': {}{}'.format(
            gen_spaces(max_col_size - len(prop.name())), value))


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
