def permutations(A):
    # Implement this placeholder.
    return []


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('permutations.tsv', permutations,
                                       test_utils.unordered_compare))
