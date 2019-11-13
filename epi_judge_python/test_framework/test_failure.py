from enum import Enum, auto


class PropertyName(Enum):
    EXCEPTION_MESSAGE = auto()  # message of unhandled exception
    EXPLANATION = auto()  # explanation from TSV file
    COMMAND = auto(
    )  # last command, that caused the error, in API-testing programs
    STATE = auto(
    )  # state of the user-defined collection (for instance, in API testing)
    EXPECTED = auto()  # expected result
    RESULT = auto()  # user-produced result
    MISSING_ITEMS = auto(
    )  # list of items from input that are missing in the result set
    EXCESS_ITEMS = auto(
    )  # list of items from result that are missing in the input set
    MISMATCH_INDEX = auto(
    )  # for collections: index of the wrong item in result for binary trees: instance of TreePath describing the position of the wrong item
    EXPECTED_ITEM = auto(
    )  # value of the expected item in collection (not the whole collection)
    RESULT_ITEM = auto(
    )  # value of the result item in collection (not the whole collection)


class Property:
    def __init__(self, name, value):
        self._name = name
        self._value = value

    def name(self):
        return self._name.name.lower().replace('_', ' ')

    def id(self):
        return self._name.value

    def raw_name(self):
        return self._name

    def value(self):
        return self._value


class TestFailure(Exception):
    """
    Tested function may raise this exception
    in order to mark the current test as failed.
    """
    def __init__(self, description=''):
        super().__init__()
        self._properties = []
        self._description = description

    def with_property(self, name, value):
        self._properties.append(Property(name, value))
        return self

    def with_mismatch_info(self, mismatch_index, expected_item, result_item):
        return self\
            .with_property(PropertyName.MISMATCH_INDEX, mismatch_index)\
            .with_property(PropertyName.EXPECTED_ITEM, expected_item)\
            .with_property(PropertyName.RESULT_ITEM, result_item)

    def get_description(self):
        return self._description

    def get_max_property_name_length(self):
        return max((len(prop.name()) for prop in self._properties), default=0)

    def get_properties(self):
        self._properties.sort(key=lambda prop: prop.id())
        return self._properties
