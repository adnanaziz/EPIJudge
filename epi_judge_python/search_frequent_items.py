# Finds the candidates which may occur > n / k times.
def search_frequent_items(k, stream):
    # Implement this placeholder.
    return []


def search_frequent_items_wrapper(k, stream):
    return search_frequent_items(k, iter(stream))


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(
            timeout_seconds, "search_frequent_items.tsv",
            search_frequent_items_wrapper, test_utils.unordered_compare))
