def k_largest_in_binary_heap(A, k):
    # Implement this placeholder.
    return []


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        "k_largest_in_heap.tsv",
        k_largest_in_binary_heap,
        comp=test_utils.unordered_compare)
