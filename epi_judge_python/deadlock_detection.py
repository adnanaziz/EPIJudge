from test_framework.test_utils import enable_timer_hook


class GraphVertex:

    white, gray, black = range(3)

    def __init__(self):
        self.color = GraphVertex.white
        self.edges = []


def is_deadlocked(graph):
    # Implement this placeholder.
    return True


@enable_timer_hook
def is_deadlocked_wrapper(timer, num_nodes, edges):
    if num_nodes <= 0:
        raise RuntimeError('Invalid num_nodes value')
    graph = [GraphVertex() for _ in range(num_nodes)]

    for (fr, to) in edges:
        if fr < 0 or fr >= num_nodes or to < 0 or to >= num_nodes:
            raise RuntimeError('Invalid vertex index')
        graph[fr].edges.append(graph[to])

    timer.start()
    result = is_deadlocked(graph)
    timer.stop()
    return result


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('deadlock_detection.tsv',
                                   is_deadlocked_wrapper)
