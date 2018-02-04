import collections

Rectangle = collections.namedtuple('Rectangle', ('x', 'y', 'width', 'height'))


def intersect_rectangle(R1, R2):
    # Implement this placeholder.
    return Rectangle(0, 0, 0, 0)


def intersect_rectangle_wrapper(R1, R2):
    return intersect_rectangle(Rectangle(*R1), Rectangle(*R2))


def res_printer(expected, result):
    def fmt(x):
        return [x[0], x[1], x[2], x[3]] if x else None

    return fmt(expected), fmt(result)


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        'rectangle_intersection.tsv',
        intersect_rectangle_wrapper,
        res_printer=res_printer)
