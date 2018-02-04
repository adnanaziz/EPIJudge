import copy
import math

from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def solve_sudoku(partial_assignment):
    # Implement this placeholder.
    return True


def assert_unique_seq(seq):
    seen = set()
    for x in seq:
        if x == 0:
            raise TestFailureException('Cell left uninitialized')
        if x < 0 or x > len(seq):
            raise TestFailureException('Cell value out of range')
        if x in seen:
            raise TestFailureException('Duplicate value in section')
        seen.add(x)


def gather_square_block(data, block_size, n):
    block_x = (n % block_size) * block_size
    block_y = (n // block_size) * block_size

    return [
        data[block_x + i][block_y + j]
        for j in range(block_size) for i in range(block_size)
    ]


@enable_timer_hook
def solve_sudoku_wrapper(timer, partial_assignment):
    solved = copy.deepcopy(partial_assignment)

    timer.start()
    solve_sudoku(solved)
    timer.stop()

    if len(partial_assignment) != len(solved):
        raise TestFailureException('Initial cell assignment has been changed')

    for (br, sr) in zip(partial_assignment, solved):
        if len(br) != len(sr):
            raise TestFailureException(
                'Initial cell assignment has been changed')
        for (bcell, scell) in zip(br, sr):
            if bcell != 0 and bcell != scell:
                raise TestFailureException(
                    'Initial cell assignment has been changed')

    block_size = int(math.sqrt(len(solved)))

    for i in range(len(solved)):
        assert_unique_seq(solved[i])
        assert_unique_seq([row[i] for row in solved])
        assert_unique_seq(gather_square_block(solved, block_size, i))


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('sudoku_solve.tsv', solve_sudoku_wrapper)
