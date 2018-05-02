from test_framework import generic_test


def get_height(cases, drops):
    def get_height_helper(cases, drops):
        if cases == 0 or drops == 0:
            return 0
        elif cases == 1:
            return drops
        if F[cases][drops] == -1:
            F[cases][drops] = (get_height_helper(cases, drops - 1) +
                               get_height_helper(cases - 1, drops - 1) + 1)
        return F[cases][drops]

    F = [[-1] * (drops + 1) for i in range(cases + 1)]
    return get_height_helper(cases, drops)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("max_safe_height.py",
                                       'max_safe_height.tsv', get_height))
