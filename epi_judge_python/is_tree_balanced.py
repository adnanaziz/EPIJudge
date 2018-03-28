from sys import exit

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test, test_utils


def is_balanced_binary_tree(tree):
    # Implement this placeholder.
    return True


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('is_tree_balanced.tsv',
                                       is_balanced_binary_tree))
