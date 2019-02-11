from test_framework import generic_test


def roman_to_integer2(s):
    MAP = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
    n = len(s)
    ans = 0
    for i in range(1, n):
        if MAP[s[i - 1]] < MAP[s[i]]:
            ans += -MAP[s[i - 1]]
        else:
            ans += MAP[s[i - 1]]
    ans += MAP[s[n - 1]]
    return ans

from functools import reduce
def roman_to_integer(s):
    T = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
    n = len(s)
    ans = reduce(lambda accu, i:
        accu + (0 - T[s[i]] if T[s[i]] < T[s[i + 1]] else T[s[i]]), 
        range(n - 1), 
        T[s[-1]]
    )
    return ans


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "roman_to_integer.py", 'roman_to_integer.tsv', roman_to_integer))
