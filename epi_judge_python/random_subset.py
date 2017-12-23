import functools

from test_framework.random_sequence_checker import \
    check_sequence_is_uniformly_random, binomial_coefficient, \
    compute_combination_idx, run_func_with_retries
from test_framework.test_utils import enable_timer_hook


def random_subset(n, k):
    # Implement this placeholder.
    return []


@enable_timer_hook
def random_subset_wrapper(timer, n, k):
    def random_subset_runner(timer, n, k):
        timer.start()
        result = [random_subset(n, k) for _ in range(100000)]
        timer.stop()

        total_possible_outcomes = binomial_coefficient(n, k)
        comb_to_idx = {
            tuple(compute_combination_idx(list(range(n)), n, k, i)): i
            for i in range(binomial_coefficient(n, k))
        }
        return check_sequence_is_uniformly_random(
            [comb_to_idx[tuple(sorted(a))] for a in result],
            total_possible_outcomes, 0.01)

    run_func_with_retries(functools.partial(random_subset_runner, timer, n, k))


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('random_subset.tsv',
                                              random_subset_wrapper)
