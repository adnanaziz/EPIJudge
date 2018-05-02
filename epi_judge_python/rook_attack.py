import copy

from test_framework import generic_test


def rook_attack(A):
    # TODO - you fill in here.
    return


def rook_attack_wrapper(A):
    a_copy = copy.deepcopy(A)
    rook_attack(a_copy)
    return a_copy


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("rook_attack.py", 'rook_attack.tsv',
                                       rook_attack_wrapper))
