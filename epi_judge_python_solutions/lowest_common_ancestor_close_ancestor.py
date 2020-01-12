import functools
from typing import Optional, Set

from binary_tree_with_parent_prototype import BinaryTreeNode
from test_framework import generic_test
from test_framework.binary_tree_utils import must_find_node
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def lca(node0: BinaryTreeNode,
        node1: BinaryTreeNode) -> Optional[BinaryTreeNode]:

    iter0, iter1 = node0, node1
    nodes_on_path_to_root: Set[BinaryTreeNode] = set()
    while iter0 or iter1:
        # Ascend tree in tandem for these two nodes.
        if iter0:
            if iter0 in nodes_on_path_to_root:
                return iter0
            nodes_on_path_to_root.add(iter0)
            iter0 = iter0.parent
        if iter1:
            if iter1 in nodes_on_path_to_root:
                return iter1
            nodes_on_path_to_root.add(iter1)
            iter1 = iter1.parent
    raise ValueError('node0 and node1 are not in the same tree')


@enable_executor_hook
def lca_wrapper(executor, tree, node0, node1):
    result = executor.run(
        functools.partial(lca, must_find_node(tree, node0),
                          must_find_node(tree, node1)))

    if result is None:
        raise TestFailure('Result can\'t be None')
    return result.data


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'lowest_common_ancestor_close_ancestor.py',
            'lowest_common_ancestor.tsv', lca_wrapper))
