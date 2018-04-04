def has_two_sum(A, t):
    i, j = 0, len(A) - 1

    while i <= j:
        if A[i] + A[j] == t:
            return True
        elif A[i] + A[j] < t:
            i += 1
        else:  # A[i] + A[j] > t.
            j -= 1
    return False


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(generic_test.generic_test_main('two_sum.tsv', has_two_sum))
