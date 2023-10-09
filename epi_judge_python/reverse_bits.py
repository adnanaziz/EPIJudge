from test_framework import generic_test


def reverse_bits(x: int) -> int:
    result = 0
    mask_1 = 1 << 63
    mask_2 = 1
    for i in range(64):
        if x & mask_1:
            result |= mask_2
        mask_1 >>= 1
        mask_2 <<= 1
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('reverse_bits.py', 'reverse_bits.tsv',
                                       reverse_bits))
