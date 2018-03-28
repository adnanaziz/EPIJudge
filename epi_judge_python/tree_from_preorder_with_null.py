import functools
from sys import exit

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook


def reconstruct_preorder(preorder):
    # Implement this placeholder.
    return None


@enable_executor_hook
def reconstruct_preorder_wrapper(executor, data):
    data = [None if x == 'null' else int(x) for x in data]
    return executor.run(functools.partial(reconstruct_preorder, data))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('tree_from_preorder_with_null.tsv',
                                       reconstruct_preorder_wrapper))
