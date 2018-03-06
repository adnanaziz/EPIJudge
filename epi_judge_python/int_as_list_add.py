from list_node import ListNode


def add_two_numbers(L1, L2):
    # Implement this placeholder.
    return None


from sys import exit
from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds, 'int_as_list_add.tsv',
                                       add_two_numbers))
