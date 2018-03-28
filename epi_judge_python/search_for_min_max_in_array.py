import collections
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_failure import PropertyName

MinMax = collections.namedtuple('MinMax', ('smallest', 'largest'))


def find_min_max(A):
    # Implement this placeholder.
    return MinMax(0, 0)


def res_printer(prop, value):
    def fmt(x):
        return 'min: {}, max: {}'.format(x[0], x[1]) if x else None

    if prop in (PropertyName.EXPECTED, PropertyName.RESULT):
        return fmt(value)
    else:
        return value


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'search_for_min_max_in_array.tsv',
            find_min_max,
            res_printer=res_printer))
