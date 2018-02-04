import collections

from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook

Person = collections.namedtuple('Person', ('age', 'name'))


def group_by_age(people):
    # Implement this placeholder.
    return


@enable_timer_hook
def group_by_age_wrapper(timer, people):
    if not people:
        return
    people = [Person(*x) for x in people]
    values = collections.Counter()
    values.update(people)

    timer.start()
    group_by_age(people)
    timer.stop()

    if not people:
        raise TestFailureException('Empty result')

    new_values = collections.Counter()
    new_values.update(people)
    if new_values != values:
        raise TestFailureException('Entry set changed')

    ages = set()
    last_age = people[0]

    for x in people:
        if x.age in ages:
            raise TestFailureException('Entries are not grouped by age')
        if last_age != x.age:
            ages.add(last_age)
            last_age = x.age


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('group_equal_entries.tsv',
                                   group_by_age_wrapper)
