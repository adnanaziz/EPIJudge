from test_framework import generic_test
from list_node import ListNode

def reverse_sublist(L: ListNode, start, finish):
    if L is None:
        return L

    dh = anchor = ListNode(0, L)
    for _ in range(1, start):
        anchor = anchor.next

    p, c = None, anchor.next
    for _ in range(start, finish+1):
        n = c.next
        c.next = p
        p = c
        c = n

    anchor.next.next = c
    anchor.next = p
    return dh.next


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("reverse_sublist.py",
                                       "reverse_sublist.tsv", reverse_sublist))
