from test_framework import generic_test


def matrix_search(A, x):

    row, col = 0, len(A[0]) - 1  # Start from the top-right corner.
    # Keeps searching while there are unclassified rows and columns.
    while row < len(A) and col >= 0:
        if A[row][col] == x:
            return True
        elif A[row][col] < x:
            row += 1  # Eliminate this row.
        else:  # A[row][col] > x.
            col -= 1  # Eliminate this column.
    return False


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("search_row_col_sorted_matrix.py",
                                       'search_row_col_sorted_matrix.tsv',
                                       matrix_search))
