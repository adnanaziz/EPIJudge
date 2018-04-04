from sys import exit

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test, test_utils


def inorder_traversal(tree):
    s, result = [], []

    while s or tree:
        if tree:
            s.append(tree)
            # Going left.
            tree = tree.left
        else:
            # Going up.
            tree = s.pop()
            result.append(tree.data)
            # Going right.
            tree = tree.right
    return result


if __name__ == '__main__':
    exit(generic_test.generic_test_main('tree_inorder.tsv', inorder_traversal))
