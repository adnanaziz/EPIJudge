# @library
class TestFailureException(Exception):
    """
    Tested function is allowed to raise this exception
    in order to mark the current test as failed.
    """
    pass
