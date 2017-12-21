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


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('run_length_compression.tsv',
                                              rle_tester)
