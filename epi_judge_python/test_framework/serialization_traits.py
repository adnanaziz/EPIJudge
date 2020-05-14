import re

from binary_tree_with_parent_prototype import BinaryTreeNode
from list_node import ListNode, list_size
from test_framework.binary_tree_utils import (binary_tree_height,
                                              binary_tree_size)


class SerializationTrait:
    def name(self):
        raise NotImplementedError('Unsupported type')

    def parse(self, arg):
        raise NotImplementedError('Unsupported type')

    def get_metric_names(self, arg_name):
        raise NotImplementedError('Unsupported type')

    def get_metrics(self, x):
        raise NotImplementedError('Unsupported type')

    def is_void(self):
        return False


class VoidTrait(SerializationTrait):
    def name(self):
        return 'void'

    def parse(self, arg):
        raise RuntimeError('Can\'t parse void')

    def get_metric_names(self, arg_name):
        return []

    def get_metrics(self, x):
        return []

    def is_void(self):
        return True


class StringTrait(SerializationTrait):
    def name(self):
        return 'string'

    def parse(self, json_object):
        return str(json_object)

    def get_metric_names(self, arg_name):
        return ['size({})'.format(arg_name)]

    def get_metrics(self, x):
        return [len(x)]


class IntegerTrait(SerializationTrait):
    def name(self):
        return 'int'

    def parse(self, json_object):
        return int(json_object)

    def get_metric_names(self, arg_name):
        return [str(arg_name)]

    def get_metrics(self, x):
        return [abs(int(x))]


class FloatTrait(SerializationTrait):
    def name(self):
        return 'float'

    def parse(self, json_object):
        return float(json_object)

    def get_metric_names(self, arg_name):
        return [str(arg_name)]

    def get_metrics(self, x):
        return [min(2 ^ 32 - 1, abs(float(x)))]


class BooleanTrait(SerializationTrait):
    def name(self):
        return 'bool'

    def parse(self, json_object):
        return bool(json_object)

    def get_metric_names(self, arg_name):
        return []

    def get_metrics(self, x):
        return []


class ListTrait(SerializationTrait):
    def __init__(self, inner_type_trait):
        super().__init__()
        self._inner_type_trait = inner_type_trait

    def name(self):
        return 'array({})'.format(self._inner_type_trait.name())

    def parse(self, json_object):
        return [self._inner_type_trait.parse(inner) for inner in json_object]

    def get_metric_names(self, arg_name):
        return ['size({})'.format(arg_name)]

    def get_metrics(self, x):
        if isinstance(x, list):
            return [len(x)]
        raise RuntimeError('Expected list')

    def get_inner_trait(self):
        return self._inner_type_trait


class BinaryTreeTrait(SerializationTrait):
    def __init__(self, node_type, inner_type_trait):
        super().__init__()
        self._node_type = node_type
        self._inner_type_trait = inner_type_trait

    def name(self):
        return 'binary_tree({})'.format(self._inner_type_trait.name())

    def parse(self, json_object):
        def build_binary_tree(data):
            """A helper function for binary tree parser.

            Constructs a binary tree from an list of keys (and None values).

            :param data - a list of serialized keys.
            """
            nodes = [
                None if node is None else BinaryTreeNode(
                    self._inner_type_trait.parse(node)) for node in data
            ]
            candidate_children = nodes[::-1]
            root = candidate_children.pop()
            for node in nodes:
                if node:
                    if candidate_children:
                        node.left = candidate_children.pop()
                        if node.left is not None:
                            node.left.parent = node
                    if candidate_children:
                        node.right = candidate_children.pop()
                        if node.right is not None:
                            node.right.parent = node
            return root

        return build_binary_tree(json_object)

    def get_metric_names(self, arg_name):
        return ['size({})'.format(arg_name), 'height({})'.format(arg_name)]

    def get_metrics(self, x):
        return [binary_tree_size(x), binary_tree_height(x)]


class LinkedListTrait(SerializationTrait):
    def __init__(self, inner_type_trait):
        super().__init__()
        self._list_trait = ListTrait(inner_type_trait)

    def name(self):
        return 'linked_list({})'.format(
            self._list_trait.get_inner_trait().name())

    def parse(self, json_object):
        parsed = self._list_trait.parse(json_object)
        head = None
        for value in reversed(parsed):
            head = ListNode(value, head)
        return head

    def get_metric_names(self, arg_name):
        return ['size({})'.format(arg_name)]

    def get_metrics(self, x):
        if x is None:
            return [0]
        elif isinstance(x, ListNode):
            return [list_size(x)]
        raise RuntimeError('Expected ListNode')


class SetTrait(SerializationTrait):
    def __init__(self, inner_type_trait):
        super().__init__()
        self._list_trait = ListTrait(inner_type_trait)

    def name(self):
        return 'set({})'.format(self._list_trait.get_inner_trait().name())

    def parse(self, json_object):
        return set(self._list_trait.parse(json_object))

    def get_metric_names(self, arg_name):
        return ['size({})'.format(arg_name)]

    def get_metrics(self, x):
        if isinstance(x, set):
            return [len(x)]
        raise RuntimeError('Expected set')

    # TODO: Custom parser that throws with mismatch info.

    def get_inner_trait(self):
        return self._list_trait.get_inner_trait()


class TupleTrait(SerializationTrait):
    def __init__(self, inner_type_traits):
        super().__init__()
        self._inner_type_traits = inner_type_traits

    def name(self):
        return 'tuple({})'.format(','.join(t.name()
                                           for t in self._inner_type_traits))

    def parse(self, json_object):
        if len(json_object) != len(self._inner_type_traits):
            raise RuntimeError(
                'Tuple parser: expected {} values, provide {}'.format(
                    len(self._inner_type_traits), len(json_object)))
        return tuple(
            inner_type_trait.parse(p) for inner_type_trait, p in zip(
                self._inner_type_traits, json_object))

    def get_metric_names(self, arg_name):
        # TODO: Find how to provide custom metrics.
        return []

    def get_metrics(self, x):
        return []


PRIMITIVE_TYPES_MAPPINGS = {
    'void': VoidTrait,
    'string': StringTrait,
    'int': IntegerTrait,
    'long': IntegerTrait,
    'float': FloatTrait,
    'bool': BooleanTrait
}


def get_trait(typename):
    if typename in PRIMITIVE_TYPES_MAPPINGS:
        return PRIMITIVE_TYPES_MAPPINGS[typename]()

    list_regex = re.compile(r'^array\((.*)\)$')
    m = list_regex.match(typename)
    if m and len(m.groups()) == 1:
        return ListTrait(get_trait(m.group(1)))

    binary_tree_regex = re.compile(r'^binary_tree\((.*)\)$')
    m = binary_tree_regex.match(typename)
    if m and len(m.groups()) == 1:
        return BinaryTreeTrait(BinaryTreeNode, get_trait(m.group(1)))

    linked_list_regex = re.compile(r'^linked_list\((.*)\)$')
    m = linked_list_regex.match(typename)
    if m and len(m.groups()) == 1:
        return LinkedListTrait(get_trait(m.group(1)))

    set_regex = re.compile(r'^set\((.*)\)$')
    m = set_regex.match(typename)
    if m and len(m.groups()) == 1:
        return SetTrait(get_trait(m.group(1)))

    tuple_regex = re.compile(r'^tuple\((.*)\)$')
    m = tuple_regex.match(typename)
    if m and len(m.groups()) == 1:
        return TupleTrait([get_trait(x) for x in m.group(1).split(',')])

    raise NotImplementedError("Unsupported type " + typename)
