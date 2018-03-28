import collections
from sys import exit

from test_framework import generic_test, test_utils

PairedTasks = collections.namedtuple('PairedTasks', ('task_1', 'task_2'))


def optimum_task_assignment(task_durations):
    # Implement this placeholder.
    return []


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('task_pairing.tsv',
                                       optimum_task_assignment))
