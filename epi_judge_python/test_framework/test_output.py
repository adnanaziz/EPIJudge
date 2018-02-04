# @library
class TestOutput:
    EMPTY_OBJECT = object()

    # For distinguishing between None (returned by user code) and empty value

    def __init__(self,
                 comparison_result,
                 timer,
                 expected=EMPTY_OBJECT,
                 result=EMPTY_OBJECT):
        self.comparison_result = comparison_result
        self.timer = timer
        self.expected = expected
        self.result = result
