# Given n, return all primes up to and including n.
def generate_primes(n):
    # Implement this placeholder.
    return []


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(generic_test.generic_test_main("prime_sieve.tsv", generate_primes))
