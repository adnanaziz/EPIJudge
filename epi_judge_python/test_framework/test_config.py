# @library
import argparse

from os import path

from test_framework.test_utils import get_default_test_data_dir_path
from test_framework.tri_bool import TriBool


class TestConfig:
    def __init__(self, test_data_file, timeout):
        self.test_data_dir = ''
        self.test_data_file = test_data_file
        self.run_all_tests = False
        self.verbose = True
        self.tty_mode = TriBool.INDETERMINATE
        self.color_mode = TriBool.INDETERMINATE
        self.timeout = timeout

    @staticmethod
    def from_command_line(test_data_file, timeout_ms, commandline_args):
        config = TestConfig(test_data_file, timeout_ms)

        parser = argparse.ArgumentParser()
        # TODO add help
        parser.add_argument(
            '--test-data-dir',
            nargs='?',
            const=True,
            type=str,
            help='path to test_data directory')
        parser.add_argument(
            '--run-all-tests',
            dest='run_all_tests',
            action='store_true',
            help='execution all tests')
        parser.add_argument(
            '--no-verbose',
            dest='verbose',
            action='store_false',
            help='suppress failure description on test failure')
        parser.add_argument(
            '--force-tty',
            dest='tty_mode',
            action='store_const',
            const=TriBool.TRUE,
            help=
            'enable tty features (like printing output on the same line) even in case stdout is not a tty device'
        )
        parser.add_argument(
            '--no-tty',
            dest='tty_mode',
            action='store_const',
            const=TriBool.FALSE,
            help='never use tty features')
        parser.add_argument(
            '--force-color',
            dest='color_mode',
            action='store_const',
            const=TriBool.TRUE,
            help='enable colored output even in case stdout is not a tty device'
        )
        parser.add_argument(
            '--no-color',
            dest='color_mode',
            action='store_const',
            const=TriBool.FALSE,
            help='never use colored output')
        parser.set_defaults(
            run_all_tests=True,
            verbose=True,
            tty_mode=TriBool.INDETERMINATE,
            color_mode=TriBool.INDETERMINATE)
        args = parser.parse_args(commandline_args)

        config.test_data_dir = args.test_data_dir
        config.run_all_tests = args.run_all_tests
        config.verbose = args.verbose
        config.tty_mode = args.tty_mode
        config.color_mode = args.color_mode

        if config.test_data_dir:
            if not path.isdir(config.test_data_dir):
                raise RuntimeError(
                    'CL: --test-data-dir argument ({}) is not a directory'.
                    format(config.test_data_dir))
        else:
            config.test_data_dir = get_default_test_data_dir_path()

        return config
