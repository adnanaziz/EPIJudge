from typing import List

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test


def inorder_traversal(tree: BinaryTreeNode) -> List[int]:

    result = []

    in_process = [(tree, False)]
    while in_process:
        node, left_subtree_traversed = in_process.pop()
        if node:
            if left_subtree_traversed:
                result.append(node.data)
            else:
                in_process.append((node.right, False))
                in_process.append((node, True))
                in_process.append((node.left, False))
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('tree_inorder.py', 'tree_inorder.tsv',
                                       inorder_traversal))
