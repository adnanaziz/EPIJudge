import collections

PairedTasks = collections.namedtuple('PairedTasks', ('task_1', 'task_2'))


def optimum_task_assignment(task_durations):
    # Implement this placeholder.
    return []


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('task_pairing.tsv', optimum_task_assignment)
