import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook


class GraphVertex:
    def __init__(self):
        self.edges = []
        # Set max_distance = 0 to indicate unvisitied vertex.
        self.max_distance = 0


def find_largest_number_teams(graph):
    # Implement this placeholder.
    return 0


@enable_executor_hook
def find_largest_number_teams_wrapper(executor, k, edges):
    if k <= 0:
        raise RuntimeError('Invalid k value')
    graph = [GraphVertex() for _ in range(k)]

    for (fr, to) in edges:
        if fr < 0 or fr >= k or to < 0 or to >= k:
            raise RuntimeError('Invalid vertex index')
        graph[fr].edges.append(graph[to])

    return executor.run(functools.partial(find_largest_number_teams, graph))


if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds,
                                       'max_teams_in_photograph.tsv',
                                       find_largest_number_teams_wrapper))
