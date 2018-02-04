from test_framework.test_utils import enable_timer_hook
from test_framework.binary_tree_utils import must_find_node


def find_successor(node):
    # Implement this placeholder.
    return None


@enable_timer_hook
def find_successor_wrapper(timer, tree, node_idx):
    node = must_find_node(tree, node_idx)

    timer.start()
    result = find_successor(node)
    timer.stop()

    return result.data if result else -1


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('successor_in_tree.tsv',
                                   find_successor_wrapper)
