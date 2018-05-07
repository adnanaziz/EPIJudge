from bst_node import BstNode
from test_framework import generic_test


# Build a BST from the (s + 1)-th to the e-th node in L.
def build_bst_from_sorted_doubly_list_helper(L, s, e):
    curr = None
    if s < e:
        m = s + ((e - s) // 2)
        temp, L = build_bst_from_sorted_doubly_list_helper(L, s, m)
        curr = L
        curr.left = temp
        L = L.right
        curr.right, L = build_bst_from_sorted_doubly_list_helper(L, m + 1, e)
    return curr, L


def build_bst_from_sorted_doubly_list(L, n):
    return build_bst_from_sorted_doubly_list_helper(L, 0, n)[0]


# Transform a BST into a circular sorted doubly linked list in-place,
# return the head of the list.
def bst_to_doubly_list_helper(n):
    # Empty subtree.
    if not n:
        return None

    # Recursively build the list from left and right subtrees.
    l_head = bst_to_doubly_list_helper(n.left)
    r_head = bst_to_doubly_list_helper(n.right)

    # Append n to the list from left subtree.
    if l_head:
        l_tail = l_head.left
        l_tail.right = n
        n.left = l_tail
        l_tail = n
    else:
        l_head = l_tail = n

    # Append the list from right subtree to n.
    if r_head:
        r_tail = r_head.left
        l_tail.right = r_head
        r_head.left = l_tail
    else:
        r_tail = l_tail
    r_tail.right = l_head
    l_head.left = r_tail

    return l_head


def bst_to_doubly_list(n):
    result = bst_to_doubly_list_helper(n)
    result.left.right = None  # breaks the link from tail to head.
    result.left = None  # breaks the link from head to tail.
    return result


# Count the list length till end.
def count_length(L):
    length = 0
    while L:
        length += 1
        L = L.right
    return length


def merge_two_bsts(A, B):

    A, B = bst_to_doubly_list(A), bst_to_doubly_list(B)
    A_length, B_length = count_length(A), count_length(B)
    return build_bst_from_sorted_doubly_list(
        merge_two_sorted_lists(A, B), A_length + B_length)


# Merges two sorted doubly linked lists, returns the head of merged list.
def merge_two_sorted_lists(A, B):
    sorted_head = BstNode()
    tail = sorted_head

    AB = [A, B]
    while all(AB):
        A_or_B = 0 if AB[0].data < AB[1].data else 1
        tail.right = AB[A_or_B]
        tail = tail.right  # Resets tail to the last node.
        AB[A_or_B] = tail.right

    if AB[0]:  # Appends the remaining of A.
        tail.right = AB[0]
    elif AB[1]:  # Appends the remaining of B.
        tail.right = AB[1]
    return sorted_head.right


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("bst_merge.py", 'bst_merge.tsv',
                                       merge_two_bsts))
