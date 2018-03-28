from sys import exit

from list_node import ListNode
from test_framework import generic_test, test_utils


# Assumes L has at least k nodes, deletes the k-th last node in L.
def remove_kth_last(L, k):
    # Implement this placeholder.
    return None


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('delete_kth_last_from_list.tsv',
                                       remove_kth_last))
