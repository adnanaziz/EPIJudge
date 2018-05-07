from test_framework import generic_test


# Given n, return all primes up to and including n.
def generate_primes(n):
    # TODO - you fill in here.
    return []


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("prime_sieve.py", "prime_sieve.tsv",
                                       generate_primes))
