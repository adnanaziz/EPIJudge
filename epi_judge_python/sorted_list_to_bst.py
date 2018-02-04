from doubly_list_node import DoublyListNode
from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


# Returns the root of the corresponding BST. The prev and next fields of the
# list nodes are used as the BST nodes left and right fields, respectively.
# The length of the list is given.
def build_bst_from_sorted_doubly_list(L, n):
    # Implement this placeholder.
    return None


def compare_vector_and_tree(tree, it):
    if not tree:
        return

    compare_vector_and_tree(tree.prev, it)

    v = next(it, None)
    if v is None:
        raise TestFailureException("Too few values in the tree")
    if v != tree.data:
        raise TestFailureException("Unexpected value")

    compare_vector_and_tree(tree.next, it)


@enable_timer_hook
def build_bst_from_sorted_doubly_list_wrapper(timer, L):
    l = None
    for v in reversed(L):
        l = DoublyListNode(v, next=l)
        if l.next != None:
            l.next.prev = l

    timer.start()
    l = build_bst_from_sorted_doubly_list(l, len(L))
    timer.stop()

    it = iter(L)
    compare_vector_and_tree(l, it)
    if next(it, None) is not None:
        raise TestFailureException("Too many L in the tree")


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main("sorted_list_to_bst.tsv",
                                   build_bst_from_sorted_doubly_list_wrapper)
