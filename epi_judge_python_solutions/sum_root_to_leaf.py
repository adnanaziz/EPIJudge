from binary_tree_node import BinaryTreeNode
from test_framework import generic_test


def sum_root_to_leaf(tree: BinaryTreeNode) -> int:
    def sum_root_to_leaf_helper(tree, partial_path_sum=0):
        if not tree:
            return 0

        partial_path_sum = partial_path_sum * 2 + tree.data
        if not tree.left and not tree.right:  # Leaf.
            return partial_path_sum
        # Non-leaf.
        return (sum_root_to_leaf_helper(tree.left, partial_path_sum) +
                sum_root_to_leaf_helper(tree.right, partial_path_sum))

    return sum_root_to_leaf_helper(tree)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('sum_root_to_leaf.py',
                                       'sum_root_to_leaf.tsv',
                                       sum_root_to_leaf))
