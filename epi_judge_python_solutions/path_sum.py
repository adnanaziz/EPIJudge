def has_path_sum(tree, remaining_weight):
    if not tree:
        return False
    if not tree.left and not tree.right:  # Leaf.
        return remaining_weight == tree.data
    # Non-leaf.
    return (has_path_sum(tree.left, remaining_weight - tree.data)
            or has_path_sum(tree.right, remaining_weight - tree.data))


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(generic_test.generic_test_main('path_sum.tsv', has_path_sum))
