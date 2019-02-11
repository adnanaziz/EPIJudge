from test_framework import generic_test


def next_number(s):
    n = len(s)
    cnt = 1
    ans = []
    for i in range(1, n):
        if s[i] != s[i - 1]:
            ans.append(str(cnt) + str(s[i - 1]))
            cnt = 1
        else:
            cnt += 1
    ans.append(str(cnt) + str(s[-1]))
    return "".join(ans)

def look_and_say2(n):
    s = "1"
    for _ in range(1, n):
        s = next_number(s)
    return s

# Pythonic solution,
from itertools import groupby
def look_and_say(n):
    s = "1"
    for _ in range(n - 1):
        s = "".join(
            str(len(list(g))) + k for k, g in groupby(s)
        )
    return s


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("look_and_say.py", "look_and_say.tsv",
                                       look_and_say))
