from test_framework import generic_test


def divide(x, y):

    result, power = 0, 32
    y_power = y << power
    while x >= y:
        while y_power > x:
            y_power >>= 1
            power -= 1

        result += 1 << power
        x -= y_power
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("primitive_divide.py",
                                       "primitive_divide.tsv", divide))
