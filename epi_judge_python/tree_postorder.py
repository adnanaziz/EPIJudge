from sys import exit

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test, test_utils


# We use stack and previous node pointer to simulate postorder traversal.
def postorder_traversal(tree):
    # Implement this placeholder.
    return []


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('tree_postorder.tsv',
                                       postorder_traversal))
