import functools

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook


# Assume s is a string encoded as bytearray.
def reverse_words(s):

    # First, reverse the whole string.
    s.reverse()

    def reverse_range(s, start, finish):
        while start < finish:
            s[start], s[finish] = s[finish], s[start]
            start, finish = start + 1, finish - 1

    start = 0
    while True:
        finish = s.find(b' ', start)
        if finish < 0:
            break
        # Reverses each word in the string.
        reverse_range(s, start, finish - 1)
        start = finish + 1
    # Reverses the last word.
    reverse_range(s, start, len(s) - 1)


# Pythonic solution, doesn't reverse in-place, may be used with strings
def reverse_words_pythonic(s):
    return ' '.join(reversed(s.split(' ')))


@enable_executor_hook
def reverse_words_wrapper(executor, s):
    s_copy = bytearray()
    s_copy.extend(map(ord, s))

    executor.run(functools.partial(reverse_words, s_copy))

    return s_copy.decode("utf-8")


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("reverse_words.py", 'reverse_words.tsv',
                                       reverse_words_wrapper))
