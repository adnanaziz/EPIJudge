from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def exterior_binary_tree(tree):
    # Implement this placeholder.
    return []


def create_output_list(L):
    if any(l is None for l in L):
        raise TestFailureException('Resulting list contains None')
    return [l.data for l in L]


@enable_timer_hook
def create_output_list_wrapper(timer, tree):
    timer.start()
    tree = exterior_binary_tree(tree)
    timer.stop()

    return create_output_list(tree)


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('tree_exterior.tsv',
                                   create_output_list_wrapper)
