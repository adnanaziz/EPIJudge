def sort_approximately_sorted_array(sequence, k):
    # Implement this placeholder.
    return []


def sort_approximately_sorted_array_wrapper(sequence, k):
    return sort_approximately_sorted_array(iter(sequence), k)


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'sort_almost_sorted_array.tsv',
        sort_approximately_sorted_array_wrapper)
