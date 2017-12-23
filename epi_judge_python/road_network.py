import collections

from test_framework.test_utils import enable_timer_hook

HighwaySection = collections.namedtuple('HighwaySection',
                                        ('x', 'y', 'distance'))


def find_best_proposals(H, P, n):
    # Implement this placeholder.
    return HighwaySection(0, 0, 0)


@enable_timer_hook
def find_best_proposals_wrapper(timer, H, P, n):
    H = [HighwaySection(*x) for x in H]
    P = [HighwaySection(*x) for x in P]

    timer.start()
    return find_best_proposals(H, P, n)


def res_printer(expected, result):
    def fmt(x):
        return [x[0], x[1], x[2]] if x else None

    return fmt(expected), fmt(result)


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'road_network.tsv',
        find_best_proposals_wrapper,
        res_printer=res_printer)
