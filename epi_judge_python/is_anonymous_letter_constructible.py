def is_letter_constructible_from_magazine(letter_text, magazine_text):
    # Implement this placeholder.
    return True


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('is_anonymous_letter_constructible.tsv',
                                       is_letter_constructible_from_magazine))
