def k_largest_in_binary_heap(A, k):
    # Implement this placeholder.
    return []


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        "k_largest_in_heap.tsv",
        k_largest_in_binary_heap,
        comparator=test_utils.unordered_compare)
