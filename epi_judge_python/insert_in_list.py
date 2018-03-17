import functools
from sys import exit

from list_node import ListNode
from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook


# Insert new_node after node.
def insert_after(node, new_node):
    # Implement this placeholder.
    return


@enable_executor_hook
def insert_list_wrapper(executor, l, node_idx, new_node_data):
    node = l
    for _ in range(node_idx - 1):
        node = node.next
    new_node = ListNode(new_node_data)

    executor.run(functools.partial(insert_after, node, new_node))

    return l


if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds, 'insert_in_list.tsv',
                                       insert_list_wrapper))
