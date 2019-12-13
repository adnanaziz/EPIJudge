import collections
import functools
import heapq
from typing import Dict, List

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook

CharWithFrequency = collections.namedtuple('CharWithFrequency', ('c', 'freq'))


def huffman_encoding(symbols: List[CharWithFrequency]) -> float:
    class BinaryTree:
        def __init__(self, aggregate_freq, s, left=None, right=None):
            self.aggregate_freq = aggregate_freq
            self.s = s
            self.left, self.right = left, right

        def __lt__(self, other):
            return self.aggregate_freq <= other.aggregate_freq

        def symbols(self):
            return self.left.symbols() + self.right.symbols(
            ) if self.s is None else self.s.c

        def __repr__(self):
            return '%s <- %r(%g) -> %s' % (self.left and self.left.symbols(),
                                           self.symbols(), self.aggregate_freq,
                                           self.right and self.right.symbols())

    # Initially assigns each symbol into candidates.
    candidates = [BinaryTree(s.freq, s) for s in symbols]
    heapq.heapify(candidates)

    # Keeps combining two nodes until there is one node left.
    while len(candidates) > 1:
        left, right = heapq.heappop(candidates), heapq.heappop(candidates)
        heapq.heappush(
            candidates,
            BinaryTree(left.aggregate_freq + right.aggregate_freq, None, left,
                       right))

    def assign_huffman_code(tree, code):
        if tree:
            if tree.s:
                # This node is a leaf.
                char_to_encoding[tree.s.c] = ''.join(code)
            else:  # Non-leaf node.
                code.append('0')
                assign_huffman_code(tree.left, code)
                code[-1] = '1'
                assign_huffman_code(tree.right, code)
                del code[-1]

    char_to_encoding: Dict[str, str] = {}
    # Traverses the binary tree, assigning codes to nodes.
    assign_huffman_code(candidates[0], [])
    return sum(len(char_to_encoding[s.c]) * s.freq / 100 for s in symbols)


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
