from test_framework import generic_test


def find_element_appears_once(A):

    counts = [0] * 32
    for x in A:
        for i in range(32):
            counts[i] += x & 1
            x >>= 1

    def handle_negative(n):
        return n if n < 2**31 else n - 2**32

    # Any result greater than or equal to 2**31 must correspond to an negative
    # value.
    return handle_negative(sum(1 << i for i, c in enumerate(counts) if c % 3))


def find_element_appears_once_alternative(A):
    # ones denotes whether a bit-position has been set once (modulo 3) so far.
    # twos denotes whether a bit-position has been set twice (modulo 3) so far.
    ones = twos = 0
    for i in A:
        # After reading A[i], bit-position j has a count of 1 modulo 3
        # if it had a count of 1 modulo 3 (the j-th bit in ones is set)
        # and the j-th bit in A[i] is 0 or the count was 0 modulo 3
        # (the j-th bit is not set in ones and in not set in twos) and
        # the j-th bit in A[i] is 1.
        next_ones = (~i & ones) | (i & ~ones & ~twos)

        # After reading A[i], bit-position j has a count of 2 modulo 3
        # if it had a count of 2 modulo 3 (the j-th bit in twos is set)
        # and the j-th bit in A[i] is a 0 or the count was 1 modulo 3
        # (the j-th bit is set in ones) and the j-th bit in A[i] is a 1.
        next_twos = (~i & twos) | (i & ones)

        ones = next_ones
        twos = next_twos

    # Since ones denotes bit-positions which have been set once (modulo 3),
    # it is the element which appears only once.
    return ones


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("element_appearing_once.py",
                                       'element_appearing_once.tsv',
                                       find_element_appears_once))
