import copy
import functools
import math

from test_framework.random_sequence_checker import check_sequence_is_uniformly_random, run_func_with_retries
from test_framework.test_utils import enable_timer_hook


def compute_random_permutation(n):
    # Implement this placeholder.
    return []


@enable_timer_hook
def compute_random_permutation_wrapper(timer, n):
    def compute_random_permutation_runner(timer, n):
        def permutation_index(perm):
            p = copy.deepcopy(perm)
            idx = 0
            n = len(p)
            while p:
                a = p.pop(0)
                idx += a * math.factorial(n - 1)
                for i, b in enumerate(p):
                    if b > a:
                        p[i] -= 1
                n -= 1
            return idx

        timer.start()
        result = [compute_random_permutation(n) for _ in range(1000000)]
        timer.stop()

        return check_sequence_is_uniformly_random(
            [permutation_index(perm) for perm in result], math.factorial(n),
            0.01)

    run_func_with_retries(
        functools.partial(compute_random_permutation_runner, timer, n))


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'random_permutation.tsv', compute_random_permutation_wrapper)
