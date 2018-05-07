import functools

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook


def reconstruct_preorder(preorder):
    def reconstruct_preorder_helper(preorder_iter):
        subtree_key = next(preorder_iter)
        if subtree_key is None:
            return None

        # Note that reconstruct_preorder_helper updates preorder_iter. So the
        # order of following two calls are critical.
        left_subtree = reconstruct_preorder_helper(preorder_iter)
        right_subtree = reconstruct_preorder_helper(preorder_iter)
        return BinaryTreeNode(subtree_key, left_subtree, right_subtree)

    return reconstruct_preorder_helper(iter(preorder))


@enable_executor_hook
def reconstruct_preorder_wrapper(executor, data):
    data = [None if x == 'null' else int(x) for x in data]
    return executor.run(functools.partial(reconstruct_preorder, data))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("tree_from_preorder_with_null.py",
                                       'tree_from_preorder_with_null.tsv',
                                       reconstruct_preorder_wrapper))
