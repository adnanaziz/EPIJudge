def is_arbitrage_exist(graph):
    # Implement this placeholder.
    return True


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(generic_test.generic_test_main("arbitrage.tsv", is_arbitrage_exist))
