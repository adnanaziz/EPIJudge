# @library
import argparse

from os import path

from test_framework.test_utils import get_default_test_data_dir_path


class TestConfig:
    def __init__(self, test_data_dir, test_data_file, stop_on_error, timeout):
        self.test_data_dir = test_data_dir
        self.test_data_file = test_data_file
        self.stop_on_error = stop_on_error
        self.timeout = timeout

    @staticmethod
    def from_command_line(test_data_file, commandline_args):
        config = TestConfig('', test_data_file, True, 0)

        parser = argparse.ArgumentParser()
        parser.add_argument('--test_data_dir', nargs='?', const=True, type=str)
        parser.add_argument(
            '--run_all_tests', default=False, action='store_true')
        args = parser.parse_args(commandline_args)

        config.test_data_dir = args.test_data_dir
        config.stop_on_error = not args.run_all_tests

        if config.test_data_dir:
            if not path.isdir(config.test_data_dir):
                raise RuntimeError(
                    '--test_data_dir argument "{}" is not a directory'.format(
                        config.test_data_dir))
        else:
            config.test_data_dir = get_default_test_data_dir_path()

        return config
