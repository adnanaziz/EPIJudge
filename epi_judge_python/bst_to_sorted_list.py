import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def bst_to_doubly_linked_list(tree):
    # Implement this placeholder.
    return None


@enable_executor_hook
def bst_to_doubly_linked_list_wrapper(executor, tree):
    l = executor.run(functools.partial(bst_to_doubly_linked_list, tree))
    if l and l.left is not None:
        raise TestFailure(
            'Function must return the head of the list. Left link must be None'
        )

    v = []
    while l:
        v.append(l.data)
        if l.right and l.right.left is not l:
            raise TestFailure('List is ill-formed')
        l = l.right

    return v


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('bst_to_sorted_list.tsv',
                                       bst_to_doubly_linked_list_wrapper))
