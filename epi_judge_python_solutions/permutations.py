from next_permutation import next_permutation
from test_framework import generic_test, test_utils


def permutations(A):

    result = []
    while True:
        result.append(A.copy())
        A = next_permutation(A)
        if not A:
            break
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("permutations.py", 'permutations.tsv',
                                       permutations,
                                       test_utils.unordered_compare))
