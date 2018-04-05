def multiply(x, y):
    def add(a, b):
        while b:
            carry = a & b
            a, b = a ^ b, carry << 1
        return a

    running_sum = 0
    while x:  # Examines each bit of x.
        if x & 1:
            running_sum = add(running_sum, y)
        x, y = x >> 1, y << 1
    return running_sum


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(generic_test.generic_test_main('primitive_multiply.tsv', multiply))
