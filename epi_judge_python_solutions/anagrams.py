import collections

from test_framework import generic_test, test_utils


def find_anagrams(dictionary):

    sorted_string_to_anagrams = collections.defaultdict(list)
    for s in dictionary:
        # Sorts the string, uses it as a key, and then appends the original
        # string as another value into hash table.
        sorted_string_to_anagrams[''.join(sorted(s))].append(s)

    return [
        group for group in sorted_string_to_anagrams.values()
        if len(group) >= 2
    ]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "anagrams.py",
            "anagrams.tsv",
            find_anagrams,
            comparator=test_utils.unordered_compare))
