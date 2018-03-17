def rook_attack(A):
    # Implement this placeholder.
    return


def rook_attack_wrapper(A):
    a_copy = copy.deepcopy(A)
    rook_attack(a_copy)
    return a_copy


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds, 'rook_attack.tsv',
                                       rook_attack_wrapper))
