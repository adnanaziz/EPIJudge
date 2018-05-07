from test_framework import generic_test


# We use stack and previous node pointer to simulate postorder traversal.
def postorder_traversal(tree):

    if not tree:  # Empty tree.
        return []

    path_stack, prev, postorder_sequence = [tree], None, []
    while path_stack:
        curr = path_stack[-1]
        if not prev or prev.left is curr or prev.right is curr:
            # We came down to curr from prev.
            if curr.left:  # Traverse left.
                path_stack.append(curr.left)
            elif curr.right:  # Traverse right.
                path_stack.append(curr.right)
            else:  # Leaf node, visit current node.
                postorder_sequence.append(curr.data)
                path_stack.pop()
        elif curr.left is prev:
            # Done with left, now traverse right.
            if curr.right:
                path_stack.append(curr.right)
            else:  # No right child, so visit curr.
                postorder_sequence.append(curr.data)
                path_stack.pop()
        else:
            # Finished traversing left and right, so visit curr.
            postorder_sequence.append(curr.data)
            path_stack.pop()
        prev = curr
    return postorder_sequence


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "tree_postorder.py", 'tree_postorder.tsv', postorder_traversal))
