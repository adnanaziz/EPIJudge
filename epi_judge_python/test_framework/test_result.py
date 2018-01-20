# @library
import enum


class TestResult(enum.Enum):
    PASSED = 0
    FAILED = 1
    TIMEOUT = 2
    UNKNOWN_EXCEPTION = 3
    STACK_OVERFLOW = 4
