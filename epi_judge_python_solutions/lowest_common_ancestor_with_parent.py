import functools

from test_framework import generic_test
from test_framework.binary_tree_utils import must_find_node
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def lca(node0, node1):
    def get_depth(node):
        depth = 0
        while node:
            depth += 1
            node = node.parent
        return depth

    depth0, depth1 = map(get_depth, (node0, node1))
    # Makes node0 as the deeper node in order to simplify the code.
    if depth1 > depth0:
        node0, node1 = node1, node0

    # Ascends from the deeper node.
    depth_diff = abs(depth0 - depth1)
    while depth_diff:
        node0 = node0.parent
        depth_diff -= 1

    # Now ascends both nodes until we reach the LCA.
    while node0 is not node1:
        node0, node1 = node0.parent, node1.parent
    return node0


@enable_executor_hook
def lca_wrapper(executor, tree, node0, node1):
    result = executor.run(
        functools.partial(lca, must_find_node(tree, node0),
                          must_find_node(tree, node1)))

    if result is None:
        raise TestFailure("Result can't be None")
    return result.data


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("lowest_common_ancestor_with_parent.py",
                                       'lowest_common_ancestor.tsv',
                                       lca_wrapper))
