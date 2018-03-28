from sys import exit

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test, test_utils


def is_binary_tree_bst(tree, low_range=float('-inf'), high_range=float('inf')):
    # Implement this placeholder.
    return True


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('is_tree_a_bst.tsv',
                                       is_binary_tree_bst))
