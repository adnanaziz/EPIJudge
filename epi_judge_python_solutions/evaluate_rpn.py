from typing import List

from test_framework import generic_test


def evaluate(expression: str) -> int:

    intermediate_results: List[int] = []
    delimiter = ','
    operators = {
        '+': lambda y, x: x + y,
        '-': lambda y, x: x - y,
        '*': lambda y, x: x * y,
        '/': lambda y, x: x // y
    }

    for token in expression.split(delimiter):
        if token in operators:
            intermediate_results.append(operators[token](
                intermediate_results.pop(), intermediate_results.pop()))
        else:  # token is a number.
            intermediate_results.append(int(token))
    return intermediate_results[-1]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('evaluate_rpn.py', 'evaluate_rpn.tsv',
                                       evaluate))
