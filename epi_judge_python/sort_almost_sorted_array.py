def sort_approximately_sorted_array(sequence, k):
    # Implement this placeholder.
    return []


def sort_approximately_sorted_array_wrapper(sequence, k):
    return sort_approximately_sorted_array(iter(sequence), k)


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(
            timeout_seconds, 'sort_almost_sorted_array.tsv',
            sort_approximately_sorted_array_wrapper))
