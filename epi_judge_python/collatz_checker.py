def test_collatz_conjecture(n):
    # Implement this placeholder.
    return False


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds, 'collatz_checker.tsv',
                                       test_collatz_conjecture))
