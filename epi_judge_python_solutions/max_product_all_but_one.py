import itertools
import operator

from test_framework import generic_test


def find_biggest_n_minus_one_product(A):

    # Builds suffix products.
    suffix_products = list(
        reversed(list(itertools.accumulate(reversed(A), operator.mul))))

    # Finds the biggest product of (n - 1) numbers.
    prefix_product, max_product = 1, float('-inf')
    for i in range(len(A)):
        suffix_product = suffix_products[i + 1] if i + 1 < len(A) else 1
        max_product = max(max_product, prefix_product * suffix_product)
        prefix_product *= A[i]
    return max_product


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("max_product_all_but_one.py",
                                       'max_product_all_but_one.tsv',
                                       find_biggest_n_minus_one_product))
