# Check if a partially filled matrix has any conflicts.
def is_valid_sudoku(partial_assignment):
    # Implement this placeholder.
    return True


from sys import exit
from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds, "is_valid_sudoku.tsv",
                                       is_valid_sudoku))
