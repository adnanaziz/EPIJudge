import functools

from test_framework.random_sequence_checker import \
    check_sequence_is_uniformly_random, binomial_coefficient, \
    compute_combination_idx, run_func_with_retries
from test_framework.test_utils import enable_timer_hook


# Assumption: there are at least k elements in the stream.
def online_random_sample(it, k):
    # Implement this placeholder.
    return []


@enable_timer_hook
def online_random_sample_wrapper(timer, A, k):
    def online_random_sample_runner(timer, A, k):
        timer.start()
        result = [online_random_sample(iter(A), k) for _ in range(100000)]
        timer.stop()

        total_possible_outcomes = binomial_coefficient(len(A), k)
        A = sorted(A)
        comb_to_idx = {
            tuple(compute_combination_idx(A, len(A), k, i)): i
            for i in range(binomial_coefficient(len(A), k))
        }
        return check_sequence_is_uniformly_random(
            [comb_to_idx[tuple(sorted(a))]
             for a in result], total_possible_outcomes, 0.01)

    run_func_with_retries(
        functools.partial(online_random_sample_runner, timer, A, k))


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main("online_sampling.tsv",
                                              online_random_sample_wrapper)
