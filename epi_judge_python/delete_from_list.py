from test_framework.test_utils import enable_timer_hook


# Delete the node past this one. Assume node is not a tail.
def delete_after(node):
    # Implement this placeholder.
    return


@enable_timer_hook
def delete_from_list_wrapper(timer, head, node_idx):
    node_to_delete = head
    prev = None
    if node_to_delete is None:
        raise RuntimeError('List is empty')
    for _ in range(node_idx):
        if node_to_delete.next is None:
            raise RuntimeError("Can't delete last node")
        prev = node_to_delete
        node_to_delete = node_to_delete.next

    timer.start()
    delete_after(prev)
    timer.stop()

    return head


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('delete_from_list.tsv',
                                              delete_from_list_wrapper)
