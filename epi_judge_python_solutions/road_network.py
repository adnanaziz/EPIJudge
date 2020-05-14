import collections
import functools
import itertools
from typing import List

from test_framework import generic_test
from test_framework.test_failure import PropertyName
from test_framework.test_utils import enable_executor_hook

HighwaySection = collections.namedtuple('HighwaySection',
                                        ('x', 'y', 'distance'))


def find_best_proposals(H: List[HighwaySection], P: List[HighwaySection],
                        n: int) -> HighwaySection:

    # graph stores the shortest path distances between all pairs of vertices.
    graph = [[float('inf')] * i + [0] + [float('inf')] * (n - i - 1)
             for i in range(n)]
    # Builds an undirected graph graph based on existing highway sections H.
    for h in H:
        graph[h.x][h.y] = graph[h.y][h.x] = h.distance

    def floyd_warshall(graph):
        for k, i, j in itertools.product(range(len(graph)), repeat=3):
            if graph[i][k] != float('inf') and graph[k][j] != float('inf'):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

    # Performs floyd warshall to build the shortest path between vertices.
    floyd_warshall(graph)

    # Examines each proposal for shorter distance for all pairs.
    best_distance_saving = float('-inf')
    best_proposal = HighwaySection(-1, -1, 0)  # Default.
    for p in P:
        proposal_saving = 0
        for a, b in itertools.product(range(n), range(n)):
            saving = graph[a][b] - min(
                graph[a][p.x] + p.distance + graph[p.y][b],
                graph[a][p.y] + p.distance + graph[p.x][b])
            proposal_saving += max(saving, 0)
        if proposal_saving > best_distance_saving:
            best_distance_saving = proposal_saving
            best_proposal = p
    return best_proposal


@enable_executor_hook
def find_best_proposals_wrapper(executor, H, P, n):
    H = [HighwaySection(*x) for x in H]
    P = [HighwaySection(*x) for x in P]

    return executor.run(functools.partial(find_best_proposals, H, P, n))


def res_printer(prop, value):
    def fmt(x):
        return [x[0], x[1], x[2]] if x else None

    if prop in (PropertyName.EXPECTED, PropertyName.RESULT):
        return fmt(value)
    else:
        return value


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('road_network.py',
                                       'road_network.tsv',
                                       find_best_proposals_wrapper,
                                       res_printer=res_printer))
