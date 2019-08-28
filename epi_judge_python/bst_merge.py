from typing import Optional

from bst_node import BstNode
from test_framework import generic_test


def merge_two_bsts(A: BstNode, B: BstNode) -> Optional[BstNode]:
    # TODO - you fill in here.
    return None


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('bst_merge.py', 'bst_merge.tsv',
                                       merge_two_bsts))
