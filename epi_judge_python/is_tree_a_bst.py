from binary_tree_node import BinaryTreeNode


def is_binary_tree_bst(tree, low_range=float('-inf'), high_range=float('inf')):
    # Implement this placeholder.
    return True


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('is_tree_a_bst.tsv',
                                              is_binary_tree_bst)
