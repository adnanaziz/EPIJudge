from test_framework.test_timer import TestTimer


class TimeoutException(Exception):
    def __init__(self, timeout_seconds):
        super().__init__()
        self._timer = TestTimer(timeout_seconds)

    def get_timer(self):
        return self._timer
