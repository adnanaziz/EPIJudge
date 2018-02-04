from test_framework.test_utils import enable_timer_hook

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        'subsequence_cover.tsv',
        find_smallest_sequentially_covering_subset_wrapper)
