def apply_permutation(perm, A):
    # Implement this placeholder.
    return


def apply_permutation_wrapper(perm, A):
    apply_permutation(perm, A)
    return A


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main("apply_permutation.tsv",
                                              apply_permutation_wrapper)
