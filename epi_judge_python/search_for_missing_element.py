import collections

DuplicateAndMissing = collections.namedtuple('DuplicateAndMissing',
                                             ('duplicate', 'missing'))


def find_duplicate_missing(A):
    # Implement this placeholder.
    return DuplicateAndMissing(0, 0)


def res_printer(expected, result):
    def fmt(x):
        return 'duplicate: {}, missing: {}'.format(x[0], x[1]) if x else None

    return fmt(expected), fmt(result)


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        'find_missing_and_duplicate.tsv',
        find_duplicate_missing,
        res_printer=res_printer)
