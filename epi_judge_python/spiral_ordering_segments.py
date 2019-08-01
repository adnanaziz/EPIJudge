from test_framework import generic_test


def matrix_in_spiral_order(square_matrix):
    if len(square_matrix) == 0:
        return []
    elif len(square_matrix) == 1 and len(square_matrix[0]) == 1:
        return square_matrix[0]

    outter = square_matrix[0][:-1] +\
             [r[-1] for r in square_matrix[:-1]] +\
             list(reversed(square_matrix[-1][1:])) +\
             [r[0] for r in list(reversed(square_matrix[1:]))]
    inner_matrix = [r[1:-1] for r in square_matrix[1:-1]]

    return outter + matrix_in_spiral_order(inner_matrix)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("spiral_ordering_segments.py",
                                       "spiral_ordering_segments.tsv",
                                       matrix_in_spiral_order))
