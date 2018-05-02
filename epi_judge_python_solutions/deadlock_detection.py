import functools

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook


class GraphVertex:

    WHITE, GRAY, BLACK = range(3)

    def __init__(self):

        self.color = GraphVertex.WHITE

        self.edges = []


def is_deadlocked(graph):
    def has_cycle(cur):
        # Visiting a gray vertex means a cycle.
        if cur.color == GraphVertex.GRAY:
            return True

        cur.color = GraphVertex.GRAY  # Marks current vertex as a gray one.
        # Traverse the neighbor vertices.
        if any(next.color != GraphVertex.BLACK and has_cycle(next)
               for next in cur.edges):
            return True
        cur.color = GraphVertex.BLACK  # Marks current vertex as black.
        return False

    return any(vertex.color == GraphVertex.WHITE and has_cycle(vertex)
               for vertex in graph)


@enable_executor_hook
def is_deadlocked_wrapper(executor, num_nodes, edges):
    if num_nodes <= 0:
        raise RuntimeError('Invalid num_nodes value')
    graph = [GraphVertex() for _ in range(num_nodes)]

    for (fr, to) in edges:
        if fr < 0 or fr >= num_nodes or to < 0 or to >= num_nodes:
            raise RuntimeError('Invalid vertex index')
        graph[fr].edges.append(graph[to])

    return executor.run(functools.partial(is_deadlocked, graph))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("deadlock_detection.py",
                                       'deadlock_detection.tsv',
                                       is_deadlocked_wrapper))
