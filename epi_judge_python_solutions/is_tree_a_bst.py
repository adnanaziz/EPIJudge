from binary_tree_node import BinaryTreeNode
from test_framework import generic_test


def is_binary_tree_bst(tree: BinaryTreeNode) -> bool:
    def are_keys_in_range(tree,
                          low_range=float('-inf'),
                          high_range=float('inf')):
        if not tree:
            return True
        elif not low_range <= tree.data <= high_range:
            return False
        return (are_keys_in_range(tree.left, low_range, tree.data)
                and are_keys_in_range(tree.right, tree.data, high_range))

    return are_keys_in_range(tree)


def is_binary_tree_bst_alternative(tree):
    def inorder_traversal(tree):
        if not tree:
            return True
        elif not inorder_traversal(tree.left):
            return False
        elif prev[0] and prev[0].data > tree.data:
            return False
        prev[0] = tree
        return inorder_traversal(tree.right)

    prev = [None]
    return inorder_traversal(tree)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('is_tree_a_bst.py', 'is_tree_a_bst.tsv',
                                       is_binary_tree_bst))
