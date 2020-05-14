from test_framework import generic_test


def is_match(regex: str, s: str) -> bool:
    def is_match_here(regex, s):
        if not regex:
            # Case (1.): Empty regex matches all strings.
            return True

        if regex == '$':
            # Case (2.): Reach the end of regex, and last char is '$'.
            return not s

        if len(regex) >= 2 and regex[1] == '*':
            # Case (3.): A '*' match.
            # Iterate through s, checking '*' condition, if '*' condition holds,
            # performs the remaining checks.
            i = 1
            while i <= len(s) and regex[0] in ('.', s[i - 1]):
                if is_match_here(regex[2:], s[i:]):
                    return True
                i += 1
            # See '*' matches zero character in s[:len(s)].
            return is_match_here(regex[2:], s)

        # Case (4.): regex begins with single character match.
        return bool(s and regex[0] in ('.', s[0])
                    and is_match_here(regex[1:], s[1:]))

    # Case (2.): regex starts with '^'.
    if regex[0] == '^':
        return is_match_here(regex[1:], s)
    return any(is_match_here(regex, s[i:]) for i in range(len(s) + 1))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('regular_expression.py',
                                       'regular_expression.tsv', is_match))
