from typing import List

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test


def postorder_traversal(tree: BinaryTreeNode) -> List[int]:

    result = []

    in_process = [(tree, False)]
    while in_process:
        node, subtrees_traversed = in_process.pop()
        if node:
            if subtrees_traversed:
                result.append(node.data)
            else:
                in_process.append((node, True))
                in_process.append((node.right, False))
                in_process.append((node.left, False))
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('tree_postorder.py',
                                       'tree_postorder.tsv',
                                       postorder_traversal))
