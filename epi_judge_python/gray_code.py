import functools
from typing import List

from test_framework import generic_test
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def gray_code(num_bits: int) -> List[int]:
    # TODO - you fill in here.
    return []


@enable_executor_hook
def gray_code_wrapper(executor, num_bits):
    result = executor.run(functools.partial(gray_code, num_bits))

    expected_size = (1 << num_bits)
    if len(result) != expected_size:
        raise TestFailure('Length mismatch: expected ' + str(expected_size) +
                          ', got ' + str(len(result)))
    for i in range(1, len(result)):
        if not differ_by_1_bit(result[i - 1], result[i]):
            if result[i - 1] == result[i]:
                raise TestFailure('Two adjacent entries are equal')
            else:
                raise TestFailure(
                    'Two adjacent entries differ by more than 1 bit')

    uniq = set(result)
    if len(uniq) != len(result):
        raise TestFailure('Not all entries are distinct: found ' +
                          str(len(result) - len(uniq)) + ' duplicates')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('gray_code.py', 'gray_code.tsv',
                                       gray_code_wrapper))
