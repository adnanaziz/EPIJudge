import functools

from test_framework.random_sequence_checker import \
    check_sequence_is_uniformly_random, binomial_coefficient, \
    compute_combination_idx, run_func_with_retries
from test_framework.test_utils import enable_timer_hook


def random_sampling(k, A):
    # Implement this placeholder.
    return


@enable_timer_hook
def random_sampling_wrapper(timer, k, A):
    def random_sampling_runner(timer, k, A):
        result = []
        timer.start()
        for _ in range(100000):
            random_sampling(k, A)
            result.append(A[:k])
        timer.stop()

        total_possible_outcomes = binomial_coefficient(len(A), k)
        A = sorted(A)
        comb_to_idx = {
            tuple(compute_combination_idx(A, len(A), k, i)): i
            for i in range(binomial_coefficient(len(A), k))
        }

        return check_sequence_is_uniformly_random(
            [comb_to_idx[tuple(sorted(a))] for a in result],
            total_possible_outcomes, 0.01)

    run_func_with_retries(
        functools.partial(random_sampling_runner, timer, k, A))


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('offline_sampling.tsv',
                                   random_sampling_wrapper)
