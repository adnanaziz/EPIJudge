import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def exterior_binary_tree(tree):
    def is_leaf(node):
        return not node.left and not node.right

    # Computes the nodes from the root to the leftmost leaf followed by all
    # the leaves in subtree.
    def left_boundary_and_leaves(subtree, is_boundary):
        if not subtree:
            return []
        return (([subtree] if is_boundary or is_leaf(subtree) else []) +
                left_boundary_and_leaves(subtree.left, is_boundary) +
                left_boundary_and_leaves(subtree.right, is_boundary
                                         and not subtree.left))

    # Computes the leaves in left-to-right order followed by the rightmost
    # leaf to the root path in subtree.
    def right_boundary_and_leaves(subtree, is_boundary):
        if not subtree:
            return []
        return (right_boundary_and_leaves(subtree.left, is_boundary
                                          and not subtree.right) +
                right_boundary_and_leaves(subtree.right, is_boundary) +
                ([subtree] if is_boundary or is_leaf(subtree) else []))

    return ([tree] + left_boundary_and_leaves(tree.left, is_boundary=True) +
            right_boundary_and_leaves(tree.right, is_boundary=True)
            if tree else [])


def create_output_list(L):
    if any(l is None for l in L):
        raise TestFailure('Resulting list contains None')
    return [l.data for l in L]


@enable_executor_hook
def create_output_list_wrapper(executor, tree):
    tree = executor.run(functools.partial(exterior_binary_tree, tree))

    return create_output_list(tree)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('tree_exterior.tsv',
                                       create_output_list_wrapper))
