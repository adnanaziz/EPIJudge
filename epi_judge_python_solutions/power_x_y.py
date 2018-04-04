def power(x, y):
    result, power = 1.0, y
    if y < 0:
        power, x = -power, 1.0 / x
    while power:
        if power & 1:
            result *= x
        x, power = x * x, power >> 1
    return result


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(generic_test.generic_test_main('power_x_y.tsv', power))
