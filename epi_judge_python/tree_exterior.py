import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def exterior_binary_tree(tree):
    # Implement this placeholder.
    return []


def create_output_list(L):
    if any(l is None for l in L):
        raise TestFailure('Resulting list contains None')
    return [l.data for l in L]


@enable_executor_hook
def create_output_list_wrapper(executor, tree):
    tree = executor.run(functools.partial(exterior_binary_tree, tree))

    return create_output_list(tree)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('tree_exterior.tsv',
                                       create_output_list_wrapper))
