import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook


# Assume s is a string encoded as bytearray.
def reverse_words(s):
    # Implement this placeholder.
    return


@enable_executor_hook
def reverse_words_wrapper(executor, s):
    s_copy = bytearray()
    s_copy.extend(map(ord, s))

    executor.run(functools.partial(reverse_words, s_copy))

    return s_copy.decode("utf-8")


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('reverse_words.tsv',
                                       reverse_words_wrapper))
