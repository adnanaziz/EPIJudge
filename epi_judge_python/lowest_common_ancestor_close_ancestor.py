from test_framework.binary_tree_utils import must_find_node
from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def lca(node0, node1):
    # Implement this placeholder.
    return None


@enable_timer_hook
def lca_wrapper(timer, tree, node0, node1):
    timer.start()
    result = lca(must_find_node(tree, node0), must_find_node(tree, node1))
    timer.stop()

    if result is None:
        raise TestFailureException("Result can't be None")
    return result.data


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('lowest_common_ancestor.tsv',
                                              lca_wrapper)
