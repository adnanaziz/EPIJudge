import functools
from typing import List

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook


class TrafficElement:
    def __init__(self, time: int, volume: float) -> None:
        self.time = time
        self.volume = volume


def calculate_traffic_volumes(A: List[TrafficElement],
                              w: int) -> List[TrafficElement]:
    # TODO - you fill in here.
    return []


@enable_executor_hook
def calculate_traffic_volumes_wrapper(executor, A, w):
    A = [TrafficElement(t, v) for (t, v) in A]

    result = executor.run(functools.partial(calculate_traffic_volumes, A, w))

    return [(x.time, x.volume) for x in result]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('max_of_sliding_window.py',
                                       'max_of_sliding_window.tsv',
                                       calculate_traffic_volumes_wrapper))
