from binary_tree_node import BinaryTreeNode
from test_framework.test_utils import enable_timer_hook


def generate_all_binary_trees(num_nodes):
    # Implement this placeholder.
    return []


def serialize_structure(tree):
    result = []
    q = [tree]
    while q:
        a = q.pop(0)
        result.append(0 if not a else 1)
        if a:
            q.append(a.left)
            q.append(a.right)
    return result


@enable_timer_hook
def generate_all_binary_trees_wrapper(timer, num_nodes):
    timer.start()
    result = generate_all_binary_trees(num_nodes)
    timer.stop()

    return sorted(map(serialize_structure, result))


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('enumerate_trees.tsv',
                                   generate_all_binary_trees_wrapper)
