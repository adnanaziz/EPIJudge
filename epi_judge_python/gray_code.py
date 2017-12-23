from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def gray_code(num_bits):
    # Implement this placeholder.
    return []


@enable_timer_hook
def gray_code_wrapper(timer, num_bits):
    def differs_by_1_bit(a, b):
        x = a ^ b
        if x == 0:
            return False
        while x & 1 == 0:
            x >>= 1
        return x == 1

    timer.start()
    result = gray_code(num_bits)
    timer.stop()

    expected_size = (1 << num_bits)
    if len(result) != expected_size:
        raise TestFailureException("Length mismatch: expected " + str(
            expected_size) + ", got " + str(len(result)))
    for i in range(1, len(result)):
        if not differs_by_1_bit(result[i - 1], result[i]):
            if result[i - 1] == result[i]:
                raise TestFailureException("Two adjacent entries are equal")
            else:
                raise TestFailureException(
                    "Two adjacent entries differ by more than 1 bit")

    uniq = set(result)
    if len(uniq) != len(result):
        raise TestFailureException(
            "Not all entries are distinct: found " +
            str(len(result) - len(uniq)) + " duplicates")


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main("gray_code.tsv",
                                              gray_code_wrapper)
