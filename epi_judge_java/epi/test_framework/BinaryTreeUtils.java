
package epi.test_framework;

import epi.BinaryTree;
import epi.BinaryTreeNode;
import epi.BstNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.IdentityHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Objects;
import java.util.Set;

public class BinaryTreeUtils {
  public static class TreePath {
    private TreePath prev;
    private boolean toLeft;

    public TreePath() {}

    private TreePath(TreePath prev, boolean toLeft) {
      this.prev = prev;
      this.toLeft = toLeft;
    }

    public TreePath withLeft() { return new TreePath(this, true); }

    public TreePath withRight() { return new TreePath(this, false); }

    @Override
    public String toString() {
      if (prev == null) {
        return "root";
      }

      return prev.toString() + (toLeft ? "->left" : "->right");
    }
  }

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
  public static <Node> List<Node> generatePreorder(Object tree) {
    List<Object> result = new ArrayList<>();
    treeGenerateHelper(tree, result, -1);
    return (List<Node>)result;
  }

  @SuppressWarnings("unchecked")
  public static <Node> List<Node> generateInorder(Object tree) {
    List<Object> result = new ArrayList<>();
    treeGenerateHelper(tree, result, 0);
    return (List<Node>)result;
  }

  @SuppressWarnings("unchecked")
  public static <Node> List<Node> generatePostorder(Object tree) {
    List<Object> result = new ArrayList<>();
    treeGenerateHelper(tree, result, 1);
    return (List<Node>)result;
  }

  private static Object findNode(Object node, Object val) {
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

  public static <Node> Node mustFindNode(Node tree, Object val) {
    @SuppressWarnings("unchecked") Node result = (Node)findNode(tree, val);
    if (result == null) {
      throw new RuntimeException(String.valueOf(val) +
                                 " was not found in the tree");
    }
    return result;
  }

  public static boolean isObjectTreeType(Object tree) {
    return tree != null &&
        (tree instanceof BinaryTree || tree instanceof BinaryTreeNode ||
         tree instanceof BstNode);
  }

  public static boolean equalBinaryTrees(Object node1, Object node2) {
    if (node1 != null && node2 != null) {
      return Objects.equals(getData(node1), getData(node2)) &&
          equalBinaryTrees(getLeft(node1), getLeft(node2)) &&
          equalBinaryTrees(getRight(node1), getRight(node2));
    } else {
      return node1 == null && node2 == null;
    }
  }

  public static void assertEqualBinaryTrees(Object expected, Object result)
      throws TestFailure {
    try {
      assertEqualBinaryTreesImpl(expected, result, new TreePath());
    } catch (TestFailure e) {
      throw e.withProperty(TestFailure.PropertyName.EXPECTED, expected)
          .withProperty(TestFailure.PropertyName.RESULT, result);
    }
  }

  private static void assertEqualBinaryTreesImpl(Object expected, Object result,
                                                 TreePath path)
      throws TestFailure {
    Object expectedData = getData(expected);
    Object resultData = getData(result);
    if (!Objects.equals(expectedData, resultData)) {
      throw new TestFailure().withMismatchInfo(path, expectedData, resultData);
    }
    if (expected != null && result != null) {
      assertEqualBinaryTreesImpl(getLeft(expected), getLeft(result),
                                 path.withLeft());
      assertEqualBinaryTreesImpl(getRight(expected), getRight(result),
                                 path.withRight());
    }
  }

  public static void assertTreeIsBst(Object tree) throws TestFailure {
    try {
      assertTreeIsBstImpl(tree, new TreePath(), Integer.MIN_VALUE,
                          Integer.MAX_VALUE);
    } catch (TestFailure e) {
      throw e.withProperty(TestFailure.PropertyName.RESULT, tree);
    }
  }

  private static void assertTreeIsBstImpl(Object node, TreePath path, int min,
                                          int max) throws TestFailure {
    if (node == null) {
      return;
    }

    Object data = getData(node);
    if (!(data instanceof Integer)) {
      throw new RuntimeException("Only integer keys are supported");
    }

    @SuppressWarnings("unchecked") int value = (Integer)data;
    if (value < min || value > max) {
      throw new TestFailure("Binary search tree constraints violation")
          .withMismatchInfo(
              path, String.format("Value between %d and %d", min, max), value);
    }
    assertTreeIsBstImpl(getLeft(node), path.withLeft(), min, value);
    assertTreeIsBstImpl(getRight(node), path.withRight(), value, max);
  }

  public static String binaryTreeToString(Object tree) {
    StringBuilder result = new StringBuilder();
    Queue<Object> q = new LinkedList<>();
    Set<Object> visited = Collections.newSetFromMap(new IdentityHashMap<>());
    boolean first = true;
    int nullNodesPending = 0;

    result.append("[");
    q.add(tree);

    while (!q.isEmpty()) {
      Object node = q.poll();
      if (visited.contains(node)) {
        throw new RuntimeException("Detected a cycle in the tree");
      }
      if (node != null) {
        if (first) {
          first = false;
        } else {
          result.append(", ");
        }

        while (nullNodesPending > 0) {
          result.append("null, ");
          nullNodesPending--;
        }

        result.append('"').append(getData(node)).append('"');

        visited.add(node);
        q.add(getLeft(node));
        q.add(getRight(node));
      } else {
        nullNodesPending++;
      }
    }

    result.append("]");
    return result.toString();
  }

  public static <Node> int binaryTreeHeight(Node tree) {
    if (tree == null) {
      return -1;
    }
    return 1 + Math.max(binaryTreeHeight(getLeft(tree)),
                        binaryTreeHeight(getRight(tree)));
  }

  public static <Node> int binaryTreeSize(Node tree) {
    if (tree == null) {
      return 0;
    }

    return 1 + binaryTreeSize(getLeft(tree)) + binaryTreeSize(getRight(tree));
  }

  // Java framework specific methods

  /**
   * Dirty hacks to overcome the fact that binary tree classes don't have a
   * common interface
   */
  private static Object getData(Object tree) {
    if (tree == null) {
      return null;
    }
    if (tree instanceof BinaryTreeNode) {
      return ((BinaryTreeNode<?>)tree).data;
    }
    if (tree instanceof BinaryTree) {
      return ((BinaryTree<?>)tree).data;
    }
    if (tree instanceof BstNode) {
      return ((BstNode<?>)tree).data;
    }
    throw new RuntimeException("Unsupported binary tree type: " +
                               tree.getClass().getName());
  }

  private static Object getLeft(Object tree) {
    if (tree == null) {
      return null;
    }
    if (tree instanceof BinaryTreeNode) {
      return ((BinaryTreeNode<?>)tree).left;
    }
    if (tree instanceof BinaryTree) {
      return ((BinaryTree<?>)tree).left;
    }
    if (tree instanceof BstNode) {
      return ((BstNode<?>)tree).left;
    }
    throw new RuntimeException("Unsupported binary tree type: " +
                               tree.getClass().getName());
  }

  private static Object getRight(Object tree) {
    if (tree == null) {
      return null;
    }
    if (tree instanceof BinaryTreeNode) {
      return ((BinaryTreeNode<?>)tree).right;
    }
    if (tree instanceof BinaryTree) {
      return ((BinaryTree<?>)tree).right;
    }
    if (tree instanceof BstNode) {
      return ((BstNode<?>)tree).right;
    }
    throw new RuntimeException("Unsupported binary tree type: " +
                               tree.getClass().getName());
  }
}
