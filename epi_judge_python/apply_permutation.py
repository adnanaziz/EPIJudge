def apply_permutation(perm, A):
    # Implement this placeholder.
    return


def apply_permutation_wrapper(perm, A):
    apply_permutation(perm, A)
    return A


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds,
                                       "apply_permutation.tsv",
                                       apply_permutation_wrapper))
