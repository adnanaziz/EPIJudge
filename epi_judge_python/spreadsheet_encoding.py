def ss_decode_col_id(col):
    # Implement this placeholder.
    return 0


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('spreadsheet_encoding.tsv',
                                       ss_decode_col_id))
