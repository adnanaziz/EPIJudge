from test_framework.binary_tree_utils import must_find_node, strip_parent_link
from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def lca(tree, node0, node1):
    # Implement this placeholder.
    return None


@enable_timer_hook
def lca_wrapper(timer, tree, key1, key2):
    strip_parent_link(tree)
    timer.start()
    result = lca(tree, must_find_node(tree, key1), must_find_node(tree, key2))
    timer.stop()

    if result is None:
        raise TestFailureException("Result can't be None")
    return result.data


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('lowest_common_ancestor.tsv', lca_wrapper)
