import collections


class GraphVertex:
    def __init__(self, label):
        self.label = label
        self.edges = []


def clone_graph(graph):
    # Implement this placeholder.
    return None


def copy_labels(edges):
    return [e.label for e in edges]


def check_graph(node, graph):
    from test_framework.test_failure_exception import TestFailureException
    vertex_set = set()
    q = collections.deque()
    q.append(node)
    vertex_set.add(node)
    while q:
        vertex = q.popleft()
        if vertex.label >= len(graph):
            raise TestFailureException('')
        label1 = copy_labels(vertex.edges)
        label2 = copy_labels(graph[vertex.label].edges)
        label1.sort()
        label2.sort()
        if label1 != label2:
            raise TestFailureException('')
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


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('graph_clone.tsv', clone_graph_test)
