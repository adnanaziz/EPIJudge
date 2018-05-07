
from test_framework.test_timer import TestTimer


class TimeoutException(Exception):
    def __init__(self, duration_ms):
        self._timer = TestTimer(duration_ms)

    def get_timer(self):
        return self._timer
