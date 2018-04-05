from sys import exit

from test_data_generators.test_explanation import TestExplanation
from test_framework import generic_test, test_utils

explanation = TestExplanation()


def can_reach_end(A):
    explanation.prev = [0] + [-1] * (len(A) - 1)
    furthest_reach_so_far, last_index = 0, len(A) - 1
    i = 0
    while i <= furthest_reach_so_far and furthest_reach_so_far < last_index:
        for j in range(
                furthest_reach_so_far,
                min(max(furthest_reach_so_far, A[i] + i), last_index) + 1):
            if explanation.prev[j] == -1:
                explanation.prev[j] = i
        furthest_reach_so_far = max(furthest_reach_so_far, A[i] + i)
        i += 1
    return furthest_reach_so_far >= last_index


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("advance_by_offsets.tsv",
                                       can_reach_end))
