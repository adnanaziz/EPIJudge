import collections
from typing import List

from test_framework import generic_test
from test_framework.test_failure import TestFailure


class GraphVertex:
    def __init__(self, label: int) -> None:
        self.label = label
        self.edges: List['GraphVertex'] = []


def clone_graph(graph: GraphVertex) -> GraphVertex:

    if graph is None:
        return None

    q = collections.deque([graph])
    vertex_map = {graph: GraphVertex(graph.label)}
    while q:
        v = q.popleft()
        for e in v.edges:
            # Try to copy vertex e.
            if e not in vertex_map:
                vertex_map[e] = GraphVertex(e.label)
                q.append(e)
            # Copy edge.
            vertex_map[v].edges.append(vertex_map[e])
    return vertex_map[graph]


def copy_labels(edges):
    return [e.label for e in edges]


def check_graph(node, graph):
    if node is None:
        raise TestFailure('Graph was not copied')

    vertex_set = set()
    q = collections.deque()
    q.append(node)
    vertex_set.add(node)
    while q:
        vertex = q.popleft()
        if vertex.label >= len(graph):
            raise TestFailure('Invalid vertex label')
        label1 = copy_labels(vertex.edges)
        label2 = copy_labels(graph[vertex.label].edges)
        if sorted(label1) != sorted(label2):
            raise TestFailure('Edges mismatch')
        for e in vertex.edges:
            if e not in vertex_set:
                vertex_set.add(e)
                q.append(e)


def clone_graph_test(k, edges):
    if k <= 0:
        raise RuntimeError('Invalid k value')
    graph = [GraphVertex(i) for i in range(k)]

    for (fr, to) in edges:
        if fr < 0 or fr >= k or to < 0 or to >= k:
            raise RuntimeError('Invalid vertex index')
        graph[fr].edges.append(graph[to])

    result = clone_graph(graph[0])
    check_graph(result, graph)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('graph_clone.py', 'graph_clone.tsv',
                                       clone_graph_test))
