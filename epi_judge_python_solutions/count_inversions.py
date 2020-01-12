from typing import List

from test_framework import generic_test


def count_inversions(A: List[int]) -> int:

    # Return the number of inversions in A[start:finish].
    def count_subarray_inversions(start, finish):
        # Merge two sorted subarrays A[start:mid] and A[mid:finish] into
        # A[start:finish] and return the number of inversions across A[start:mid]
        # and A[mid:finish].
        def merge_sort_and_count_inversions_across_subarrays(
                start, mid, finish):
            sorted_A = []
            left_start, right_start, inversion_count = start, mid, 0

            while left_start < mid and right_start < finish:
                if A[left_start] <= A[right_start]:
                    sorted_A.append(A[left_start])
                    left_start += 1
                else:
                    # A[left_start:mid] are the inversions of A[right_start].
                    inversion_count += mid - left_start
                    sorted_A.append(A[right_start])
                    right_start += 1

            # Updates A with sorted_A.
            A[start:
              finish] = sorted_A + A[left_start:mid] + A[right_start:finish]
            return inversion_count

        if finish - start <= 1:
            return 0
        mid = (start + finish) // 2
        return (count_subarray_inversions(start, mid) +
                count_subarray_inversions(mid, finish) +
                merge_sort_and_count_inversions_across_subarrays(
                    start, mid, finish))

    return count_subarray_inversions(0, len(A))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('count_inversions.py',
                                       'count_inversions.tsv',
                                       count_inversions))
