import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook


def replace_and_remove(size, s):
    # Implement this placeholder.
    return 0


@enable_executor_hook
def replace_and_remove_wrapper(executor, size, s):
    res_size = executor.run(functools.partial(replace_and_remove, size, s))
    return s[:res_size]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('replace_and_remove.tsv',
                                       replace_and_remove_wrapper))
