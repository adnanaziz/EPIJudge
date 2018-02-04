import collections

MinMax = collections.namedtuple('MinMax', ('smallest', 'largest'))


def find_min_max(A):
    # Implement this placeholder.
    return MinMax(0, 0)


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        'search_for_min_max_in_array.tsv',
        find_min_max,
        res_printer=res_printer)
