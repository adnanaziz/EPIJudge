from test_framework.test_utils import enable_timer_hook

from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'subsequence_cover.tsv',
        find_smallest_sequentially_covering_subset_wrapper)
