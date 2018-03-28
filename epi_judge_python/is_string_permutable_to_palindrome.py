def can_form_palindrome(s):
    # Implement this placeholder.
    return True


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'is_string_permutable_to_palindrome.tsv', can_form_palindrome))
