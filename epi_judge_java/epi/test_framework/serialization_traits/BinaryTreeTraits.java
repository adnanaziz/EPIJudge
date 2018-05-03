
package epi.test_framework.serialization_traits;

import epi.BinaryTree;
import epi.BinaryTreeNode;
import epi.BstNode;
import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.minimal_json.Json;
import epi.test_framework.minimal_json.JsonArray;
import epi.test_framework.minimal_json.JsonValue;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class BinaryTreeTraits extends SerializationTraits {
  private Class<?> nodeType;
  private SerializationTraits innerTypeTraits;

  public BinaryTreeTraits(Class<?> nodeType,
                          SerializationTraits innerTypeTraits) {
    this.nodeType = nodeType;
    this.innerTypeTraits = innerTypeTraits;
  }

  @Override
  public String name() {
    return String.format("binary_tree(%s)", innerTypeTraits.name());
  }

  @Override
  public Object parse(String str) {
    return jsonParse(Json.parse(str));
  }

  @Override
  public Object jsonParse(JsonValue jsonObject) {
    if (!jsonObject.isArray()) {
      throw new RuntimeException("Binary Tree parser: expected JSON array");
    }

    if (nodeType.equals(BinaryTreeNode.class)) {
      return buildBinaryTreeNode(jsonObject.asArray());
    } else if (nodeType.equals(BinaryTree.class)) {
      return buildBinaryTree(jsonObject.asArray());
    } else if (nodeType.equals(BstNode.class)) {
      return buildBstNode(jsonObject.asArray());
    } else {
      throw new RuntimeException(
          String.format("Binary Tree parser: %s class is not supported",
                        nodeType.toString()));
    }
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Arrays.asList(String.format("size(%s)", argName),
                         String.format("height(%s)", argName));
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    return Arrays.asList(BinaryTreeUtils.binaryTreeSize(x),
                         BinaryTreeUtils.binaryTreeHeight(x));
  }

  private Object buildBinaryTreeNode(JsonArray data) {
    List<BinaryTreeNode<Object>> nodes = new LinkedList<>();
    for (JsonValue s : data) {
      if (!s.isString()) {
        throw new RuntimeException("Binary Tree parser: expected JSON string");
      }
      if (s.asString().equals("null")) {
        nodes.add(null);
      } else {
        nodes.add(new BinaryTreeNode<>(innerTypeTraits.parse(s.asString())));
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

  private Object buildBinaryTree(JsonArray data) {
    List<BinaryTree<Object>> nodes = new LinkedList<>();

    for (JsonValue s : data) {
      if (!s.isString()) {
        throw new RuntimeException("Binary Tree parser: expected JSON string");
      }
      if (s.asString().equals("null")) {
        nodes.add(null);
      } else {
        nodes.add(new BinaryTree<>(innerTypeTraits.parse(s.asString())));
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

  private Object buildBstNode(JsonArray data) {
    List<BstNode<Object>> nodes = new LinkedList<>();

    for (JsonValue s : data) {
      if (!s.isString()) {
        throw new RuntimeException("Binary Tree parser: expected JSON string");
      }
      if (s.asString().equals("null")) {
        nodes.add(null);
      } else {
        nodes.add(new BstNode<>(innerTypeTraits.parse(s.asString())));
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
}
