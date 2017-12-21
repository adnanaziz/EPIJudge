from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook

from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        "kth_node_in_tree.tsv", find_kth_node_binary_tree_wrapper)
