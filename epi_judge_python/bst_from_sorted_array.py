from bst_node import BSTNode
from test_framework.binary_tree_utils import equal_binary_trees


def build_min_height_bst_from_sorted_array(A):
    # Implement this placeholder.
    return None


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'bst_from_sorted_array.tsv', build_min_height_bst_from_sorted_array,
        equal_binary_trees)
