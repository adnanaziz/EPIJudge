def n_queens(n):
    # Implement this placeholder.
    return []


def comp(a, b):
    return sorted(a) == sorted(b)


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('n_queens.tsv', n_queens, comp)
