import collections
import heapq

from test_framework import generic_test


def calculate_bonus(productivity):

    # Stores (productivity, index)-pair in min_heap where ordered by
    # productivity.
    EmployeeData = collections.namedtuple('EmployeeData',
                                          ('productivity', 'index'))
    min_heap = [EmployeeData(p, i) for i, p in enumerate(productivity)]
    heapq.heapify(min_heap)

    # Initially assigns one ticket to everyone.
    tickets = [1] * len(productivity)
    # Fills tickets from lowest rating to highest rating.
    while min_heap:
        next_dev = heapq.heappop(min_heap)[1]
        # Handles the left neighbor.
        if next_dev > 0 and productivity[next_dev] > productivity[next_dev
                                                                  - 1]:
            tickets[next_dev] = tickets[next_dev - 1] + 1
        # Handles the right neighbor.
        if (next_dev + 1 < len(tickets)
                and productivity[next_dev] > productivity[next_dev + 1]):
            tickets[next_dev] = max(tickets[next_dev],
                                    tickets[next_dev + 1] + 1)
    return sum(tickets)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("bonus.py", 'bonus.tsv',
                                       calculate_bonus))
