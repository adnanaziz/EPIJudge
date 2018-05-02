from test_framework import generic_test


def is_binary_tree_bst(tree, low_range=float('-inf'), high_range=float('inf')):
    # TODO - you fill in here.
    return True


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("is_tree_a_bst.py", 'is_tree_a_bst.tsv',
                                       is_binary_tree_bst))
