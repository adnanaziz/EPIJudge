def is_palindrome_number(x):
    # Implement this placeholder.
    return True


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("is_number_palindromic.tsv",
                                       is_palindrome_number))
