# @library
import sys
import collections
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


def equal_binary_trees(r1, r2):
    if r1 and r2:
        return (equal_binary_trees(r1.left, r2.left)
                and equal_binary_trees(r1.right, r2.right)
                and r1.data == r2.data)
    else:
        return not r1 and not r2


def must_find_node(tree, val):
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

    result = find_node(tree, val)
    if result is None:
        raise RuntimeError('{} was not found int the tree'.format(val))
    return result


def binary_tree_to_string(node):
    result = '['
    q = collections.deque([node])
    visited = set()

    null_nodes_pending = 0
    first = True

    while q:
        n = q.popleft()
        if id(n) in visited:  # TODO: Denote cycles
            continue
        if n:
            if first:
                first = False
            else:
                result += ', '
            while null_nodes_pending:
                result += 'null, '
                null_nodes_pending -= 1
            result += '"{}"'.format(n.data)

            visited.add(id(n))
            q.append(n.left)
            q.append(n.right)
        else:
            null_nodes_pending += 1

    result += ']'
    return result


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
