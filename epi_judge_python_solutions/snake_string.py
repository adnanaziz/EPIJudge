from test_framework import generic_test


def snake_string(s: str) -> str:

    result = [s[i] for i in range(1, len(s), 4)]
    # Outputs the second row, i.e., s[0], s[2], s[4], ...
    result.extend(s[i] for i in range(0, len(s), 2))
    # Outputs the third row, i.e., s[3], s[7], s[11], ...
    result.extend(s[i] for i in range(3, len(s), 4))
    return ''.join(result)


# Python solution uses slicing with right steps.
def snake_string_pythonic(s):
    return s[1::4] + s[::2] + s[3::4]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('snake_string.py', 'snake_string.tsv',
                                       snake_string))
