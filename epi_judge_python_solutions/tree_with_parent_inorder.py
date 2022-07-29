from typing import List

from binary_tree_with_parent_prototype import BinaryTreeNode
from test_framework import generic_test


def inorder_traversal(tree: BinaryTreeNode) -> List[int]:

    prev, result = None, []
    while tree:
        if prev is tree.parent and tree.left:  # Keep going left.
            next = tree.left
        elif prev is tree.parent or tree.left is prev:
            result.append(tree.data)
            # Done with left, so go right if right is not empty. Otherwise,
            # go up.
            next = tree.right or tree.parent
        else:  # Done with both children, so move up.
            next = tree.parent

        prev, tree = tree, next
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('tree_with_parent_inorder.py',
                                       'tree_with_parent_inorder.tsv',
                                       inorder_traversal))
