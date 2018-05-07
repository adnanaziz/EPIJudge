
import enum


class TestResult(enum.IntEnum):
    PASSED = 0
    FAILED = 1
    TIMEOUT = 2
    UNKNOWN_EXCEPTION = 3
    STACK_OVERFLOW = 4
    RUNTIME_ERROR = 5
