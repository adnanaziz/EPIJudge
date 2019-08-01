from test_framework import generic_test


def has_two_sum(A, t):
    # assume A is pre sorted
    i, j = 0, len(A) - 1
    while i <= j:
        if A[i] + A[j] == t:
            return True
        elif A[i] + A[j] < t:
            i += 1
        else:
            j -= 1

    return False


def has_three_sum(A, t):
    A.sort()
    for a in A:
        two_sum = t - a
        if has_two_sum(A, two_sum):
            return True

    return False


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("three_sum.py", "three_sum.tsv",
                                       has_three_sum))
