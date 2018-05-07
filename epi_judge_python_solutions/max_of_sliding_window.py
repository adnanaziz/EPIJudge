import functools

from queue_with_max_using_deque import QueueWithMax
from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook


class TrafficElement:
    def __init__(self, time, volume):
        self.time = time
        self.volume = volume

    # Following operators are needed for QueueWithMax with maximum.
    def __lt__(self, other):
        return self.volume < other.volume

    def __eq__(self, other):
        return self.time == other.time and self.volume == other.volume


def calculate_traffic_volumes(A, w):

    sliding_window = QueueWithMax()
    maximum_volumes = []
    for traffic_info in A:
        sliding_window.enqueue(traffic_info)
        while traffic_info.time - sliding_window.head().time > w:
            sliding_window.dequeue()
        maximum_volumes.append(
            TrafficElement(traffic_info.time,
                           sliding_window.max().volume))
    return maximum_volumes


@enable_executor_hook
def calculate_traffic_volumes_wrapper(executor, A, w):
    A = [TrafficElement(t, v) for (t, v) in A]

    result = executor.run(functools.partial(calculate_traffic_volumes, A, w))

    return [(x.time, x.volume) for x in result]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("max_of_sliding_window.py",
                                       'max_of_sliding_window.tsv',
                                       calculate_traffic_volumes_wrapper))
