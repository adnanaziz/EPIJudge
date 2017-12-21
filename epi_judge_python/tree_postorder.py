from binary_tree_node import BinaryTreeNode


# We use stack and previous node pointer to simulate postorder traversal.
def postorder_traversal(tree):
    # Implement this placeholder.
    return []


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('tree_postorder.tsv',
                                              postorder_traversal)
