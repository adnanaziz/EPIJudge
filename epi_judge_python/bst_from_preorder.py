from sys import exit

from bst_node import BstNode
from test_framework import generic_test, test_utils


def rebuild_bst_from_preorder(preorder_sequence):
    # Implement this placeholder.
    return None


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('bst_from_preorder.tsv',
                                       rebuild_bst_from_preorder))
