def find_anagrams(dictionary):
    # Implement this placeholder.
    return []


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        "anagrams.tsv", find_anagrams, comparator=test_utils.unordered_compare)
