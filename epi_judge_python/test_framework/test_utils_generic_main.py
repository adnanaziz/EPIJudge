# @library
import argparse
import os
import sys

from test_framework import test_utils, generic_test_handler


def generic_test_main(filename,
                      func,
                      comp=test_utils.equal_to,
                      res_printer=None):
    """
    :param filename - file with test data
    :param func - function to be tested
    :param comp - custom comparator. A function that accepts
        (expected, computed result) and returns a boolean value
    :param res_printer - function for customized printing
    """
    try:
        parser = argparse.ArgumentParser()
        parser.add_argument('--test_data_dir', nargs='?', const=True, type=str)
        parser.add_argument('--run_all_tests', default=False, action='store_true')
        args = parser.parse_args()
        if args.test_data_dir:
            if not os.path.isdir(args.test_data_dir):
                raise RuntimeError(
                    '--test_data_dir argument "{}" is not a directory'.format(
                        args.test_data_dir))
        else:
            args.test_data_dir = test_utils.get_default_test_data_dir_path()

        timeout = 0
        stop_on_error = not args.run_all_tests
        test_utils.run_tests(
            os.path.join(args.test_data_dir, filename),
            generic_test_handler.GenericTestHandler(func, comp=comp), timeout,
            stop_on_error, res_printer)
    except RuntimeError as e:
        print('\nCritical error: {}'.format(e), file=sys.stderr)


def test_func(i1, i2, i3, l, f1, f2, s1, s2):
    assert isinstance(i1, int), "Invalid type"
    assert isinstance(i2, int), "Invalid type"
    assert isinstance(i3, int), "Invalid type"
    assert isinstance(l, int), "Invalid type"
    assert isinstance(f1, float), "Invalid type"
    assert isinstance(f2, float), "Invalid type"
    assert isinstance(s1, str), "Invalid type"
    assert isinstance(s2, str), "Invalid type"

    return len(s1) == i1 and len(s2) == i2


def array_test(x, li, lli, lls):
    return [x == len(l) for l in [li, lli, lls]]


if __name__ == '__main__':
    generic_test_main('simple_test_2.tsv', test_func)
    generic_test_main('simple_test_array.tsv', array_test)
