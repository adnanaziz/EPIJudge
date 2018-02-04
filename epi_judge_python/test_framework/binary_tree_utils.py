# @library
import collections
import sys

sys.setrecursionlimit(15500)


def tree_generate_helper(tree, result, order):
    if tree:
        if order == -1:
            result.append(tree.data)
        tree_generate_helper(tree.left, result, order)
        if order == 0:
            result.append(tree.data)
        tree_generate_helper(tree.right, result, order)
        if order == 1:
            result.append(tree.data)


def generate_preorder(tree):
    result = []
    tree_generate_helper(tree, result, -1)
    return result


def generate_inorder(tree):
    result = []
    tree_generate_helper(tree, result, 0)
    return result


def generate_postorder(tree):
    result = []
    tree_generate_helper(tree, result, 1)
    return result


def find_node(tree, val):
    if tree:
        if tree.data == val:
            return tree

        left_result = find_node(tree.left, val)
        if left_result:
            return left_result

        right_result = find_node(tree.right, val)
        if right_result:
            return right_result

    return None


def must_find_node(tree, val):
    result = find_node(tree, val)
    if result is None:
        raise RuntimeError('{} was not found in the tree'.format(val))
    return result


def equal_binary_trees(node1, node2):
    if node1 and node2:
        return (node1.data == node2.data
                and equal_binary_trees(node1.left, node2.left)
                and equal_binary_trees(node1.right, node2.right))

    else:
        return not node1 and not node2


def binary_tree_to_string(tree):
    result = ''
    q = collections.deque()
    visited = set()
    first = True
    null_nodes_pending = 0

    result += '['
    q.append(tree)

    while q:
        node = q.popleft()
        if id(node) in visited:
            raise RuntimeError('Detected a cycle in the tree')
        if node:
            if first:
                first = False
            else:
                result += ', '

            while null_nodes_pending:
                result += 'null, '
                null_nodes_pending -= 1

            result += '"{}"'.format(node.data)

            visited.add(id(node))
            q.append(node.left)
            q.append(node.right)
        else:
            null_nodes_pending += 1

    result += ']'
    return result


def binary_tree_height(tree):
    if not tree:
        return -1
    return 1 + max(
        binary_tree_height(tree.left), binary_tree_height(tree.right))


# Python framework specific functions


def convert_binary_tree_to_binary_tree_with_parent(tree):
    def add_parent_link(node, parent):
        if not node:
            return None
        node.parent = parent
        add_parent_link(node.left, node)
        add_parent_link(node.right, node)

    add_parent_link(tree, None)
    return tree


def strip_parent_link(tree):
    nodes = [tree]
    while nodes:
        n = nodes.pop()
        if n is None:
            continue
        n.parent = None
        nodes.append(n.left)
        nodes.append(n.right)
