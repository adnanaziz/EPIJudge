import collections
from typing import List

from test_framework import generic_test


def find_all_substrings(s: str, words: List[str]) -> List[int]:
    def match_all_words_in_dict(start):
        curr_string_to_freq = collections.Counter()
        for i in range(start, start + len(words) * unit_size, unit_size):
            curr_word = s[i:i + unit_size]
            it = word_to_freq[curr_word]
            if it == 0:
                return False
            curr_string_to_freq[curr_word] += 1
            if curr_string_to_freq[curr_word] > it:
                # curr_word occurs too many times for a match to be possible.
                return False
        return True

    word_to_freq = collections.Counter(words)
    unit_size = len(words[0])
    return [
        i for i in range(len(s) - unit_size * len(words) + 1)
        if match_all_words_in_dict(i)
    ]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'string_decompositions_into_dictionary_words.py',
            'string_decompositions_into_dictionary_words.tsv',
            find_all_substrings))
