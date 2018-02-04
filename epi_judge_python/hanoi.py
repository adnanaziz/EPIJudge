from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook

NUM_PEGS = 3


def compute_tower_hanoi(num_rings):
    # Implement this placeholder.
    return []


@enable_timer_hook
def compute_tower_hanoi_wrapper(timer, num_rings):
    pegs = [list(reversed(range(1, num_rings + 1)))
            ] + [[] for _ in range(1, NUM_PEGS)]

    timer.start()
    result = compute_tower_hanoi(num_rings)
    timer.stop()

    for from_peg, to_peg in result:
        if pegs[to_peg] and pegs[from_peg][-1] >= pegs[to_peg][-1]:
            raise TestFailureException("Illegal move from {} to {}".format(
                pegs[from_peg][-1], pegs[to_peg][-1]))
        pegs[to_peg].append(pegs[from_peg].pop())
    expected_pegs1 = [[], [], list(reversed(range(1, num_rings + 1)))]
    expected_pegs2 = [[], list(reversed(range(1, num_rings + 1))), []]
    if pegs not in (expected_pegs1, expected_pegs2):
        raise TestFailureException(
            "Pegs doesn't place in the right configuration")


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('hanoi.tsv', compute_tower_hanoi_wrapper)
