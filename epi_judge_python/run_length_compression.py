from test_framework import generic_test
from test_framework.test_failure import TestFailure


def decoding(s: str) -> str:
    # TODO - you fill in here.
    return ''


def encoding(s: str) -> str:
    # TODO - you fill in here.
    return ''


def rle_tester(encoded, decoded):
    if decoding(encoded) != decoded:
        raise TestFailure('Decoding failed')
    if encoding(decoded) != encoded:
        raise TestFailure('Encoding failed')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('run_length_compression.py',
                                       'run_length_compression.tsv',
                                       rle_tester))
