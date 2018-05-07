from test_framework import generic_test


def closest_int_same_bit_count(x):

    NUM_UNSIGNED_BITS = 64
    for i in range(NUM_UNSIGNED_BITS - 1):
        if (x >> i) & 1 != (x >> (i + 1)) & 1:
            x ^= (1 << i) | (1 << (i + 1))  # Swaps bit-i and bit-(i + 1).
            return x

    # Raise error if all bits of x are 0 or 1.
    raise ValueError('All bits are 0 or 1')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("closest_int_same_weight.py",
                                       "closest_int_same_weight.tsv",
                                       closest_int_same_bit_count))
