from test_framework import generic_test


# We use stack and previous node pointer to simulate postorder traversal.
def postorder_traversal(tree):
    # TODO - you fill in here.
    return []


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "tree_postorder.py", 'tree_postorder.tsv', postorder_traversal))
