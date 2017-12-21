from bst_node import BSTNode


def find_first_greater_than_k(tree, k):
    # Implement this placeholder.
    return None


def find_first_greater_than_k_wrapper(tree, k):
    result = find_first_greater_than_k(tree, k)
    return result.data if result else -1


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'search_first_greater_value_in_bst.tsv',
        find_first_greater_than_k_wrapper)
