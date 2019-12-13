import functools
from typing import List, Optional

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook


def generate_all_binary_trees(num_nodes: int
                              ) -> List[Optional[BinaryTreeNode]]:

    if num_nodes == 0:  # Empty tree, add as a None.
        return [None]

    result: List[Optional[BinaryTreeNode]] = []
    for num_left_tree_nodes in range(num_nodes):
        num_right_tree_nodes = num_nodes - 1 - num_left_tree_nodes
        left_subtrees = generate_all_binary_trees(num_left_tree_nodes)
        right_subtrees = generate_all_binary_trees(num_right_tree_nodes)
        # Generates all combinations of left_subtrees and right_subtrees.
        result += [
            BinaryTreeNode(0, left, right) for left in left_subtrees
            for right in right_subtrees
        ]
    return result


def generate_all_binary_trees_pythonic(num_nodes):
    return [
        BinaryTreeNode(0, left, right)
        for num_left_tree_nodes in range(num_nodes)
        for left in generate_all_binary_trees(num_left_tree_nodes)
        for right in generate_all_binary_trees(num_nodes - 1 -
                                               num_left_tree_nodes)
    ] or [None]


def serialize_structure(tree):
    result = []
    q = [tree]
    while q:
        a = q.pop(0)
        result.append(0 if not a else 1)
        if a:
            q.append(a.left)
            q.append(a.right)
    return result


@enable_executor_hook
def generate_all_binary_trees_wrapper(executor, num_nodes):
    result = executor.run(
        functools.partial(generate_all_binary_trees, num_nodes))

    return sorted(map(serialize_structure, result))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('enumerate_trees.py',
                                       'enumerate_trees.tsv',
                                       generate_all_binary_trees_wrapper))
