import bisect

from test_framework import generic_test


def search_first_of_k(A, k):
    lo, hi = 0, len(A)
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if k <= A[mid]:
            hi = mid
        else:
            lo = mid + 1
    return lo if lo < len(A) and A[lo] == k else -1


# Pythonic solution
def search_first_of_k_pythonic(A, k):
    i = bisect.bisect_left(A, k)
    return i if i < len(A) and A[i] == k else -1


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "search_first_key.py", 'search_first_key.tsv', search_first_of_k))
