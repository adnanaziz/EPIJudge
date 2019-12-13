import json
import os
import sys

from test_framework.generic_test_handler import GenericTestHandler
from test_framework.platform import set_output_opts
from test_framework.test_config import TestConfig
from test_framework.test_failure import PropertyName, TestFailure
from test_framework.test_output import TestOutput
from test_framework.test_result import TestResult
from test_framework.test_utils import (get_file_path_in_judge_dir,
                                       split_tsv_file)
from test_framework.test_utils_console import (print_failed_test,
                                               print_post_run_stats,
                                               print_test_info,
                                               show_complexity_notification)
from test_framework.timeout_exception import TimeoutException


def generic_test_main(test_file,
                      test_data_file,
                      test_func,
                      comparator=None,
                      res_printer=None,
                      program_config=None):
    """
    The main test starter.

    :param test_file - name of the test file
    :param test_data_file - file with test data
    :param test_func - function to be tested
    :param comparator - custom comparator. A function that accepts
        (expected, computed result) and returns a boolean value
    :param res_printer - function for customized printing
    :param program_config - function for customizing test_config
    """
    try:
        with open(
                get_file_path_in_judge_dir('config.json')) as config_file_data:
            config_override = json.load(config_file_data)

        commandline_args = sys.argv[1:]
        config = TestConfig.from_command_line(
            test_file, test_data_file, config_override['timeoutSeconds'],
            config_override['numFailedTestsBeforeStop'], commandline_args)

        if program_config:
            program_config(config)

        set_output_opts(config.tty_mode, config.color_mode)

        test_handler = GenericTestHandler(test_func, comparator)
        return run_tests(test_handler, config, res_printer)
    except RuntimeError as e:
        print('\nCritical error({}): {}'.format(e.__class__.__name__, e),
              file=sys.stderr)
        return TestResult.RUNTIME_ERROR


def run_tests(handler, config, res_printer):
    test_data = split_tsv_file(
        os.path.join(config.test_data_dir, config.test_data_file))
    handler.parse_signature(test_data[0])

    metric_names = config.metric_names_override(handler.metric_names())

    test_nr = 0
    tests_passed = 0
    total_tests = len(test_data) - 1
    metrics = []
    durations = []
    result = TestResult.FAILED

    for test_case in test_data[1:]:
        test_nr += 1

        # Since the last field of test_data is test_explanation, which is not
        # used for running test, we extract that here.
        test_explanation = test_case.pop()

        test_output = TestOutput()
        test_failure = TestFailure()

        try:
            test_output = handler.run_test(config.timeout_seconds,
                                           config.metrics_override, test_case)
            result = TestResult.PASSED
            tests_passed += 1
            metrics.append(test_output.metrics)
            durations.append(test_output.timer.get_microseconds())
        except TestFailure as exc:
            result = TestResult.FAILED
            test_failure = exc
        except TimeoutException as exc:
            result = TestResult.TIMEOUT
            test_output.timer = exc.get_timer()
        except RecursionError:
            result = TestResult.STACK_OVERFLOW
        except RuntimeError:
            raise
        except Exception as exc:
            result = TestResult.UNKNOWN_EXCEPTION
            test_failure = TestFailure(exc.__class__.__name__).with_property(
                PropertyName.EXCEPTION_MESSAGE, str(exc))

        print_test_info(result, test_nr, total_tests,
                        test_failure.get_description(), test_output.timer)

        if result != TestResult.PASSED:
            if not handler.expected_is_void():
                test_case.pop()
            if test_explanation not in ('', 'TODO'):
                test_failure.with_property(PropertyName.EXPLANATION,
                                           test_explanation)
            print_failed_test(handler.param_names(), test_case, test_failure,
                              res_printer)
            tests_not_passed = test_nr - tests_passed
            if tests_not_passed >= config.num_failed_tests_before_stop:
                break

    if config.update_js:
        update_test_passed(config.test_file, tests_passed)

    print()

    if durations:
        complexity = ''
        if metric_names and metrics and config.analyze_complexity:
            show_complexity_notification()

        print_post_run_stats(tests_passed, total_tests, complexity, durations)
    return result


def update_test_passed(test_file, tests_passed):
    problem_mapping_file_path = get_file_path_in_judge_dir(
        'problem_mapping.js')
    js_begin_pattern, js_end_pattern = 'problem_mapping = ', ';'
    with open(problem_mapping_file_path) as problem_mapping_file:
        chapter_to_problem_to_language_solution_mapping = json.loads(
            problem_mapping_file.read().replace(js_begin_pattern, '').replace(
                js_end_pattern, ''))

    test_file = 'Python: ' + test_file
    for chapter in chapter_to_problem_to_language_solution_mapping.values():
        for _, language_solution_mapping in chapter.items():
            if test_file in language_solution_mapping:
                language_solution_mapping[test_file]['passed'] = tests_passed
                with open(problem_mapping_file_path,
                          'w') as problem_mapping_file:
                    problem_mapping_file.write(js_begin_pattern)
                    json.dump(chapter_to_problem_to_language_solution_mapping,
                              problem_mapping_file,
                              indent=4)
                    problem_mapping_file.write(js_end_pattern)
                return
