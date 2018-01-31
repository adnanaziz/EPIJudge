from test_framework.test_utils import enable_timer_hook


# Assumes node_to_delete is not tail.
def deletion_from_list(node_to_delete):
    # Implement this placeholder.
    return


@enable_timer_hook
def deletion_from_list_wrapper(timer, head, node_to_delete_idx):
    node_to_delete = head
    if node_to_delete is None:
        raise RuntimeError('List is empty')
    for _ in range(node_to_delete_idx):
        if node_to_delete.next is None:
            raise RuntimeError("Can't delete last node")
        node_to_delete = node_to_delete.next

    timer.start()
    deletion_from_list(node_to_delete)
    timer.stop()

    return head


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('delete_node_from_list.tsv',
                                              deletion_from_list_wrapper)
