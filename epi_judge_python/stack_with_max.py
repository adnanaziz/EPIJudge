from test_framework import generic_test
from test_framework.test_failure import TestFailure


class Stack:
    def __init__(self,):
        self.el = []
        self.asc_s = []

    def empty(self):
        if len(self.el) == 0:
            return True
        return False

    def max(self):
        if self.empty():
            return
        return self.asc_s[-1]

    def pop(self):
        if self.empty():
            return
        x = self.el.pop()
        if x >= self.asc_s[-1]:
            self.asc_s.pop()
        return x

    def push(self, x):
        self.el.append(x)
        if not self.asc_s or x >= self.asc_s[-1]:
            self.asc_s.append(x)
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
                    raise TestFailure(
                        "Pop: expected " + str(arg) + ", got " + str(result))
            elif op == 'max':
                result = s.max()
                if result != arg:
                    raise TestFailure(
                        "Max: expected " + str(arg) + ", got " + str(result))
            elif op == 'empty':
                result = int(s.empty())
                if result != arg:
                    raise TestFailure(
                        "Empty: expected " + str(arg) + ", got " + str(result))
            else:
                raise RuntimeError("Unsupported stack operation: " + op)
    except IndexError:
        raise TestFailure('Unexpected IndexError exception')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("stack_with_max.py",
                                       'stack_with_max.tsv', stack_tester))
