import functools

from binary_tree_node import BinaryTreeNode
from test_framework.test_utils import enable_executor_hook


def reconstruct_preorder(preorder):
    # Implement this placeholder.
    return None


@enable_executor_hook
def reconstruct_preorder_wrapper(executor, data):
    data = [None if x == 'null' else int(x) for x in data]
    return executor.run(functools.partial(reconstruct_preorder, data))


from sys import exit
from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds,
                                       'tree_from_preorder_with_null.tsv',
                                       reconstruct_preorder_wrapper))
