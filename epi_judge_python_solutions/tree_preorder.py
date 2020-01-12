from typing import List

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test


def preorder_traversal(tree: BinaryTreeNode) -> List[int]:

    result = []

    in_process = [(tree, False)]
    while in_process:
        node, node_processed = in_process.pop()
        if node:
            if node_processed:
                result.append(node.data)
            else:
                in_process.append((node.right, False))
                in_process.append((node.left, False))
                in_process.append((node, True))
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('tree_preorder.py', 'tree_preorder.tsv',
                                       preorder_traversal))
