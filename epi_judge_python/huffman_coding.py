import collections
import functools
from typing import List

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook

CharWithFrequency = collections.namedtuple('CharWithFrequency', ('c', 'freq'))


def huffman_encoding(symbols: List[CharWithFrequency]) -> float:
    # TODO - you fill in here.
    return 0.0


@enable_executor_hook
def huffman_encoding_wrapper(executor, symbols):
    if any(len(x[0]) != 1 for x in symbols):
        raise RuntimeError('CharWithFrequency parser: string length is not 1')

    symbols = [CharWithFrequency(c[0], freq) for (c, freq) in symbols]
    return executor.run(functools.partial(huffman_encoding, symbols))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('huffman_coding.py',
                                       'huffman_coding.tsv',
                                       huffman_encoding_wrapper))
