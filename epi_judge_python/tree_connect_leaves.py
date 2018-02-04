from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def create_list_of_leaves(tree):
    # Implement this placeholder.
    return []


@enable_timer_hook
def create_list_of_leaves_wrapper(timer, tree):
    timer.start()
    result = create_list_of_leaves(tree)
    timer.stop()

    if any(x is None for x in result):
        raise TestFailureException("Result list can't contain None")
    return [x.data for x in result]


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main("tree_connect_leaves.tsv",
                                   create_list_of_leaves_wrapper)
