from test_framework import generic_test


def preorder_traversal(tree):

    path, result = [tree], []
    while path:
        curr = path.pop()
        if curr:
            result.append(curr.data)
            path += [curr.right, curr.left]
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("tree_preorder.py", 'tree_preorder.tsv',
                                       preorder_traversal))
