
import json
import re

import list_node
from binary_tree_with_parent_prototype import BinaryTreeNode


def get_string_parser_for_type(typename):
    """
    Constructs a string parser for the given type.

    :param typename - string representation of a type from the test data header.
    :return: a functor, that accepts a string and converts it to an instance of the given type.
    """
    if typename == "string":
        return lambda s: str(s)

    if typename == "int" or typename == "long":
        return lambda i: int(i)

    if typename == "float":
        return lambda f: float(f)

    if typename == "bool":
        return lambda b: b.lower() == "true"

    if typename == "void":
        return None

    list_regex = re.compile(r"^array\((.*)\)$")
    m = list_regex.match(typename)
    if m and len(m.groups()) == 1:
        inner_parser = get_object_cast_for_type(m.group(1))

        def list_parse(data):
            parsed = json.loads("{\"data\":" + data + "}")["data"]
            return [inner_parser(x) for x in parsed]

        return list_parse

    bt_regex = re.compile(r"^binary_tree\((.*)\)$")
    m = bt_regex.match(typename)
    if m and len(m.groups()) == 1:
        key_parser = get_string_parser_for_type(m.group(1))
        string_array_parser = get_string_parser_for_type("array(string)")

        def tree_parser(data):
            parsed = string_array_parser(data)
            return build_binary_tree(parsed, key_parser, BinaryTreeNode)

        return tree_parser

    ll_regex = re.compile(r"^linked_list\((.*)\)$")
    m = ll_regex.match(typename)
    if m and len(m.groups()) == 1:
        array_parser = get_string_parser_for_type("array(" + m.group(1) + ")")

        def list_parser(data):
            parsed = array_parser(data)
            return build_linked_list(parsed)

        return list_parser

    set_regex = re.compile(r"^set\((.*)\)$")
    m = set_regex.match(typename)
    if m and len(m.groups()) == 1:
        array_parser = get_string_parser_for_type("array(" + m.group(1) + ")")

        def set_parser(data):
            parsed = array_parser(data)
            return set(parsed)

        return set_parser

    tu_regex = re.compile(r"^tuple\(.*\)$")
    m = tu_regex.match(typename)
    if m:
        json_parser = get_object_cast_for_type(typename)
        return lambda data: json_parser(json.loads(data))

    raise RuntimeError("Unsupported type " + typename)


def get_object_cast_for_type(typename):
    """Constructs a object converter from an object,
       obtained from a JSON parser
       (can be string, int, bool, float, or list)
       to the given type.

        :param typename - string representation of a type
            from the test data header.
        :returns a functor, that accepts an object
        and converts it to an instance of the given type .
    """
    if typename in ["string", "int", "bool", "float"]:
        return lambda x: x  # TODO Type check

    list_regex = re.compile(r"^array\((.*)\)$")
    m = list_regex.match(typename)
    if m and len(m.groups()) == 1:
        inner_cast = get_object_cast_for_type(m.group(1))
        return lambda data: [inner_cast(x) for x in data]

    bt_regex = re.compile(r"^binary_tree\((.*)\)$")
    m = bt_regex.match(typename)
    if m and len(m.groups()) == 1:
        key_parser = get_string_parser_for_type(m.group(1))
        string_array_parser = get_object_cast_for_type("array(string)")

        def tree_parse(data):
            parsed = string_array_parser(data)
            return build_binary_tree(parsed, key_parser, BinaryTreeNode)

        return tree_parse

    ll_regex = re.compile(r"^linked_list\((.*)\)$")
    m = ll_regex.match(typename)
    if m and len(m.groups()) == 1:
        array_parser = get_object_cast_for_type("array(" + m.group(1) + ")")

        def list_parser(data):
            parsed = array_parser(data)
            return build_linked_list(parsed)

        return list_parser

    set_regex = re.compile(r"^set\((.*)\)$")
    m = set_regex.match(typename)
    if m and len(m.groups()) == 1:
        array_parser = get_object_cast_for_type("array(" + m.group(1) + ")")

        def set_parser(data):
            parsed = array_parser(data)
            return set(parsed)

        return set_parser

    tu_regex = re.compile(r"^tuple\((.*)\)$")
    m = tu_regex.match(typename)
    if m and len(m.groups()) == 1:
        # TODO support inner tuples
        parsers = [get_object_cast_for_type(x) for x in m.group(1).split(',')]

        def tuple_parse(data):
            if len(data) != len(parsers):
                raise RuntimeError(
                    "Tuple parser: expected {} values, got {}".format(
                        len(parsers), len(data)))
            return tuple([p(x) for (p, x) in zip(parsers, data)])

        return tuple_parse

    raise RuntimeError("Unsupported type " + typename)


def build_binary_tree(data, key_ctor, node_ctor):
    """A helper function for binary tree parser.

    Constructs a binary tree from an list of keys (and None values).

    :param data - a list of serialized keys.
    :param key_ctor - object converter for key entries.
            Usually is obtained with
            get_object_cast_for_type() function.
    :param node_ctor - tree node constructor,
            that takes node key as a single argument.
    """
    nodes = [
        None if node == 'null' else node_ctor(key_ctor(node)) for node in data
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


def build_linked_list(data):
    """A helper function for linked list parser.

    Constructs a linked list from a list of values.

    :param data - list of values.
    """
    head = None
    for x in reversed(data):
        head = list_node.ListNode(x, head)
    return head
