from test_framework import generic_test


def swap_bits(x, i, j):
    m_i = 1 << i
    m_j = 1 << j
    v_i = x & m_i
    v_j = x & m_j

    if v_i and v_j == 0:
        x = x ^ m_i
        x |= m_j
    elif not v_i and v_j:
        x |= m_i
        x ^= m_j
    return x


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('swap_bits.py', 'swap_bits.tsv',
                                       swap_bits))
