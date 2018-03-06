from list_node import ListNode


def search_list(L, key):
    # Implement this placeholder.
    return None


def search_list_wrapper(L, key):
    result = search_list(L, key)
    return result.data if result else -1


from sys import exit
from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds, 'search_in_list.tsv',
                                       search_list_wrapper))
