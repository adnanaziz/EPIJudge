from typing import List

from test_framework import generic_test


def palindrome_decompositions(text: str) -> List[List[str]]:
    def directed_palindrome_decompositions(offset, partial_partition):
        if offset == len(text):
            result.append(partial_partition.copy())
            return

        for i in range(offset + 1, len(text) + 1):
            prefix = text[offset:i]
            if prefix == prefix[::-1]:
                directed_palindrome_decompositions(
                    i, partial_partition + [prefix])

    result: List[List[str]] = []
    directed_palindrome_decompositions(offset=0, partial_partition=[])
    return result


# Pythonic solution uses bottom-up construction.
def palindrome_decompositions_pythonic(text: str) -> List[List[str]]:
    return ([[text[:i]] + right
             for i in range(1,
                            len(text) + 1) if text[:i] == text[:i][::-1]
             for right in palindrome_decompositions_pythonic(text[i:])]
            or [[]])


def comp(a, b):
    return sorted(a) == sorted(b)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'enumerate_palindromic_decompositions.py',
            'enumerate_palindromic_decompositions.tsv',
            palindrome_decompositions, comp))
