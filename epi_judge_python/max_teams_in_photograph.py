from test_framework.test_utils import enable_timer_hook


class GraphVertex:
    def __init__(self):
        self.edges = []
        # Set max_distance = 0 to indicate unvisitied vertex.
        self.max_distance = 0


def find_largest_number_teams(graph):
    # Implement this placeholder.
    return 0


@enable_timer_hook
def find_largest_number_teams_wrapper(timer, k, edges):
    if k <= 0:
        raise RuntimeError('Invalid k value')
    graph = [GraphVertex() for _ in range(k)]

    for (fr, to) in edges:
        if fr < 0 or fr >= k or to < 0 or to >= k:
            raise RuntimeError('Invalid vertex index')
        graph[fr].edges.append(graph[to])

    timer.start()
    result = find_largest_number_teams(graph)
    timer.stop()
    return result


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('max_teams_in_photograph.tsv',
                                   find_largest_number_teams_wrapper)
