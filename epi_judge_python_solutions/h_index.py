from sys import exit

from test_data_generators.test_explanation import TestExplanation
from test_framework import generic_test, test_utils

explanation = TestExplanation()


def h_index(citations):
    citations.sort()
    n = len(citations)
    for i, c in enumerate(citations):
        if c >= n - i:
            explanation.citations = [c for c in citations if c >= n - i]
            return n - i
    explanation.citations = None
    return 0


if __name__ == '__main__':
    exit(generic_test.generic_test_main('h_index.tsv', h_index))
