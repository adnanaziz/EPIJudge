from test_framework.test_utils import enable_timer_hook


class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None, nxt=None):
        self.data = data
        self.left = left
        self.right = right
        self.next = nxt  # Populates this field.


def construct_right_sibling(tree):
    # Implement this placeholder.
    return


def traverse_next(node):
    while node:
        yield node
        node = node.next
    raise StopIteration


def traverse_left(node):
    while node:
        yield node
        node = node.left
    raise StopIteration


def init_next_link(node):
    if node:
        node.next = None
        init_next_link(node.left)
        init_next_link(node.right)


@enable_timer_hook
def construct_right_sibling_wrapper(timer, tree):
    init_next_link(tree)

    timer.start()
    construct_right_sibling(tree)
    timer.stop()

    return [[n.data for n in traverse_next(level)]
            for level in traverse_left(tree)]


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('tree_right_sibling.tsv',
                                              construct_right_sibling_wrapper)
