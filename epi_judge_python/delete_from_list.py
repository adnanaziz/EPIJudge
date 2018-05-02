import functools

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook


# Delete the node past this one. Assume node is not a tail.
def delete_after(node):
    # TODO - you fill in here.
    return


@enable_executor_hook
def delete_from_list_wrapper(executor, head, node_idx):
    node_to_delete = head
    prev = None
    if node_to_delete is None:
        raise RuntimeError('List is empty')
    for _ in range(node_idx):
        if node_to_delete.next is None:
            raise RuntimeError("Can't delete last node")
        prev = node_to_delete
        node_to_delete = node_to_delete.next

    executor.run(functools.partial(delete_after, prev))

    return head


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("delete_from_list.py",
                                       'delete_from_list.tsv',
                                       delete_from_list_wrapper))
