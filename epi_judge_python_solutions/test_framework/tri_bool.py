
from enum import Enum, auto


class TriBool(Enum):
    FALSE = auto()
    TRUE = auto()
    INDETERMINATE = auto()

    def get_or_default(self, default_value):
        if self == self.FALSE:
            return False
        if self == self.TRUE:
            return True
        else:
            return default_value
