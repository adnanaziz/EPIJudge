import functools

from posting_list_node import PostingListNode
from test_framework import generic_test
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def copy_postings_list(L):

    if not L:
        return None

    # Stage 1: Makes a copy of the original list without assigning the jump
    #          field, and creates the mapping for each node in the original
    #          list to the copied list.
    it = L
    while it:
        new_node = PostingListNode(it.order, it.next, None)
        it.next = new_node
        it = new_node.next

    # Stage 2: Assigns the jump field in the copied list.
    it = L
    while it:
        if it.jump:
            it.next.jump = it.jump.next
        it = it.next.next

    # Stage 3: Reverts the original list, and assigns the next field of
    #          the copied list.
    it = L
    new_list_head = it.next
    while it.next:
        it.next, it = it.next.next, it.next
    return new_list_head


def assert_lists_equal(orig, copy):
    node_mapping = dict()
    o_it = orig
    c_it = copy
    while o_it:
        if not c_it:
            raise TestFailure('Copied list has fewer nodes than the original')
        if o_it.order != c_it.order:
            raise TestFailure('Order value mismatch')
        node_mapping[o_it] = c_it
        o_it = o_it.next
        c_it = c_it.next

    if c_it:
        raise TestFailure('Copied list has more nodes than the original')

    o_it = orig
    c_it = copy
    while o_it:
        if c_it in node_mapping:
            raise TestFailure(
                'Copied list contains a node from the original list')
        if o_it.jump is None:
            if c_it.jump is not None:
                raise TestFailure(
                    'Jump link points to a different nodes in the copied list')
        else:
            if not node_mapping[o_it.jump] is c_it.jump:
                raise TestFailure(
                    'Jump link points to a different nodes in the copied list')
        o_it = o_it.next
        c_it = c_it.next


@enable_executor_hook
def copy_postings_list_wrapper(executor, l):
    def create_posting_list(serialized):
        key_mapping = dict()
        head = None
        for (order, _) in reversed(serialized):
            head = PostingListNode(order, head)
            key_mapping[order] = head

        list_it = head
        for (_, jump_index) in serialized:
            if jump_index != -1:
                list_it.jump = key_mapping.get(jump_index, None)
                if not list_it.jump:
                    raise RuntimeError('Jump index out of range')

        return head

    head = create_posting_list(l)

    copy = executor.run(functools.partial(copy_postings_list, head))

    assert_lists_equal(head, copy)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("copy_posting_list.py",
                                       'copy_posting_list.tsv',
                                       copy_postings_list_wrapper))
