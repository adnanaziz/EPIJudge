from test_framework.test_failure_exception import TestFailureException


class Queue:
    def __init__(self, capacity):
        # Implement this placeholder.
        return

    def enqueue(self, x):
        # Implement this placeholder.
        return

    def dequeue(self):
        # Implement this placeholder.
        return 0

    def size(self):
        # Implement this placeholder.
        return 0


def queue_tester(ops):
    q = Queue(1)

    for (op, arg) in ops:
        if op == 'Queue':
            q = Queue(arg)
        elif op == 'enqueue':
            q.enqueue(arg)
        elif op == 'dequeue':
            result = q.dequeue()
            if result != arg:
                raise TestFailureException(
                    "Dequeue: expected " + str(arg) + ", got " + str(result))
        elif op == 'size':
            result = q.size()
            if result != arg:
                raise TestFailureException(
                    "Size: expected " + str(arg) + ", got " + str(result))
        else:
            raise RuntimeError("Unsupported queue operation: " + op)


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('circular_queue.tsv',
                                              queue_tester)
