from test_framework import generic_test

class ListNode:
    def __init__(self, val):
        self.next = None
        self.val = val

def reverse_sublist(L, start, finish):
    if not L or not L.next:
        return L
    dummy = ListNode(None)
    head = L
    m, n = start, finish
    dummy.next = head
    for i in range(n):
        if i == m - 2:
            m_pre = head
        if i == m - 1:
            m_node = head
        if i == n - 1:
            n_node = head
        head = head.next
    if m == 1:
        m_pre = dummy

    while m_node != n_node:
        m_pre.next = m_node.next
        m_node.next = n_node.next
        n_node.next = m_node
        m_node = m_pre.next
    
    return dummy.next


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("reverse_sublist.py",
                                       "reverse_sublist.tsv", reverse_sublist))
