
package epi.test_framework.serialization_traits;

import epi.BinaryTree;
import epi.BinaryTreeNode;
import epi.BstNode;
import epi.TreeLike;
import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.minimal_json.JsonArray;
import epi.test_framework.minimal_json.JsonValue;

import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class BinaryTreeTrait extends SerializationTrait {
  private Class<?> nodeType;
  private SerializationTrait innerTypeTrait;

  public BinaryTreeTrait(Class<?> nodeType, SerializationTrait innerTypeTrait) {
    this.nodeType = nodeType;
    this.innerTypeTrait = innerTypeTrait;
  }

  @Override
  public String name() {
    return String.format("binary_tree(%s)", innerTypeTrait.name());
  }

  @Override
  public Object parse(JsonValue jsonObject) {
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
  @SuppressWarnings("unchecked")
  public List<Integer> getMetrics(Object x) {
    return List.of(BinaryTreeUtils.binaryTreeSize((TreeLike<Object, ?>)x),
                   BinaryTreeUtils.binaryTreeHeight((TreeLike<Object, ?>)x));
  }

  private Object buildBinaryTreeNode(JsonArray data) {
    List<BinaryTreeNode<Object>> nodes = new LinkedList<>();
    for (JsonValue node : data) {
      nodes.add(node.isNull()
                    ? null
                    : new BinaryTreeNode<>(innerTypeTrait.parse(node)));
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
    for (JsonValue node : data) {
      nodes.add(node.isNull() ? null
                              : new BinaryTree<>(innerTypeTrait.parse(node)));
    }

    Deque<BinaryTree<Object>> candidateChildren = new LinkedList<>(nodes);
    BinaryTree<Object> root = candidateChildren.removeFirst();
    for (BinaryTree<Object> node : nodes) {
      if (node != null) {
        if (!candidateChildren.isEmpty()) {
          node.left = candidateChildren.removeFirst();
          if (node.left != null) {
            node.left.parent = node;
          }
        }
        if (!candidateChildren.isEmpty()) {
          node.right = candidateChildren.removeFirst();
          if (node.right != null) {
            node.right.parent = node;
          }
        }
      }
    }
    return root;
  }

  private Object buildBstNode(JsonArray data) {
    List<BstNode<Object>> nodes = new LinkedList<>();
    for (JsonValue node : data) {
      nodes.add(node.isNull() ? null
                              : new BstNode<>(innerTypeTrait.parse(node)));
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
