import collections

from test_framework.test_utils import enable_timer_hook

CharWithFrequency = collections.namedtuple('CharWithFrequency', ('c', 'freq'))


def huffman_encoding(symbols):
    # Implement this placeholder.
    return 0.0


@enable_timer_hook
def huffman_encoding_wrapper(timer, symbols):
    if any(len(x[0]) != 1 for x in symbols):
        raise RuntimeError('CharWithFrequency parser: string length is not 1')

    symbols = [CharWithFrequency(c[0], freq) for (c, freq) in symbols]
    timer.start()
    return huffman_encoding(symbols)


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('huffman_coding.tsv',
                                              huffman_encoding_wrapper)
