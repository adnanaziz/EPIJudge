import collections

from test_framework.test_utils import enable_timer_hook

# Event is a tuple (start_time, end_time)
Event = collections.namedtuple('Event', ('start', 'finish'))


def find_max_simultaneous_events(A):
    # Implement this placeholder.
    return 0


@enable_timer_hook
def find_max_simultaneous_events_wrapper(timer, events):
    events = [Event(*x) for x in events]
    timer.start()
    return find_max_simultaneous_events(events)


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'calendar_rendering.tsv', find_max_simultaneous_events_wrapper)
