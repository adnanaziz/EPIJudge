from test_framework import generic_test


def minimum_path_weight(triangle):
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("minimum_weight_path_in_a_triangle.py",
                                       'minimum_weight_path_in_a_triangle.tsv',
                                       minimum_path_weight))
