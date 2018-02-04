class Queue:
    def enqueue(self, x):
        # Implement this placeholder.
        return

    def dequeue(self):
        # Implement this placeholder.
        return 0


def queue_tester(ops):
    from test_framework.test_failure_exception import TestFailureException

    try:
        q = Queue()

        for (op, arg) in ops:
            if op == 'Queue':
                q = Queue()
            elif op == 'enqueue':
                q.enqueue(arg)
            elif op == 'dequeue':
                result = q.dequeue()
                if result != arg:
                    raise TestFailureException("Dequeue: expected " + str(arg)
                                               + ", got " + str(result))
            else:
                raise RuntimeError("Unsupported queue operation: " + op)
    except IndexError:
        raise TestFailureException('Unexpected IndexError exception')


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('queue_from_stacks.tsv', queue_tester)
