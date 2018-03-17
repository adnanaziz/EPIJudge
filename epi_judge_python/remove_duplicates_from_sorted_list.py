from sys import exit

from list_node import ListNode
from test_framework import generic_test, test_utils


def remove_duplicates(L):
    # Implement this placeholder.
    return None


if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(
            timeout_seconds, 'remove_duplicates_from_sorted_list.tsv',
            remove_duplicates))
