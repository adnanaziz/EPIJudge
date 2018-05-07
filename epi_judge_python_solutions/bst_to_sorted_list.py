import collections
import functools

from test_framework import generic_test
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def bst_to_doubly_linked_list(tree):

    HeadAndTail = collections.namedtuple('HeadAndTail', ('head', 'tail'))

    # Transforms a BST into a sorted doubly linked list in-place,
    # and return the head and tail of the list.
    def bst_to_doubly_linked_list_helper(tree):
        # Empty subtree.
        if not tree:
            return HeadAndTail(None, None)

        # Recursively builds the list from left and right subtrees.
        left = bst_to_doubly_linked_list_helper(tree.left)
        right = bst_to_doubly_linked_list_helper(tree.right)

        # Appends tree to the list from left subtree.
        if left.tail:
            left.tail.right = tree
        tree.left = left.tail

        # Appends the list from right subtree to tree.
        tree.right = right.head
        if right.head:
            right.head.left = tree

        return HeadAndTail(left.head or tree, right.tail or tree)

    return bst_to_doubly_linked_list_helper(tree).head


@enable_executor_hook
def bst_to_doubly_linked_list_wrapper(executor, tree):
    l = executor.run(functools.partial(bst_to_doubly_linked_list, tree))

    if l is not None and l.left is not None:
        raise TestFailure(
            'Function must return the head of the list. Left link must be None'
        )

    v = []
    while l:
        v.append(l.data)
        if l.right and l.right.left is not l:
            raise TestFailure('List is ill-formed')
        l = l.right

    return v


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("bst_to_sorted_list.py",
                                       'bst_to_sorted_list.tsv',
                                       bst_to_doubly_linked_list_wrapper))
