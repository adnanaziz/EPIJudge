import collections

from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


class Team:
    Player = collections.namedtuple('Player', ('height'))

    def __init__(self, height):
        self._players = [Team.Player(h) for h in height]

    # Checks if A can be placed in front of B.
    @staticmethod
    def valid_placement_exists(A, B):
        # Implement this placeholder.
        return True


@enable_timer_hook
def valid_placement_exists_wrapper(timer, h1, h2, expected12, expected21):
    t1, t2 = Team(h1), Team(h2)

    timer.start()
    result12 = Team.valid_placement_exists(t1, t2)
    result21 = Team.valid_placement_exists(t2, t1)
    timer.stop()

    if result12 != expected12 or result21 != expected21:
        raise TestFailureException("")


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('is_array_dominated.tsv',
                                              valid_placement_exists_wrapper)
