from test_framework import generic_test


def is_well_formed(s):

    left_chars, LOOKUP = [], {'(': ')', '{': '}', '[': ']'}
    for c in s:
        if c in LOOKUP:
            left_chars.append(c)
        elif not left_chars or LOOKUP[left_chars.pop()] != c:
            # Unmatched right char or mismatched chars.
            return False
    return not left_chars


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("is_valid_parenthesization.py",
                                       'is_valid_parenthesization.tsv',
                                       is_well_formed))
