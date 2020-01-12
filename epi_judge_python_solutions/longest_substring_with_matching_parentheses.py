from test_framework import generic_test


def longest_matching_parentheses(s: str) -> int:

    max_length, end, left_parentheses_indices = 0, -1, []
    for i, c in enumerate(s):
        if c == '(':
            left_parentheses_indices.append(i)
        elif not left_parentheses_indices:
            end = i
        else:
            left_parentheses_indices.pop()
            start = (left_parentheses_indices[-1]
                     if left_parentheses_indices else end)
            max_length = max(max_length, i - start)
    return max_length


def longest_matching_parentheses_constant_space(s: str) -> int:
    def parse_from_side(s, paren):
        max_length = num_parens_so_far = length = 0
        for c in s:
            if c == paren:
                num_parens_so_far, length = num_parens_so_far + 1, length + 1
            else:  # c != paren
                if num_parens_so_far <= 0:
                    num_parens_so_far = length = 0
                else:
                    num_parens_so_far -= 1
                    length += 1
                    if num_parens_so_far == 0:
                        max_length = max(max_length, length)
        return max_length

    return max(parse_from_side(s, '('), parse_from_side(reversed(s), ')'))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'longest_substring_with_matching_parentheses.py',
            'longest_substring_with_matching_parentheses.tsv',
            longest_matching_parentheses))
