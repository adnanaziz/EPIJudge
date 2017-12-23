from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def bst_to_doubly_linked_list(tree):
    # Implement this placeholder.
    return None


@enable_timer_hook
def bst_to_doubly_linked_list_wrapper(timer, tree):
    timer.start()
    l = bst_to_doubly_linked_list(tree)
    timer.stop()
    if l and l.left is not None:
        raise TestFailureException(
            'Function must return the head of the list. Left link must be None'
        )

    v = []
    while l:
        v.append(l.data)
        if l.right and l.right.left is not l:
            raise TestFailureException('List is ill-formed')
        l = l.right

    return v


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'bst_to_sorted_list.tsv', bst_to_doubly_linked_list_wrapper)
