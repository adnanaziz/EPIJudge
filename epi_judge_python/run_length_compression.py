from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_failure import TestFailure


def decoding(s):
    # Implement this placeholder.
    return ''


def encoding(s):
    # Implement this placeholder.
    return ''


def rle_tester(encoded, decoded):
    if decoding(encoded) != decoded:
        raise TestFailure('Decoding failed')
    if encoding(decoded) != encoded:
        raise TestFailure('Encoding failed')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('run_length_compression.tsv',
                                       rle_tester))
