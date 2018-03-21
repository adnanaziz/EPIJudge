import collections
import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook

CharWithFrequency = collections.namedtuple('CharWithFrequency', ('c', 'freq'))


def huffman_encoding(symbols):
    # Implement this placeholder.
    return 0.0


@enable_executor_hook
def huffman_encoding_wrapper(executor, symbols):
    if any(len(x[0]) != 1 for x in symbols):
        raise RuntimeError('CharWithFrequency parser: string length is not 1')

    symbols = [CharWithFrequency(c[0], freq) for (c, freq) in symbols]
    return executor.run(functools.partial(huffman_encoding, symbols))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('huffman_coding.tsv',
                                       huffman_encoding_wrapper))
