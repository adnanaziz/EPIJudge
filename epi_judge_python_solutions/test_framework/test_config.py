import argparse
import os

from test_framework.test_utils import get_default_test_data_dir_path
from test_framework.tri_bool import TriBool


class TestConfig:
    """
    This class contains parameters that control test execution

    Attributes:
        test_data_dir (str): path to directory with .tsv files

        test_file (str): program source filename

        test_data_file (str): name of corresponding .tsv file

        tty_mode (TriBool):
          if TRUE, enable advanced output (mainly usage of \r)
          if INDETERMINATE, try to autodetect if output is console

        color_mode (TriBool):
          if TRUE, enable colored output
          if INDETERMINATE, try to autodetect if output is console

        update_js (bool):
          if True, update problem_mapping.js

        timeout_seconds (float): if > 0, run each test with a timeout

        num_failed_tests_before_stop (int):
          number of failures, before the testing is terminated
          if zero, testing is never terminated

        analyze_complexity (bool): if True, enable solution complexity analyze

        metric_names_override (func (list[str]) -> list[str]):
          function for adjusting list of metric names
          by default identity function
          another function may be set in program_config callback

        metrics_override (func (list[int], <test func args>) -> list[int]):
          function for adjusting list of generated metrics
          all changes should be isomorphic to metric_names_override
          by default returns identical metrics list
          another function may be set in program_config callback
    """
    def __init__(self, test_file, test_data_file, timeout_seconds,
                 num_failed_tests_before_stop):
        self.test_data_dir = ''
        self.test_file = test_file
        self.test_data_file = test_data_file
        self.tty_mode = TriBool.INDETERMINATE
        self.color_mode = TriBool.INDETERMINATE
        self.update_js = True
        self.timeout_seconds = timeout_seconds
        self.num_failed_tests_before_stop = num_failed_tests_before_stop
        self.analyze_complexity = False
        self.complexity_timeout = 20
        self.metric_names_override = lambda names: names
        self.metrics_override = lambda metrics, *func_args: metrics

    @staticmethod
    def from_command_line(test_file, test_data_file, timeout_seconds,
                          num_failed_tests_before_stop, commandline_args):
        # Set num_failed_tests_before_stop to 0, means users want to run as many as tests in one run.
        if num_failed_tests_before_stop == 0:
            num_failed_tests_before_stop = float('inf')

        config = TestConfig(test_file, test_data_file, timeout_seconds,
                            num_failed_tests_before_stop)

        parser = argparse.ArgumentParser()
        parser.add_argument('--test-data-dir',
                            nargs='?',
                            const=True,
                            type=str,
                            help='path to test_data directory')
        parser.add_argument(
            '--force-tty',
            dest='tty_mode',
            default=TriBool.INDETERMINATE,
            action='store_const',
            const=TriBool.TRUE,
            help=
            'enable tty features (like printing output on the same line) even in case stdout is not a tty device'
        )
        parser.add_argument('--no-tty',
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
        parser.add_argument('--no-color',
                            dest='color_mode',
                            action='store_const',
                            const=TriBool.FALSE,
                            help='never use colored output')
        parser.add_argument('--no-update-js',
                            dest='update_js',
                            default=True,
                            action='store_false',
                            help='no update problem_mapping.js')
        parser.add_argument('--no-complexity',
                            dest='analyze_complexity',
                            default=False,
                            action='store_false',
                            help='no asymptotic complexity estimation')
        args = parser.parse_args(commandline_args)

        config.test_data_dir = args.test_data_dir
        config.tty_mode = args.tty_mode
        config.color_mode = args.color_mode
        config.update_js = args.update_js
        config.analyze_complexity = args.analyze_complexity

        if config.test_data_dir:
            if not os.path.isdir(config.test_data_dir):
                raise RuntimeError(
                    'CL: --test-data-dir argument ({}) is not a directory'.
                    format(config.test_data_dir))
        else:
            config.test_data_dir = get_default_test_data_dir_path()

        return config
