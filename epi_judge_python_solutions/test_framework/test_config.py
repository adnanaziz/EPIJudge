
import argparse
import os

from test_framework.test_utils import get_default_test_data_dir_path
from test_framework.tri_bool import TriBool


class TestConfig:
    def __init__(self, test_file, test_data_file, timeout_seconds,
                 num_failed_tests_before_stop):
        self.test_data_dir = ''
        self.test_file = test_file
        self.test_data_file = test_data_file
        self.verbose = True
        self.tty_mode = TriBool.INDETERMINATE
        self.color_mode = TriBool.INDETERMINATE
        self.timeout_seconds = timeout_seconds
        self.num_failed_tests_before_stop = num_failed_tests_before_stop

    @staticmethod
    def from_command_line(test_file, test_data_file, timeout_seconds,
                          num_failed_tests_before_stop, commandline_args):
        # Set num_failed_tests_before_stop to 0, means users want to run as many as tests in one run.
        if num_failed_tests_before_stop == 0:
            num_failed_tests_before_stop = float('inf')

        config = TestConfig(test_file, test_data_file, timeout_seconds,
                            num_failed_tests_before_stop)

        parser = argparse.ArgumentParser()
        parser.add_argument(
            '--test-data-dir',
            nargs='?',
            const=True,
            type=str,
            help='path to test_data directory')
        parser.add_argument(
            '--no-verbose',
            dest='verbose',
            default=True,
            action='store_false',
            help='suppress failure description on test failure')
        parser.add_argument(
            '--force-tty',
            dest='tty_mode',
            default=TriBool.INDETERMINATE,
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
            default=TriBool.INDETERMINATE,
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
        parser.add_argument(
            '--no-update-js',
            dest='update_js',
            default=False,
            action='store_false',
            help='No update problem_mapping.js')
        args = parser.parse_args(commandline_args)

        config.test_data_dir = args.test_data_dir
        config.verbose = args.verbose
        config.tty_mode = args.tty_mode
        config.color_mode = args.color_mode
        config.update_js = args.update_js

        if config.test_data_dir:
            if not os.path.isdir(config.test_data_dir):
                raise RuntimeError(
                    'CL: --test-data-dir argument ({}) is not a directory'.
                    format(config.test_data_dir))
        else:
            config.test_data_dir = get_default_test_data_dir_path()

        return config
