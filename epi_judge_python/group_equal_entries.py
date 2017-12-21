import collections

from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook

Person = collections.namedtuple('Person', ('age', 'name'))


def group_by_age(people):
    # Implement this placeholder.
    return


@enable_timer_hook
def group_by_age_wrapper(timer, v):
    if not v:
        return
    v = [Person(*x) for x in v]
    values = collections.Counter()
    values.update(v)

    timer.start()
    group_by_age(v)
    timer.stop()

    if not v:
        raise TestFailureException('Empty result')

    new_values = collections.Counter()
    new_values.update(v)
    if new_values != values:
        raise TestFailureException('Entry set changed')

    ages = set()
    last_age = v[0]

    for x in v:
        if x.age in ages:
            raise TestFailureException('Entries are not grouped by age')
        if last_age != x.age:
            ages.add(last_age)
            last_age = x.age


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('group_equal_entries.tsv',
                                              group_by_age_wrapper)
