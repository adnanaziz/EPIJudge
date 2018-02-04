from bst_node import BstNode
from test_framework.binary_tree_utils import binary_tree_height, generate_inorder
from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def build_min_height_bst_from_sorted_array(A):
    # Implement this placeholder.
    return None


@enable_timer_hook
def build_min_height_bst_from_sorted_array_wrapper(timer, A):
    timer.start()
    result = build_min_height_bst_from_sorted_array(A)
    timer.stop()

    if generate_inorder(result) != A:
        raise TestFailureException("Result binary tree mismatches input array")
    return binary_tree_height(result)


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        'bst_from_sorted_array.tsv',
        build_min_height_bst_from_sorted_array_wrapper)
