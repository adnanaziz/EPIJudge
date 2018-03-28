import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'smallest_subarray_covering_all_values.tsv',
            find_smallest_sequentially_covering_subset_wrapper))
