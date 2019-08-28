import math
from typing import List

import bintrees

from test_framework import generic_test

# These numbers have very interesting property, and people called it ugly numbers. It is also called quadratic integer rings.


class Number:
    def __init__(self, a, b):
        self.a, self.b = a, b
        self.val = a + b * math.sqrt(2)

    def __lt__(self, other):
        return self.val < other.val

    def __eq__(self, other):
        return self.val == other.val


def generate_first_k_a_b_sqrt2(k: int) -> List[float]:

    # Initial for 0 + 0 * sqrt(2).
    candidates = bintrees.RBTree([(Number(0, 0), None)])

    result: List[float] = []
    while len(result) < k:
        next_smallest = candidates.pop_min()[0]
        result.append(next_smallest.val)
        # Adds the next two numbers derived from next_smallest.
        candidates[Number(next_smallest.a + 1, next_smallest.b)] = None
        candidates[Number(next_smallest.a, next_smallest.b + 1)] = None
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('a_b_sqrt2.py', 'a_b_sqrt2.tsv',
                                       generate_first_k_a_b_sqrt2))
