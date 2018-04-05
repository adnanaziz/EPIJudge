import collections
from sys import exit

from test_framework import generic_test, test_utils

PairedTasks = collections.namedtuple('PairedTasks', ('task_1', 'task_2'))


def optimum_task_assignment(task_durations):
    task_durations.sort()
    return [
        PairedTasks(task_durations[i], task_durations[~i])
        for i in range(len(task_durations) // 2)
    ]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('task_pairing.tsv',
                                       optimum_task_assignment))
