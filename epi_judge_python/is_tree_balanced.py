from sys import exit

from binary_tree_node import BinaryTreeNode
from test_framework import generic_test, test_utils


def is_balanced_binary_tree(tree):
    # Implement this placeholder.
    return True


if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds, 'is_tree_balanced.tsv',
                                       is_balanced_binary_tree))
