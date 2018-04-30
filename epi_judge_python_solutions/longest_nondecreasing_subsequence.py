def longest_nondecreasing_subsequence_length(A):
    # max_length[i] holds the length of the longest nondecreasing subsequence
    # of A[:i + 1].
    max_length = [1] * len(A)
    for i in range(1, len(A)):
        max_length[i] = 1 + max((max_length[j] for j in range(i)
                                if A[i] >= A[j]), default=0)
    return max(max_length)


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'longest_nondecreasing_subsequence.tsv',
            longest_nondecreasing_subsequence_length))
