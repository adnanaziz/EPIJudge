from test_framework.test_utils import enable_timer_hook


class GraphVertex:
    def __init__(self):
        self.d = -1
        self.edges = []


def is_any_placement_feasible(graph):
    # Implement this placeholder.
    return True


@enable_timer_hook
def is_any_placement_feasible_wrapper(timer, k, edges):
    if k <= 0:
        raise RuntimeError('Invalid k value')
    graph = [GraphVertex() for _ in range(k)]

    for (fr, to) in edges:
        if fr < 0 or fr >= k or to < 0 or to >= k:
            raise RuntimeError('Invalid vertex index')
        graph[fr].edges.append(graph[to])

    timer.start()
    result = is_any_placement_feasible(graph)
    timer.stop()
    return result


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('is_circuit_wirable.tsv',
                                   is_any_placement_feasible_wrapper)
