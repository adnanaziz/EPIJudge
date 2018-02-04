from test_framework.test_failure_exception import TestFailureException


class Stack:
    def empty(self):
        # Implement this placeholder.
        return True

    def max(self):
        # Implement this placeholder.
        return 0

    def pop(self):
        # Implement this placeholder.
        return 0

    def push(self, x):
        # Implement this placeholder.
        return


def stack_tester(ops):
    try:
        s = Stack()

        for (op, arg) in ops:
            if op == 'Stack':
                s = Stack()
            elif op == 'push':
                s.push(arg)
            elif op == 'pop':
                result = s.pop()
                if result != arg:
                    raise TestFailureException(
                        "Pop: expected " + str(arg) + ", got " + str(result))
            elif op == 'max':
                result = s.max()
                if result != arg:
                    raise TestFailureException(
                        "Max: expected " + str(arg) + ", got " + str(result))
            elif op == 'empty':
                result = int(s.empty())
                if result != arg:
                    raise TestFailureException(
                        "Empty: expected " + str(arg) + ", got " + str(result))
            else:
                raise RuntimeError("Unsupported stack operation: " + op)
    except IndexError:
        raise TestFailureException('Unexpected IndexError exception')


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('stack_with_max.tsv', stack_tester)
