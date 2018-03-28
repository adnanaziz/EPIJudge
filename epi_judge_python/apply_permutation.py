def apply_permutation(perm, A):
    # Implement this placeholder.
    return


def apply_permutation_wrapper(perm, A):
    apply_permutation(perm, A)
    return A


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("apply_permutation.tsv",
                                       apply_permutation_wrapper))
