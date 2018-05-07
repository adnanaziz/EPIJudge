from test_framework import generic_test


def is_arbitrage_exist(graph):
    # TODO - you fill in here.
    return True


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("arbitrage.py", "arbitrage.tsv",
                                       is_arbitrage_exist))
