import time


class TestTimer:
    _start = 0
    _stop = 0

    def start(self):
        self._start = time.perf_counter()

    def stop(self):
        if not self.stopped():
            self._stop = time.perf_counter()

    def started(self):
        return self._start != 0

    def stopped(self):
        return self._stop != 0

    def get_microseconds(self):
        return int((self._stop - self._start) * 1000000)

    def has_valid_result(self):
        return self.started() and self._stop != 0


def duration_to_string(dur):
    dur = int(dur)
    MICRO_TO_MILLI = 1000
    MICRO_TO_SECOND = 1000000
    FORMAT = '{:>4}'
    if dur == 0:
        return '  <1 us'
    elif dur < MICRO_TO_MILLI:
        return str(FORMAT + ' us').format(dur)
    elif dur < MICRO_TO_SECOND:
        return str(FORMAT + ' ms').format(dur // MICRO_TO_MILLI)
    else:
        return str(FORMAT + '  s').format(dur // MICRO_TO_SECOND)
