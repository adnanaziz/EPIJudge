from test_framework.test_utils import enable_timer_hook


class GraphVertex:

    white, gray, black = range(3)

    def __init__(self):
        self.color = GraphVertex.white
        self.edges = []


def is_deadlocked(G):
    # Implement this placeholder.
    return True


@enable_timer_hook
def is_deadlocked_wrapper(timer, k, edges):
    if k <= 0:
        raise RuntimeError('Invalid k value')
    graph = [GraphVertex() for _ in range(k)]

    for (fr, to) in edges:
        if fr < 0 or fr >= k or to < 0 or to >= k:
            raise RuntimeError('Invalid vertex index')
        graph[fr].edges.append(graph[to])

    timer.start()
    result = is_deadlocked(graph)
    timer.stop()
    return result


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('deadlock_detection.tsv',
                                              is_deadlocked_wrapper)
