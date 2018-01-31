from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None, size=None):
        self.data = data
        self.left = left
        self.right = right
        self.size = size


def find_kth_node_binary_tree(tree, k):
    # Implement this placeholder.
    return None


@enable_timer_hook
def find_kth_node_binary_tree_wrapper(timer, tree, k):
    def init_size(node):
        if not node:
            return 0
        node.size = 1 + init_size(node.left) + init_size(node.right)
        return node.size

    init_size(tree)

    timer.start()
    result = find_kth_node_binary_tree(tree, k)
    timer.stop()

    if not result:
        raise TestFailureException("Result can't be None")
    return result.data


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        "kth_node_in_tree.tsv", find_kth_node_binary_tree_wrapper)
