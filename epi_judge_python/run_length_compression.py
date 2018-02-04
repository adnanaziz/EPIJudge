from test_framework.test_failure_exception import TestFailureException


def decoding(s):
    # Implement this placeholder.
    return ''


def encoding(s):
    # Implement this placeholder.
    return ''


def rle_tester(encoded, decoded):
    if decoding(encoded) != decoded:
        raise TestFailureException('Decoding failed')
    if encoding(decoded) != encoded:
        raise TestFailureException('Encoding failed')


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('run_length_compression.tsv', rle_tester)
