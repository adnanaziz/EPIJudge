from list_node import ListNode
from test_framework.test_utils import enable_timer_hook


# Insert new_node after node.
def insert_after(node, new_node):
    # Implement this placeholder.
    return


@enable_timer_hook
def insert_list_wrapper(timer, L, pos, key):
    node = L
    for _ in range(pos - 1):
        node = node.next
    new_node = ListNode(key)

    timer.start()
    insert_after(node, new_node)
    timer.stop()

    return L


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('insert_in_list.tsv',
                                              insert_list_wrapper)
