from typing import List

from test_framework import generic_test


def justify_text(words: List[str], L: int) -> List[str]:

    curr_line_length, result = 0, []
    curr_line: List[str] = []
    for word in words:
        if curr_line_length + len(word) + len(curr_line) > L:
            # Distribute equally between words in curr_line.
            for i in range(L - curr_line_length):
                curr_line[i % max(len(curr_line) - 1, 1)] += ' '
            result.append(''.join(curr_line))
            curr_line, curr_line_length = [], 0
        curr_line.append(word)
        curr_line_length += len(word)
    # Use ljust(L) to pad the last line with the appropriate number of blanks.
    return result + [' '.join(curr_line).ljust(L)]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('left_right_justify_text.py',
                                       'left_right_justify_text.tsv',
                                       justify_text))
