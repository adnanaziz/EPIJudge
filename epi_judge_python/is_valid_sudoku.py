# Check if a partially filled matrix has any conflicts.
def is_valid_sudoku(partial_assignment):
    # Implement this placeholder.
    return True


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("is_valid_sudoku.tsv", is_valid_sudoku))
