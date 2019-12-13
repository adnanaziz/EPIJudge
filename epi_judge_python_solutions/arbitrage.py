import math
from typing import List

from test_framework import generic_test


def is_arbitrage_exist(graph: List[List[float]]) -> bool:
    def bellman_ford(graph, source):
        dis_to_source = ([float('inf')] * (source - 1) + [0] + [float('inf')] *
                         (len(graph) - source))

        for _ in range(1, len(graph)):
            have_update = False
            for i, row in enumerate(graph):
                for j, g in enumerate(row):
                    if (dis_to_source[i] != float('inf')
                            and dis_to_source[j] > dis_to_source[i] + g):
                        have_update = True
                        dis_to_source[j] = dis_to_source[i] + g

            # No update in this iteration means no negative cycle.
            if not have_update:
                return False

        # Detects cycle if there is any further update.
        return any(dis_to_source[i] != float('inf')
                   and dis_to_source[j] > dis_to_source[i] + g
                   for i, row in enumerate(graph) for j, g in enumerate(row))

    # Uses Bellman-ford to find negative weight cycle.
    return bellman_ford([[-math.log10(edge) for edge in edge_list]
                         for edge_list in graph], 0)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('arbitrage.py', 'arbitrage.tsv',
                                       is_arbitrage_exist))
