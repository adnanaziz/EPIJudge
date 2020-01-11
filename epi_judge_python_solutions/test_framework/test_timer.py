import statistics
import time


class TestTimer:
    SECOND_TO_MICRO = 1000000

    def __init__(self, duration_seconds=None):
        self._start = 0
        self._duration_us = 0 if duration_seconds is None else duration_seconds * TestTimer.SECOND_TO_MICRO

    def start(self):
        self._start = time.perf_counter()

    def stop(self):
        self._duration_us += (time.perf_counter() -
                              self._start) * TestTimer.SECOND_TO_MICRO

    def get_microseconds(self):
        return self._duration_us


def duration_to_string(dur):
    dur = int(dur)
    milli_to_micro = 1000
    second_to_micro = milli_to_micro * 1000
    duration_format = '{:>4}'

    if dur == 0:
        return '  <1 us'
    elif dur < milli_to_micro:
        return str(duration_format + ' us').format(dur)
    elif dur < second_to_micro:
        return str(duration_format + ' ms').format(dur // milli_to_micro)
    return str(duration_format + '  s').format(dur // second_to_micro)


def avg_and_median_from_durations(durations):
    return statistics.mean(durations), statistics.median(durations)
