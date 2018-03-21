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
    exit(
        generic_test.generic_test_main('rook_attack.tsv', rook_attack_wrapper))
