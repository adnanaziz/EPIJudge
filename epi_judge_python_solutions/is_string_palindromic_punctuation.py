from test_framework import generic_test


def is_palindrome(s: str) -> bool:

    # i moves forward, and j moves backward.
    i, j = 0, len(s) - 1
    while i < j:
        # i and j both skip non-alphanumeric characters.
        while not s[i].isalnum() and i < j:
            i += 1
        while not s[j].isalnum() and i < j:
            j -= 1
        if s[i].lower() != s[j].lower():
            return False
        i, j = i + 1, j - 1
    return True


def is_palindrome_pythonic(s):
    return all(
        a == b
        for a, b in zip(map(str.lower, filter(str.isalnum, s)),
                        map(str.lower, filter(str.isalnum, reversed(s)))))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'is_string_palindromic_punctuation.py',
            'is_string_palindromic_punctuation.tsv', is_palindrome))
