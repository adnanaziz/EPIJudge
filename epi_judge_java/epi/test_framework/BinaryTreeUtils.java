// @library
package epi.test_framework;

import epi.BstNode;
import epi.BinaryTree;
import epi.BinaryTreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.IdentityHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

public class BinaryTreeUtils {
  private static void treeGenerateHelper(Object tree, List<Object> result,
                                         int order) {
    if (tree != null) {
      if (order == -1) {
        result.add(getData(tree));
      }
      treeGenerateHelper(getLeft(tree), result, order);
      if (order == 0) {
        result.add(getData(tree));
      }
      treeGenerateHelper(getRight(tree), result, order);
      if (order == 1) {
        result.add(getData(tree));
      }
    }
  }

  @SuppressWarnings("unchecked")
  public static <T> List<T> generatePreorder(BinaryTreeNode<T> tree) {
    List<Object> result = new ArrayList<>();
    treeGenerateHelper(tree, result, -1);
    return (List<T>)result;
  }

  @SuppressWarnings("unchecked")
  public static <T> List<T> generateInorder(Object tree) {
    List<Object> result = new ArrayList<>();
    treeGenerateHelper(tree, result, 0);
    return (List<T>)result;
  }

  @SuppressWarnings("unchecked")
  public static <T> List<T> generatePostorder(Object tree) {
    List<Object> result = new ArrayList<>();
    treeGenerateHelper(tree, result, 1);
    return (List<T>)result;
  }

  private static <T> Object findNode(Object node, Object val) {
    if (node != null) {
      if (val.equals(getData(node))) {
        return node;
      }
      Object leftResult = findNode(getLeft(node), val);
      if (leftResult != null) {
        return leftResult;
      }
      Object rightResult = findNode(getRight(node), val);
      if (rightResult != null) {
        return rightResult;
      }
    }
    return null;
  }

  public static <T> T mustFindNode(T node, Object val) {
    @SuppressWarnings("unchecked") T result = (T)findNode(node, val);
    if (result == null) {
      throw new RuntimeException(String.valueOf(val) +
                                 " was not found in the tree");
    }
    return result;
  }

  public static String binaryTreeToString(Object node) {
    StringBuilder result = new StringBuilder();
    Queue<Object> q = new LinkedList<>();
    Set<Object> visited = Collections.newSetFromMap(new IdentityHashMap<>());

    int nullNodesPending = 0;
    boolean first = true;

    result.append("[");
    q.add(node);
    while (!q.isEmpty()) {
      Object n = q.poll();
      if (visited.contains(n)) {
        continue;
      }
      if (n != null) {
        if (first) {
          first = false;
        } else {
          result.append(", ");
        }
        while (nullNodesPending > 0) {
          result.append("null, ");
          nullNodesPending--;
        }
        result.append('"').append(getData(n)).append('"');

        visited.add(n);
        q.add(getLeft(n));
        q.add(getRight(n));
      } else {
        nullNodesPending++;
      }
    }

    result.append("]");
    return result.toString();
  }

  public static <T> int binaryTreeHeight(T tree) {
    if (tree == null) {
      return -1;
    }
    return 1 + Math.max(binaryTreeHeight(getLeft(tree)),
                        binaryTreeHeight(getRight(tree)));
  }

  /**
   * Dirty hacks to overcome the fact that binary tree classes don't have a
   * common interface
   */
  private static Object getData(Object node) {
    if (node == null) {
      return null;
    }
    if (node instanceof BinaryTreeNode) {
      return ((BinaryTreeNode<?>)node).data;
    }
    if (node instanceof BinaryTree) {
      return ((BinaryTree<?>)node).data;
    }
    if (node instanceof BstNode) {
      return ((BstNode<?>)node).data;
    }
    throw new RuntimeException("Unsupported binary tree type " +
                               node.getClass().toString());
  }

  private static Object getLeft(Object node) {
    if (node == null) {
      return null;
    }
    if (node instanceof BinaryTreeNode) {
      return ((BinaryTreeNode<?>)node).left;
    }
    if (node instanceof BinaryTree) {
      return ((BinaryTree<?>)node).left;
    }
    if (node instanceof BstNode) {
      return ((BstNode<?>)node).left;
    }
    throw new RuntimeException("Unsupported binary tree type " +
                               node.getClass().toString());
  }

  private static Object getRight(Object node) {
    if (node == null) {
      return null;
    }
    if (node instanceof BinaryTreeNode) {
      return ((BinaryTreeNode<?>)node).right;
    }
    if (node instanceof BinaryTree) {
      return ((BinaryTree<?>)node).right;
    }
    if (node instanceof BstNode) {
      return ((BstNode<?>)node).right;
    }
    throw new RuntimeException("Unsupported binary tree type " +
                               node.getClass().toString());
  }
}
