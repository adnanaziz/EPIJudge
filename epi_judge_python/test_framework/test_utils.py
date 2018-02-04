# @library
import math
import os
import re

from concurrent import futures

from test_framework.timeout_exception import TimeoutException


def split_tsv_file(tsv_file):
    ROW_DELIM = '\n'
    FIELD_DELIM = '\t'

    try:
        with open(tsv_file) as input_data:
            return [
                row.replace(ROW_DELIM, '').split(FIELD_DELIM)
                for row in input_data
            ]
    except OSError:
        raise RuntimeError('Test data file not found')


def get_default_test_data_dir_path():
    MAX_SEARCH_DEPTH = 4
    ENV_KEY = 'EPI_TEST_DATA_DIR'
    DIR_NAME = 'test_data'

    env_result = os.getenv(ENV_KEY, '')
    if env_result:
        if not os.path.isdir(env_result):
            raise RuntimeError(
                '{} environment variable is set to "{}", but it\'s not a directory'
                .format(ENV_KEY, env_result))
        return env_result

    path = DIR_NAME
    for _ in range(MAX_SEARCH_DEPTH):
        if os.path.isdir(path):
            return path
        path = os.path.join(os.path.pardir, path)

    raise RuntimeError(
        'Can\'t find test data directory. Specify it with {} environment variable (you may need to restart PC) or '
        'start the program with "--test_data_dir <path>" command-line option'.
        format(ENV_KEY))


def filter_bracket_comments(s):
    """
    Serialized type name can contain multiple comments, enclosed into brackets.
    This function removes all such comments.
    """
    bracket_enclosed_comment = r"(\[[^\]]*\])"
    return re.sub(bracket_enclosed_comment, '', s, 0).replace(' ', '')


def invoke_with_timeout(timeout, func):
    """
    Invokes func with a specified timeout.

    If func takes more than timeout seconds to run, TimeoutException is raised.
    If timeout == 0, it simply calls the function.

    :return: whatever func returns
    """
    if timeout == 0:
        # timeout is disabled
        return func()
    else:
        try:
            with futures.ThreadPoolExecutor(max_workers=1) as executor:
                future = executor.submit(func)
                return future.result(timeout=timeout)
        except futures.TimeoutError:
            raise TimeoutException


def completely_sorted(x):
    """Multi-dimensional container sort.

    If x is list of lists of ... of lists,
    then the argument is lexicographically sorted on all levels,
    starting from the bottom.
    """
    if isinstance(x, list):
        return sorted(completely_sorted(e) for e in x)
    else:
        return x


def unordered_compare(a, b):
    """Compares elements of 2 (multi-dimensional) list."""
    return completely_sorted(a) == completely_sorted(b)


def equal_to(a, b):
    """
    Expected value comparator.

    Compares float values with math.isclose(),
    binary trees with equal_binary_trees(),
    and other types with == operator.
    """
    if isinstance(a, float) or isinstance(b, float):
        return math.isclose(a, b)
    import binary_tree_node
    import binary_tree_with_parent_prototype
    import bst_node
    from test_framework.binary_tree_utils import equal_binary_trees
    if (isinstance(a, binary_tree_node.BinaryTreeNode)
            or isinstance(a, binary_tree_with_parent_prototype.BinaryTreeNode)
            or isinstance(a, bst_node.BstNode)) and (
                isinstance(b, binary_tree_node.BinaryTreeNode) or isinstance(
                    b, binary_tree_with_parent_prototype.BinaryTreeNode)
                or isinstance(b, bst_node.BstNode)):
        return equal_binary_trees(a, b)
    return a == b


def has_timer_hook(func):
    return hasattr(func, 'timer_hook') and func.timer_hook


def enable_timer_hook(func):
    func.timer_hook = True
    return func
