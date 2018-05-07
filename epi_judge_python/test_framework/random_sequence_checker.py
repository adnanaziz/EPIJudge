
import collections
import math
import random

from test_framework.test_failure import TestFailure


def compute_deviation_multiplier(allowed_false_negative, num_rvs=1):

    individual_rv_error = allowed_false_negative / num_rvs

    ERROR_BOUNDS = [
        1 - 0.682689492137086, 1 - 0.954499736103642, 1 - 0.997300203936740,
        1 - 0.999936657516334, 1 - 0.999999426696856, 1 - 0.999999998026825,
        1 - 0.999999999997440
    ]

    for i, bound in enumerate(ERROR_BOUNDS):
        if bound <= individual_rv_error:
            return i + 1

    return len(ERROR_BOUNDS) + 1


def check_frequencies(seq, n, false_negative_tolerance):
    avg = len(seq) / float(n)
    k_indiv = compute_deviation_multiplier(false_negative_tolerance, n)
    p = 1.0 / n
    sigma_indiv = math.sqrt(len(seq) * p * (1.0 - p))
    k_sigma_indiv = k_indiv * sigma_indiv
    # To make our testing meaningful "sufficiently large", we need to have enough testing data.
    if len(seq) * p < 50 or len(seq) * (1.0 - p) < 50:
        return True  # Sample size is too small so we cannot use normal approximation

    indiv_freqs = collections.Counter(seq)

    # Check that there are roughly len(seq)/n occurrences of key.
    # By roughly we mean the difference is less than k_sigma.
    return all(
        abs(freq - avg) <= k_sigma_indiv for freq in indiv_freqs.values())


def check_pairs_frequencies(seq, n, false_negative_tolerance):
    seq_pairs = [(x, next_x) for x, next_x in zip(seq, seq[1:])]
    return check_frequencies(seq_pairs, n * n, false_negative_tolerance)


def check_triples_frequencies(seq, n, false_negative_tolerance):
    seq_triples = [(x, next_x, next_next_x)
                   for x, next_x, next_next_x in zip(seq, seq[1:], seq[2:])]
    return check_frequencies(seq_triples, n * n * n, false_negative_tolerance)


def check_birthday_spacings(seq, n):
    expected_avg_repetition_length = int(
        math.ceil(math.sqrt(math.log(2) * 2.0 * n)))
    number_of_subarrays = len(seq) - expected_avg_repetition_length + 1
    MIN_NUMBER_SUBARRAYS = 1000
    if number_of_subarrays < MIN_NUMBER_SUBARRAYS:
        return True  # Not enough subarrays for birthday spacing check

    number_of_subarrays_with_repetitions = sum(
        len(set(seq[i:i + expected_avg_repetition_length])) <
        expected_avg_repetition_length
        for i in range(len(seq) - expected_avg_repetition_length))

    COUNT_TOLERANCE = 0.4
    return COUNT_TOLERANCE * number_of_subarrays <= number_of_subarrays_with_repetitions


# seq is a sequence of integers, which should be in the range [0,n-1]. We assume n << len(seq).
def check_sequence_is_uniformly_random(seq, n, false_negative_tolerance):
    return check_frequencies(seq, n, false_negative_tolerance) and \
           check_pairs_frequencies(seq, n, false_negative_tolerance) and \
           check_triples_frequencies(seq, n, false_negative_tolerance) and \
           check_birthday_spacings(seq, n)


def binomial_coefficient(n, k):
    return 0 if n < k else math.factorial(n) // (
        math.factorial(k) * math.factorial(n - k))


# Get the mth combination in lexicographical order from A (n elements) chosen k at a time.
def compute_combination_idx(A, n, k, m):
    comb = []
    a, b, x = n, k, (binomial_coefficient(n, k) - 1) - m
    for _ in range(k):
        a = a - 1
        while binomial_coefficient(a, b) > x:
            a -= 1
        comb.append(A[n - 1 - a])
        x -= binomial_coefficient(a, b)
        b -= 1
    return comb


# Run func several times, and early return if it succeeds; otherwise, throws TestFailure.
def run_func_with_retries(func):
    NUM_RUNS = 5
    # If any of the run succeed, we assume the algorithm is correct.
    if any(func() for _ in range(NUM_RUNS)):
        return
    raise TestFailure("Result is not a random permutation")


if __name__ == '__main__':
    assert check_sequence_is_uniformly_random(
        [random.randint(1, 10) for i in range(1000000)],
        10,
        false_negative_tolerance=0.01)
    assert not check_sequence_is_uniformly_random(
        [random.randint(1, 11) for i in range(1000000)],
        10,
        false_negative_tolerance=0.01)
    assert not check_sequence_is_uniformly_random(
        [i % 10 for i in range(1000000)], 10, false_negative_tolerance=0.01)
