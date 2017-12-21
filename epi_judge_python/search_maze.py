import collections
import copy

from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook

WHITE, BLACK = range(2)

Coordinate = collections.namedtuple('Coordinate', ('x', 'y'))


def search_maze(maze, s, e):
    # Implement this placeholder.
    return []


def path_element_is_feasible(maze, prev, cur):
    if not ((0 <= cur.x < len(maze)) and
            (0 <= cur.y < len(maze[cur.x])) and maze[cur.x][cur.y] == WHITE):
        return False
    return cur == (prev.x + 1, prev.y) or \
           cur == (prev.x - 1, prev.y) or \
           cur == (prev.x, prev.y + 1) or \
           cur == (prev.x, prev.y - 1)


@enable_timer_hook
def search_maze_wrapper(timer, maze, s, e):
    s = Coordinate(*s)
    e = Coordinate(*e)
    cp = copy.deepcopy(maze)

    timer.start()
    path = search_maze(cp, s, e)
    timer.stop()

    if not path:
        return s == e

    if path[0] != s or path[-1] != e:
        raise TestFailureException(
            "Path doesn't lay between start and end points")

    for i in range(1, len(path)):
        if not path_element_is_feasible(maze, path[i - 1], path[i]):
            raise TestFailureException("Path contains invalid segments")

    return True


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('search_maze.tsv',
                                              search_maze_wrapper)
