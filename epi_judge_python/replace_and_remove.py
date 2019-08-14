import functools

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook


def replace_and_remove(size, s):
    a_count = 0
    write_idx = 0
    for i in range(size):
        if s[i] != 'b':
            s[write_idx] = s[i]
            write_idx += 1
        if s[i] == 'a':
            a_count += 1
    final_size = write_idx + a_count
    cur_idx = write_idx - 1
    write_idx = write_idx + a_count - 1
    while cur_idx >= 0:
        if s[cur_idx] != 'a':
            s[write_idx] = s[cur_idx]
            write_idx -= 1
        else:
            s[write_idx-1], s[write_idx] = 'd', 'd'
            write_idx -= 2
        cur_idx -= 1

    return final_size


@enable_executor_hook
def replace_and_remove_wrapper(executor, size, s):
    res_size = executor.run(functools.partial(replace_and_remove, size, s))
    return s[:res_size]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("replace_and_remove.py",
                                       'replace_and_remove.tsv',
                                       replace_and_remove_wrapper))
