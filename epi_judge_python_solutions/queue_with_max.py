from stack_with_max import Stack
from test_framework import generic_test
from test_framework.test_failure import TestFailure


class QueueWithMax:
    def __init__(self):
        self._enqueue = Stack()
        self._dequeue = Stack()

    def enqueue(self, x):

        self._enqueue.push(x)

    def dequeue(self):

        if self._dequeue.empty():
            while not self._enqueue.empty():
                self._dequeue.push(self._enqueue.pop())
        if not self._dequeue.empty():
            return self._dequeue.pop()
        raise IndexError('Cannot get dequeue() on empty queue.')

    def max(self):

        if not self._enqueue.empty():
            return self._enqueue.max() if self._dequeue.empty() else max(
                self._enqueue.max(), self._dequeue.max())
        elif not self._dequeue.empty():
            return self._dequeue.max()
        raise IndexError('Cannot get max() on empty queue.')


def queue_tester(ops):

    try:
        q = QueueWithMax()

        for (op, arg) in ops:
            if op == 'QueueWithMax':
                q = QueueWithMax()
            elif op == 'enqueue':
                q.enqueue(arg)
            elif op == 'dequeue':
                result = q.dequeue()
                if result != arg:
                    raise TestFailure("Dequeue: expected " + str(arg) +
                                      ", got " + str(result))
            elif op == 'max':
                result = q.max()
                if result != arg:
                    raise TestFailure(
                        "Max: expected " + str(arg) + ", got " + str(result))
            else:
                raise RuntimeError("Unsupported queue operation: " + op)
    except IndexError:
        raise TestFailure('Unexpected IndexError exception')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("queue_with_max.py",
                                       'queue_with_max.tsv', queue_tester))
