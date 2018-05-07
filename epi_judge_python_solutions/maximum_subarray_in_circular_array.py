from test_framework import generic_test


def max_subarray_sum_in_circular(A):

    # Calculates the non-circular solution.
    def find_max_subarray():
        maximum_till = maximum = 0
        for a in A:
            maximum_till = max(a, a + maximum_till)
            maximum = max(maximum, maximum_till)
        return maximum

    # Calculates the solution which is circular.
    def find_circular_max_subarray():
        def compute_running_maximum(A):
            partial_sum = A[0]
            running_maximum = [partial_sum]
            for a in A[1:]:
                partial_sum += a
                running_maximum.append(max(running_maximum[-1], partial_sum))
            return running_maximum

        # Maximum subarray sum starts at index 0 and ends at or before index i.
        maximum_begin = compute_running_maximum(A)
        # Maximum subarray sum starts at index i + 1 and ends at the last
        # element.
        maximum_end = compute_running_maximum(A[::-1])[::-1][1:] + [0]

        # Calculates the maximum subarray which is circular.
        return max(
            begin + end for begin, end in zip(maximum_begin, maximum_end))

    return max(find_max_subarray(), find_circular_max_subarray())


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "maximum_subarray_in_circular_array.py",
            'maximum_subarray_in_circular_array.tsv',
            max_subarray_sum_in_circular))
