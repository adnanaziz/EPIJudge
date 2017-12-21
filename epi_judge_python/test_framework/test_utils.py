# @library
import concurrent.futures
import inspect
import math
import re
import statistics
import sys
import traceback

from test_framework.test_failure_exception import TestFailureException
from test_framework.test_output import TestOutput
from test_framework.test_result import TestResult
from test_framework.test_timer import TestTimer, duration_to_string
from test_framework.test_utils_console import print_test_result, print_failed_test

DEFAULT_TEST_DATA_PATH_DIR = '../test_data/'


def run_tests(test_data_path, handler, timeout, stop_on_error, res_printer):
    def split_tsv_file(data_file):
        ROW_DELIM = '\n'
        FIELD_DELIM = '\t'
        with open(data_file) as input_data:
            return [
                row.replace(ROW_DELIM, '').split(FIELD_DELIM)
                for row in input_data
            ]

    test_data = split_tsv_file(test_data_path)

    handler.parse_signature(test_data[0])

    test_nr = 0
    total_tests = len(test_data) - 1
    tests_passed = 0
    durations = []

    for test_case in test_data[1:]:
        test_nr += 1

        test_explanation = test_case.pop()

        result = TestResult.FAILED
        test_output = None
        diagnostic = ''

        try:
            if timeout != 0:
                with concurrent.futures.ThreadPoolExecutor(
                        max_workers=1) as executor:
                    future = executor.submit(handler.run_test, test_case)
                    test_output = future.result(timeout=timeout)
                    result = TestResult.PASSED if test_output.comparison_result \
                        else TestResult.FAILED
            else:
                test_output = handler.run_test(test_case)
                result = TestResult.PASSED if test_output.comparison_result \
                    else TestResult.FAILED
        except TestFailureException as exc:
            result = TestResult.FAILED
            diagnostic = str(exc)
        except concurrent.futures.TimeoutError:
            result = TestResult.TIMEOUT
        except RecursionError:
            result = TestResult.STACK_OVERFLOW
        except RuntimeError:
            print()
            print()
            print('Critical error:')
            traceback.print_exc(file=sys.stdout)
            exit(0)
        except Exception as exc:
            result = TestResult.UNKNOWN_EXCEPTION
            diagnostic = exc.__class__.__name__ + ': ' + str(exc)

        if test_output is None:
            test_output = TestOutput(False, TestTimer())
            # Append expected value if execution ended due to an exception
            if not handler.expected_is_void():
                test_output.expected = test_case[-1]

        print_test_result(result, test_nr, total_tests, diagnostic,
                          test_output.timer)
        tests_passed += 1 if result == TestResult.PASSED else 0
        if test_output.timer.has_valid_result():
            durations.append(test_output.timer.get_microseconds())

        if result != TestResult.PASSED and stop_on_error:
            if not handler.expected_is_void():
                test_case = test_case[:-1]
            print_failed_test(test_case, test_output, test_explanation,
                              res_printer)
            break

    print()
    if stop_on_error:
        if len(durations):
            print("Average running time: {}".format(
                duration_to_string(statistics.mean(durations))))
            print("Median running time: {}".format(
                duration_to_string(statistics.median(durations))))
        if tests_passed < total_tests:
            print("*** You've passed {}/{} tests. ***".format(
                tests_passed, total_tests))
        else:
            print("*** You've passed ALL tests. Congratulations! ***")


def completely_sorted(x):
    """Multi-dimensional container sort.

    If x is list of lists of ... of lists,
    then the argument is lexicographically sorted on all levels,
    starting from the bottom.
    """
    if isinstance(x, list):
        return sorted(completely_sorted(e) for e in x)
    else:
        return x


def unordered_compare(a, b):
    """Compares elements of 2 (multi-dimensional) list."""
    return completely_sorted(a) == completely_sorted(b)


def equal_to(a, b):
    """Expected value comparator.

    Compares float values with math.isclose(),
    binary trees with equal_binary_trees(),
    and other types with == operator.
    """
    if isinstance(a, float) or isinstance(b, float):
        return math.isclose(a, b)
    import binary_tree_node
    import binary_tree_with_parent_prototype
    import bst_node
    from test_framework.binary_tree_utils import equal_binary_trees
    if (isinstance(a, binary_tree_node.BinaryTreeNode)
            or isinstance(a, binary_tree_with_parent_prototype.BinaryTreeNode)
            or isinstance(a, bst_node.BSTNode)) and (
                isinstance(b, binary_tree_node.BinaryTreeNode) or isinstance(
                    b, binary_tree_with_parent_prototype.BinaryTreeNode)
                or isinstance(b, bst_node.BSTNode)):
        return equal_binary_trees(a, b)
    return a == b


def filter_bracket_comments(s):
    """Serialized type name can contain multiple comments,
       enclosed into brackets.
       This function removes all such comments."""
    bracket_enclosed_comment = r"(\[[^\]]*\])"
    return re.sub(bracket_enclosed_comment, '', s, 0).replace(' ', '')


def nondefault_param_count(s: inspect.Signature):
    """
    Counts the number of function arguments that have no default value
    """
    return sum(1 if p.default is inspect.Parameter.empty else 0
               for p in s.parameters.values())


def has_timer_hook(func):
    return hasattr(func, 'timer_hook') and func.timer_hook


def enable_timer_hook(func):
    func.timer_hook = True
    return func
