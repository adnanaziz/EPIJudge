from test_framework import generic_test

from binary_tree_node import BinaryTreeNode


def binary_tree_depth_order(tree: BinaryTreeNode):
    result = []
    if tree is None:
        return result
    q1 = [tree]
    while q1:
        result.append([node.data for node in q1])
        q1 = [child for node in q1 for child in (node.left, node.right) if child is not None]
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("tree_level_order.py",
                                       "tree_level_order.tsv",
                                       binary_tree_depth_order))
