import collections
import functools
import math

from test_framework.random_sequence_checker import run_func_with_retries
from test_framework.test_utils import enable_timer_hook


def nonuniform_random_number_generation(values, probabilities):
    # Implement this placeholder.
    return 0


@enable_timer_hook
def nonuniform_random_number_generation_wrapper(timer, values, probabilities):
    def nonuniform_random_number_generation_runner(timer, values,
                                                   probabilities):
        n = 10**6
        timer.start()
        result = [
            nonuniform_random_number_generation(values, probabilities)
            for _ in range(n)
        ]
        timer.stop()

        counts = collections.Counter(result)
        for v, p in zip(values, probabilities):
            if n * p < 50 or n * (1.0 - p) < 50:
                continue
            sigma = math.sqrt(n * p * (1.0 - p))
            if abs(float(counts[v]) - (p * n)) > 5 * sigma:
                return False
        return True

    run_func_with_retries(
        functools.partial(nonuniform_random_number_generation_runner, timer,
                          values, probabilities))


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('nonuniform_random_number.tsv',
                                   nonuniform_random_number_generation_wrapper)
