import functools
import random

from test_framework.random_sequence_checker import check_sequence_is_uniformly_random, run_func_with_retries
from test_framework.test_utils import enable_timer_hook


def zero_one_random():
    return random.randrange(2)


def uniform_random(lower_bound, upper_bound):
    # Implement this placeholder.
    return 0


@enable_timer_hook
def uniform_random_wrapper(timer, lower_bound, upper_bound):
    def uniform_random_runner(timer, lower_bound, upper_bound):
        timer.start()
        result = [
            uniform_random(lower_bound, upper_bound) for _ in range(100000)
        ]
        timer.stop()

        return check_sequence_is_uniformly_random(
            [a - lower_bound for a in result], upper_bound - lower_bound + 1,
            0.01)

    run_func_with_retries(
        functools.partial(uniform_random_runner, timer, lower_bound,
                          upper_bound))


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('uniform_random_number.tsv',
                                              uniform_random_wrapper)
