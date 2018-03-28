# @library
from concurrent import futures

from test_framework.test_timer import TestTimer
from test_framework.timeout_exception import TimeoutException


class TimedExecutor:
    def __init__(self, timeout_seconds):
        self._timer = TestTimer()
        self._timeout_seconds = timeout_seconds

    def run(self, func):
        """
        Invokes func with a specified timeout_seconds.

        If func takes more than timeout_seconds seconds to run,
        TimeoutException is raised.
        If timeout_seconds == 0, it simply calls the function.

        :return: whatever func returns
        """
        if self._timeout_seconds == 0:
            self._timer.start()
            result = func()
            self._timer.stop()
            return result
        else:
            try:

                def timed_call(func, timer):
                    timer.start()
                    result = func()
                    timer.stop()
                    return result

                with futures.ThreadPoolExecutor(max_workers=1) as executor:
                    future = executor.submit(timed_call, func, self._timer)
                    return future.result(timeout=self._timeout_seconds)
            except futures.TimeoutError:
                raise TimeoutException(self._timeout_seconds)

    def get_timer(self):
        return self._timer
