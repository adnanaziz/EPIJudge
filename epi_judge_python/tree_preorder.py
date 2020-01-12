from typing import List

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test


def preorder_traversal(tree: BinaryTreeNode) -> List[int]:
    # TODO - you fill in here.
    return []


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('tree_preorder.py', 'tree_preorder.tsv',
                                       preorder_traversal))
