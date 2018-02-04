import collections

from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


class Team:
    Player = collections.namedtuple('Player', ('height'))

    def __init__(self, height):
        self._players = [Team.Player(h) for h in height]

    # Checks if team0 can be placed in front of team1.
    @staticmethod
    def valid_placement_exists(team0, team1):
        # Implement this placeholder.
        return True


@enable_timer_hook
def valid_placement_exists_wrapper(timer, team0, team1, expected_01,
                                   expected10):
    t0, t1 = Team(team0), Team(team1)

    timer.start()
    if Team.valid_placement_exists(
            t0, t1) != expected_01 or Team.valid_placement_exists(
                t1, t0) != expected10:
        raise TestFailureException("")


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('is_array_dominated.tsv',
                                   valid_placement_exists_wrapper)
