from test_framework.test_failure_exception import TestFailureException


class QueueWithMax:
    def enqueue(self, x):
        # Implement this placeholder.
        return

    def dequeue(self):
        # Implement this placeholder.
        return 0

    def max(self):
        # Implement this placeholder.
        return 0


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
                    raise TestFailureException("Dequeue: expected " + str(arg)
                                               + ", got " + str(result))
            elif op == 'max':
                result = q.max()
                if result != arg:
                    raise TestFailureException("Max: expected " + str(arg) +
                                               ", got " + str(result))
            else:
                raise RuntimeError("Unsupported queue operation: " + op)
    except IndexError:
        raise TestFailureException('Unexpected IndexError exception')


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('queue_with_max.tsv',
                                              queue_tester)
