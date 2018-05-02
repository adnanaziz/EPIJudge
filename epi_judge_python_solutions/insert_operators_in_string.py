import functools

from test_framework import generic_test


def expression_synthesis(digits, target):
    def directed_expression_synthesis(digits, current_term):
        def evaluate():
            intermediate_operands = []
            operand_it = iter(operands)
            intermediate_operands.append(next(operand_it))
            # Evaluates '*' first.
            for oper in operators:
                if oper == '*':
                    product = intermediate_operands[-1] * next(operand_it)
                    intermediate_operands[-1] = product
                else:  # oper == '+'.
                    intermediate_operands.append(next(operand_it))
            # Evaluates '+' second.
            return sum(intermediate_operands)

        current_term = current_term * 10 + digits[0]
        if len(digits) == 1:
            operands.append(current_term)
            if evaluate() == target:  # Found a match.
                return True
            del operands[-1]
            return False

        # No operator.
        if directed_expression_synthesis(digits[1:], current_term):
            return True
        # Tries multiplication operator '*'.
        operands.append(current_term)
        operators.append('*')
        if directed_expression_synthesis(digits[1:], 0):
            return True
        del operands[-1]
        del operators[-1]
        # Tries addition operator '+'.
        operands.append(current_term)
        # First check feasibility of plus operator.
        if target - evaluate() <= functools.reduce(lambda val, d: val * 10 + d,
                                                   digits[1:], 0):
            operators.append('+')
            if directed_expression_synthesis(digits[1:], 0):
                return True
            del operators[-1]
        del operands[-1]
        return False

    operands, operators = [], []
    return directed_expression_synthesis(digits, 0)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("insert_operators_in_string.py",
                                       "insert_operators_in_string.tsv",
                                       expression_synthesis))
