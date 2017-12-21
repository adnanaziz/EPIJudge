from binary_tree_node import BinaryTreeNode
from test_framework.test_utils import enable_timer_hook


def reconstruct_preorder(preorder):
    # Implement this placeholder.
    return None


@enable_timer_hook
def reconstruct_preorder_wrapper(timer, data):
    data = [None if x == 'null' else int(x) for x in data]
    timer.start()
    result = reconstruct_preorder(data)
    timer.stop()
    return result


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'tree_from_preorder_with_null.tsv', reconstruct_preorder_wrapper)
