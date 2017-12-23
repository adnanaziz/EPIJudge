// @library
package epi.test_framework;

import epi.BstNode;
import epi.BinaryTree;
import epi.BinaryTreeNode;
import epi.ListNode;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Map;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class TestUtilsDeserialization {
  /**
   * Mappings for trivial types
   */
  private static final Map<Type, String> TYPE_NAME_MAPPING;
  private static final Map<Type, Function<String, Object>> TYPE_PARSER_MAPPING;
  private static final Map<Type, Function<JsonValue, Object>>
      TYPE_JSON_PARSER_MAPPING;

  static {
    Map<Type, String> tn = new HashMap<Type, String>() {
      {
        put(String.class, "string");
        put(Integer.class, "int");
        put(int.class, "int");
        put(Short.class, "int");
        put(short.class, "int");
        put(Long.class, "long");
        put(long.class, "long");
        put(Character.class, "string");
        put(char.class, "string");
        put(Boolean.class, "bool");
        put(boolean.class, "bool");
        put(Float.class, "float");
        put(float.class, "float");
        put(Double.class, "float");
        put(double.class, "float");
      }
    };
    TYPE_NAME_MAPPING = tn;

    Map<Type, Function<String, Object>> tp =
        new HashMap<Type, Function<String, Object>>() {
          {
            put(String.class, (String s) -> s);
            put(Integer.class, Integer::parseInt);
            put(int.class, Integer::parseInt);
            put(Short.class, Short::parseShort);
            put(short.class, Short::parseShort);
            put(Long.class, Long::parseLong);
            put(long.class, Long::parseLong);
            put(Character.class, TestUtilsDeserialization::stringToChar);
            put(char.class, TestUtilsDeserialization::stringToChar);
            put(Boolean.class, Boolean::parseBoolean);
            put(boolean.class, Boolean::parseBoolean);
            put(Float.class, Float::parseFloat);
            put(float.class, Float::parseFloat);
            put(Double.class, Double::parseDouble);
            put(double.class, Double::parseDouble);
          }
        };
    TYPE_PARSER_MAPPING = tp;

    Map<Type, Function<JsonValue, Object>> tj =
        new HashMap<Type, Function<JsonValue, Object>>() {
          {
            put(String.class, JsonValue::asString);
            put(Integer.class, JsonValue::asInt);
            put(int.class, JsonValue::asInt);
            put(Short.class, (JsonValue o) -> (short)o.asInt());
            put(short.class, (JsonValue o) -> (short)o.asInt());
            put(Long.class, JsonValue::asLong);
            put(long.class, JsonValue::asLong);
            put(Character.class, (JsonValue o) -> stringToChar(o.asString()));
            put(char.class, (JsonValue o) -> stringToChar(o.asString()));
            put(Boolean.class, JsonValue::asBoolean);
            put(boolean.class, JsonValue::asBoolean);
            put(Float.class, JsonValue::asFloat);
            put(float.class, JsonValue::asFloat);
            put(Double.class, JsonValue::asDouble);
            put(double.class, JsonValue::asDouble);
          }
        };
    TYPE_JSON_PARSER_MAPPING = tj;
  }

  /**
   * Helper method used in Character parsers.
   *
   * @param s - a string containing exactly 1 character.
   */
  private static Character stringToChar(String s) {
    if (s.length() != 1) {
      throw new RuntimeException("Char parser: string length is not 1");
    }
    return s.charAt(0);
  }

  /**
   * Converts a Type object to its string representation that conforms to the
   * one, used in the test data header.
   */
  @SuppressWarnings("unchecked")
  private static String getSerializedTypeName(Type declaredType) {
    if (declaredType.equals(Void.TYPE)) {
      return "void";
    }
    if (declaredType instanceof ParameterizedType) {
      ParameterizedType pt = (ParameterizedType)declaredType;
      if (pt.getRawType().equals(List.class)) {
        return "array(" + getSerializedTypeName(getInnerGenericType(pt, 0)) +
            ")";
      }
      if (pt.getRawType().equals(Iterable.class)) {
        return "array(" + getSerializedTypeName(getInnerGenericType(pt, 0)) +
            ")";
      }
      if (pt.getRawType().equals(Set.class)) {
        return "set(" + getSerializedTypeName(getInnerGenericType(pt, 0)) + ")";
      }
      if (pt.getRawType().equals(BinaryTreeNode.class)) {
        return "binary_tree(" +
            getSerializedTypeName(getInnerGenericType(pt, 0)) + ")";
      }
      if (pt.getRawType().equals(BinaryTree.class)) {
        return "binary_tree(" +
            getSerializedTypeName(getInnerGenericType(pt, 0)) + ")";
      }
      if (pt.getRawType().equals(BstNode.class)) {
        return "binary_tree(" +
            getSerializedTypeName(getInnerGenericType(pt, 0)) + ")";
      }
      if (pt.getRawType().equals(ListNode.class)) {
        return "linked_list(" +
            getSerializedTypeName(getInnerGenericType(pt, 0)) + ")";
      }
    }

    String mapped = TYPE_NAME_MAPPING.get(declaredType);
    if (mapped != null) {
      return mapped;
    }

    if (declaredType instanceof Class) {
      EpiUserType ann =
          (EpiUserType)((Class)declaredType).getAnnotation(EpiUserType.class);
      if (ann != null) {
        StringBuilder sb = new StringBuilder();
        sb.append("tuple(");
        boolean first = true;
        for (Class<?> c : ann.ctorParams()) {
          if (first) {
            first = false;
          } else {
            sb.append(",");
          }
          sb.append(getSerializedTypeName(c));
        }
        sb.append(")");
        return sb.toString();
      }
    }

    throw new RuntimeException("Unsupported argument type: " +
                               declaredType.getTypeName());
  }

  /**
   * A small snippet that makes it easier to obtain a certain generic argument
   * from the provided type.
   *
   * @param type - generic type. Must be ParametrizedType.
   * @param idx  - index of the desired generic argument. Bound-checking is not
   *             performed.
   * @warning type must be obtained directly from the method reflexion with
   * getGeneric*() methods. For instance, List.class is a generic type, but it
   * carries no information about its generic argument.
   */
  private static Type getInnerGenericType(Type type, int idx) {
    if (type instanceof ParameterizedType) {
      return ((ParameterizedType)type).getActualTypeArguments()[idx];
    } else {
      throw new RuntimeException(type.getTypeName() +
                                 " has no generic type arguments");
    }
  }

  /**
   * This method compares the provided type with its serialized representation
   * from the test data header.
   */
  static boolean matchArgumentType(Type declaredType, String serializedType) {
    String mapped = getSerializedTypeName(declaredType);
    return mapped.equals(serializedType);
  }

  /**
   * This method converts a (probably) generic type to a list, consisting of the
   * type and its generic arguments. Examples: Integer is converted to {Integer}
   * List(List(Integer)) is converted to {List, List, Integer}
   */
  static List<Class<?>> linearizeType(Type type) {
    List<Class<?>> result = new ArrayList<>();
    while (true) {
      if (type.equals(Void.TYPE)) {
        break;
      }
      if (type instanceof ParameterizedType) {
        ParameterizedType pt = (ParameterizedType)type;
        if (pt.getRawType().equals(List.class)) {
          result.add(List.class);
          type = getInnerGenericType(pt, 0);
          continue;
        } else if (pt.getRawType().equals(Iterable.class)) {
          result.add(List.class);
          type = getInnerGenericType(pt, 0);
          continue;
        } else if (pt.getRawType().equals(Set.class)) {
          result.add(Set.class);
          type = getInnerGenericType(pt, 0);
          continue;
        } else if (pt.getRawType().equals(BinaryTreeNode.class)) {
          result.add(
              BinaryTreeNode.class);  // Code repetition due to complications
          // in casting ParametrizedType to Class
          type = getInnerGenericType(pt, 0);
          continue;
        } else if (pt.getRawType().equals(BinaryTree.class)) {
          result.add(BinaryTree.class);
          type = getInnerGenericType(pt, 0);
          continue;
        } else if (pt.getRawType().equals(BstNode.class)) {
          result.add(BstNode.class);
          type = getInnerGenericType(pt, 0);
          continue;
        } else if (pt.getRawType().equals(ListNode.class)) {
          result.add(ListNode.class);
          type = getInnerGenericType(pt, 0);
          continue;
        } else {
          throw new RuntimeException("Unsupported generic type " +
                                     type.getTypeName());
        }
      } else if (type instanceof Class) {
        result.add((Class<?>)type);
        break;
      } else {
        throw new RuntimeException("Unsupported type " + type.getTypeName());
      }
    }
    return result;
  }

  /**
   * Creates the string deserializer for the specific type.
   *
   * @param types - list of types, obtained from {@link #linearizeType(Type)}
   */
  @SuppressWarnings("unchecked")
  static Function<String, Object> getTypeParser(List<Class<?>> types) {
    if (types.isEmpty()) {
      return null;  // Void parser
    }

    Function<String, Object> parser = TYPE_PARSER_MAPPING.get(types.get(0));
    if (parser != null) {
      return parser;
    }

    if (types.get(0).equals(List.class)) {
      return getListParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(Set.class)) {
      return getSetParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(BinaryTreeNode.class)) {
      return getBinaryTreeNodeParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(BinaryTree.class)) {
      return getBinaryTreeParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(BstNode.class)) {
      return getBstNodeParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(ListNode.class)) {
      return getLinkedListParser(types.subList(1, types.size()));
    }

    EpiUserType ann = types.get(0).getAnnotation(EpiUserType.class);
    if (ann != null) {
      return getTupleParser(types.get(0), ann.ctorParams());
    }

    throw new RuntimeException("Unsupported parameter type: " +
                               types.get(0).getTypeName());
  }

  /**
   * Creates the string converter from JsonValue to the specific type
   *
   * @param types - list of types, obtained from {@link #linearizeType(Type)}
   */
  @SuppressWarnings("unchecked")
  private static Function<JsonValue, Object> getArgumentJsonParser(
      List<Class<?>> types) {
    if (types.isEmpty()) {
      throw new RuntimeException("Incomplete type list");
    }

    Function<JsonValue, Object> parser =
        TYPE_JSON_PARSER_MAPPING.get(types.get(0));
    if (parser != null) {
      return parser;
    }

    if (types.get(0).equals(List.class)) {
      return getListJsonParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(Set.class)) {
      return getSetJsonParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(BinaryTreeNode.class)) {
      return getBinaryTreeNodeJsonParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(BinaryTree.class)) {
      return getBinaryTreeJsonParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(BstNode.class)) {
      return getBstNodeJsonParser(types.subList(1, types.size()));
    }

    if (types.get(0).equals(ListNode.class)) {
      return getLinkedListJsonParser(types.subList(1, types.size()));
    }

    EpiUserType ann = types.get(0).getAnnotation(EpiUserType.class);
    if (ann != null) {
      return getTupleJsonParser(types.get(0), ann.ctorParams());
    }

    throw new RuntimeException("Unsupported argument type: " +
                               types.get(0).getTypeName());
  }

  /**
   * This method constructs a parser that converts a list of values (encoded as
   * a JSON array) into an instance of userType object.
   *
   * @param userType   - the user type that will be created by the parser.
   * @param ctorParams - a list of types that matches the serialized data.
   *                   userType is required to have a constructor with matching
   *                   set of arguments. Generics arguments are not supported.
   */
  private static Function<String, Object> getTupleParser(
      Class<?> userType, Class<?>[] ctorParams) {
    Function<JsonValue, Object> jsonParser =
        getTupleJsonParser(userType, ctorParams);
    return (String s) -> jsonParser.apply(Json.parse(s));
  }

  /**
   * This method constructs a parser that converts a a JSON array into an
   * instance of userType object.
   *
   * @see #getTupleParser(Class, Class[])
   */
  @SuppressWarnings("unchecked")
  private static Function<JsonValue, Object> getTupleJsonParser(
      Class<?> userType, Class<?>[] ctorParams) {
    try {
      Function<JsonValue, Object>[] paramParsers =
          new Function[ctorParams.length];
      for (int i = 0; i < ctorParams.length; i++) {
        paramParsers[i] =
            getArgumentJsonParser(Collections.singletonList(ctorParams[i]));
      }

      Constructor<?> ctor = userType.getDeclaredConstructor(ctorParams);

      return jsonValue -> {
        JsonArray a = jsonValue.asArray();
        if (a.size() != ctorParams.length) {
          throw new RuntimeException(
              "Tuple parser: expected " + String.valueOf(ctorParams.length) +
              " values, provided " + String.valueOf(a.size()));
        }
        Object[] params = new Object[ctorParams.length];
        for (int i = 0; i < ctorParams.length; i++) {
          params[i] = paramParsers[i].apply(a.get(i));
        }
        try {
          return ctor.newInstance(params);
        } catch (InstantiationException | IllegalAccessException |
                 InvocationTargetException e) {
          throw new RuntimeException("Tuple parser: " + e.getMessage());
        }
      };
    } catch (NoSuchMethodException e) {
      throw new RuntimeException(userType.getTypeName() +
                                 " does not have a ctor from " +
                                 ctorParams.toString());
    }
  }

  /**
   * Helper method for binary tree parser.
   */
  private static Function<String, Object> getBinaryTreeNodeParser(
      List<Class<?>> inner) {
    Function<JsonValue, Object> jsonParser = getBinaryTreeNodeJsonParser(inner);
    return (String s) -> jsonParser.apply(Json.parse(s));
  }

  /**
   * Helper method for binary tree parser.
   */
  private static Function<JsonValue, Object> getBinaryTreeNodeJsonParser(
      List<Class<?>> inner) {
    Function<String, Object> keyParser = getTypeParser(inner);
    return (JsonValue v) -> buildBinaryTreeNode(v, keyParser);
  }

  /**
   * Builds a binary tree from a JSON array, where all keys are encoded as
   * strings.
   */
  public static Object buildBinaryTreeNode(JsonValue data,
                                           Function<String, Object> keyParser) {
    List<BinaryTreeNode<Object>> nodes = new LinkedList<>();
    for (JsonValue s : data.asArray()) {
      if (s.asString().equals("null")) {
        nodes.add(null);
      } else {
        nodes.add(new BinaryTreeNode<>(keyParser.apply(s.asString())));
      }
    }
    Deque<BinaryTreeNode<Object>> candidateChildren = new LinkedList<>(nodes);
    BinaryTreeNode<Object> root = candidateChildren.removeFirst();
    for (BinaryTreeNode<Object> node : nodes) {
      if (node != null) {
        if (!candidateChildren.isEmpty()) {
          node.left = candidateChildren.removeFirst();
        }
        if (!candidateChildren.isEmpty()) {
          node.right = candidateChildren.removeFirst();
        }
      }
    }
    return root;
  }

  /**
   * @see #getBinaryTreeNodeParser(List)
   */
  private static Function<String, Object> getBinaryTreeParser(
      List<Class<?>> inner) {
    Function<JsonValue, Object> jsonParser = getBinaryTreeJsonParser(inner);
    return (String s) -> jsonParser.apply(Json.parse(s));
  }

  /**
   * @see #getBinaryTreeNodeJsonParser(List)
   */
  private static Function<JsonValue, Object> getBinaryTreeJsonParser(
      List<Class<?>> inner) {
    Function<String, Object> keyParser = getTypeParser(inner);
    return (JsonValue v) -> buildBinaryTree(v, keyParser);
  }

  /**
   * @see #buildBinaryTreeNode(JsonValue, Function)
   */
  public static Object buildBinaryTree(JsonValue data,
                                       Function<String, Object> keyParser) {
    List<BinaryTree<Object>> nodes = new LinkedList<>();
    for (JsonValue s : data.asArray()) {
      if (s.asString().equals("null")) {
        nodes.add(null);
      } else {
        nodes.add(new BinaryTree<>(keyParser.apply(s.asString())));
      }
    }
    Deque<BinaryTree<Object>> candidateChildren = new LinkedList<>(nodes);
    BinaryTree<Object> root = candidateChildren.removeFirst();
    for (BinaryTree<Object> node : nodes) {
      if (node != null) {
        if (!candidateChildren.isEmpty()) {
          node.left = candidateChildren.removeFirst();
          if (node.left != null) node.left.parent = node;
        }
        if (!candidateChildren.isEmpty()) {
          node.right = candidateChildren.removeFirst();
          if (node.right != null) node.right.parent = node;
        }
      }
    }
    return root;
  }

  /**
   * @see #getBinaryTreeNodeParser(List)
   */
  private static Function<String, Object> getBstNodeParser(
      List<Class<?>> inner) {
    Function<JsonValue, Object> jsonParser = getBstNodeJsonParser(inner);
    return (String s) -> jsonParser.apply(Json.parse(s));
  }

  /**
   * @see #getBinaryTreeNodeJsonParser(List)
   */
  private static Function<JsonValue, Object> getBstNodeJsonParser(
      List<Class<?>> inner) {
    Function<String, Object> keyParser = getTypeParser(inner);
    return (JsonValue v) -> buildBstNode(v, keyParser);
  }

  /**
   * @see #buildBinaryTreeNode(JsonValue, Function)
   */
  private static Object buildBstNode(JsonValue data,
                                     Function<String, Object> keyParser) {
    List<BstNode<Object>> nodes = new LinkedList<>();
    for (JsonValue s : data.asArray()) {
      if (s.asString().equals("null")) {
        nodes.add(null);
      } else {
        nodes.add(new BstNode<>(keyParser.apply(s.asString())));
      }
    }
    Deque<BstNode<Object>> candidateChildren = new LinkedList<>(nodes);
    BstNode<Object> root = candidateChildren.removeFirst();
    for (BstNode<Object> node : nodes) {
      if (node != null) {
        if (!candidateChildren.isEmpty()) {
          node.left = candidateChildren.removeFirst();
        }
        if (!candidateChildren.isEmpty()) {
          node.right = candidateChildren.removeFirst();
        }
      }
    }
    return root;
  }

  /**
   * Returns a parser that converts a String to {@link LinkedList} object.
   *
   * @param inner - the type of {@link LinkedList generic argument.
   */
  private static Function<String, Object> getLinkedListParser(
      List<Class<?>> inner) {
    Function<JsonValue, Object> jsonParser = getLinkedListJsonParser(inner);
    return (String s) -> jsonParser.apply(Json.parse(s));
  }

  /**
   * Returns a parser that converts a JsonArray to a {@link LinkedList object.
   *
   * @param inner - the type of {@link LinkedList generic argument.
   */
  private static Function<JsonValue, Object> getLinkedListJsonParser(
      List<Class<?>> inner) {
    Function<JsonValue, Object> valueParser = getArgumentJsonParser(inner);
    return (JsonValue v) -> buildLinkedList(v, valueParser);
  }

  /**
   * Helper function for parsing linked lists
   *
   * @param a           - JSON array of linked list nodes
   * @param valueParser - functor, used to convert entries in JsonArray to the
   *                    corresponding objects
   */
  private static Object buildLinkedList(
      JsonValue a, Function<JsonValue, Object> valueParser) {
    ListNode<Object> head = null;
    List<JsonValue> values = a.asArray().values();
    ListIterator<JsonValue> valuesIt = values.listIterator(values.size());
    while (valuesIt.hasPrevious()) {
      head = new ListNode<>(valueParser.apply(valuesIt.previous()), head);
    }
    return head;
  }

  /**
   * Returns a parser that converts a String to a List object
   *
   * @param inner - the type of List generic argument
   */
  private static Function<String, Object> getListParser(List<Class<?>> inner) {
    Function<JsonValue, Object> jsonParser = getListJsonParser(inner);
    return (String s) -> jsonParser.apply(Json.parse(s));
  }

  /**
   * Returns a parser that converts a JsonArray to a List object
   *
   * @param inner - the type of List generic argument
   */
  private static Function<JsonValue, Object> getListJsonParser(
      List<Class<?>> inner) {
    Function<JsonValue, Object> innerParser = getArgumentJsonParser(inner);

    return (JsonValue v)
               -> StreamSupport.stream(v.asArray().spliterator(), false)
                      .map(innerParser)
                      .collect(Collectors.toList());
  }

  /**
   * Returns a parser that converts a String to a Set object
   *
   * @param inner - the type of Set generic argument
   */
  @SuppressWarnings("unchecked")
  private static Function<String, Object> getSetParser(List<Class<?>> inner) {
    Function<String, Object> listParser = getListParser(inner);
    return (String s) -> new HashSet<>((List<Object>)(listParser.apply(s)));
  }

  /**
   * Returns a parser that converts a JsonArray to a Set object
   *
   * @param inner - the type of Set generic argument
   */
  @SuppressWarnings("unchecked")
  private static Function<JsonValue, Object> getSetJsonParser(
      List<Class<?>> inner) {
    Function<JsonValue, Object> listParser = getListJsonParser(inner);
    return (JsonValue o) -> new HashSet<>((List<Object>)(listParser.apply(o)));
  }
}
