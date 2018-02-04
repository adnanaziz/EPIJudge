import functools

from test_framework.random_sequence_checker import \
    check_sequence_is_uniformly_random, binomial_coefficient, \
    compute_combination_idx, run_func_with_retries
from test_framework.test_utils import enable_timer_hook


# Assumption: there are at least k elements in the stream.
def online_random_sample(stream, k):
    # Implement this placeholder.
    return []


@enable_timer_hook
def online_random_sample_wrapper(timer, stream, k):
    def online_random_sample_runner(timer, stream, k):
        timer.start()
        result = [online_random_sample(iter(stream), k) for _ in range(100000)]
        timer.stop()

        total_possible_outcomes = binomial_coefficient(len(stream), k)
        stream = sorted(stream)
        comb_to_idx = {
            tuple(compute_combination_idx(stream, len(stream), k, i)): i
            for i in range(binomial_coefficient(len(stream), k))
        }
        return check_sequence_is_uniformly_random(
            [comb_to_idx[tuple(sorted(a))] for a in result],
            total_possible_outcomes, 0.01)

    run_func_with_retries(
        functools.partial(online_random_sample_runner, timer, stream, k))


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main("online_sampling.tsv",
                                   online_random_sample_wrapper)
