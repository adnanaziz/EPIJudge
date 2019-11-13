
package epi.test_framework;

import epi.TreeLike;

import java.util.ArrayList;
import java.util.Collections;
import java.util.IdentityHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Objects;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;

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
      List<String> result = new ArrayList<>();
      TreePath node = this;

      while (node != null) {
        result.add(node.toLeft ? "->left" : "->right");
        node = node.prev;
      }

      Collections.reverse(result);
      result.set(0, "root");

      return String.join("", result);
    }
  }

  private static class IntRange {
    private int low;
    private int high;

    public IntRange(int low, int high) {
      this.low = low;
      this.high = high;
    }

    public IntRange() { this(Integer.MIN_VALUE, Integer.MAX_VALUE); }

    public boolean contains(int value) { return low <= value && value <= high; }

    public IntRange limitFromBottom(int newLow) {
      if (newLow > low) {
        return new IntRange(newLow, high);
      } else {
        return this;
      }
    }

    public IntRange limitFromTop(int newHigh) {
      if (newHigh < high) {
        return new IntRange(low, newHigh);
      } else {
        return this;
      }
    }

    @Override
    public String toString() {
      return String.format("range between %d and %d", low, high);
    }
  }

  public static <T> List<T> generatePreorder(TreeLike<T, ?> tree) {
    List<T> result = new ArrayList<>();
    Stack<TreeLike<T, ?>> s = new Stack<>();
    s.push(tree);

    while (!s.empty()) {
      TreeLike<T, ?> node = s.pop();
      if (node == null) {
        continue;
      }

      result.add(node.getData());
      s.push(node.getRight());
      s.push(node.getLeft());
    }

    return result;
  }

  public static <T> List<T> generateInorder(TreeLike<T, ?> tree) {
    List<T> result = new ArrayList<>();
    Stack<TreeLike<T, ?>> s = new Stack<>();
    s.push(tree);
    boolean initial = true;

    if (tree == null) {
      return result;
    }

    while (!s.empty()) {
      TreeLike<T, ?> node = s.pop();

      if (initial) {
        initial = false;
      } else {
        result.add(node.getData());
        node = node.getRight();
      }

      while (node != null) {
        s.push(node);
        node = node.getLeft();
      }
    }

    return result;
  }

  public static <T> List<T> generatePostorder(TreeLike<T, ?> tree) {
    List<T> result = new ArrayList<>();
    Stack<TreeLike<T, ?>> s = new Stack<>();
    s.push(tree);

    while (!s.empty()) {
      TreeLike<T, ?> node = s.pop();
      if (node == null) {
        continue;
      }

      result.add(node.getData());
      s.push(node.getLeft());
      s.push(node.getLeft());
    }

    Collections.reverse(result);

    return result;
  }

  private static <T, Node extends TreeLike<T, Node>> Node findNode(Node node,
                                                                   T val) {
    Stack<Node> s = new Stack<>();
    s.push(node);

    while (!s.empty()) {
      node = s.pop();
      if (node == null) {
        continue;
      }

      if (val.equals(node.getData())) {
        return node;
      }

      s.push(node.getLeft());
      s.push(node.getRight());
    }

    return null;
  }

  public static <T, Node extends TreeLike<T, Node>> Node mustFindNode(Node tree,
                                                                      T val) {
    Node result = findNode(tree, val);
    if (result == null) {
      throw new RuntimeException(String.valueOf(val) +
                                 " was not found in the tree");
    }
    return result;
  }

  private static class TwoNodes<T> {
    public final TreeLike<T, ?> node1;
    public final TreeLike<T, ?> node2;

    public TwoNodes(TreeLike<T, ?> node1, TreeLike<T, ?> node2) {
      this.node1 = node1;
      this.node2 = node2;
    }
  }

  public static <T> boolean equalBinaryTrees(TreeLike<T, ?> tree1,
                                             TreeLike<T, ?> tree2) {
    Stack<TwoNodes<T>> s = new Stack<>();
    s.push(new TwoNodes<>(tree1, tree2));

    while (!s.empty()) {
      TwoNodes<T> nodes = s.pop();

      if ((nodes.node1 == null) != (nodes.node2 == null)) {
        return false;
      }

      if (nodes.node1 != null) {
        if (!Objects.equals(nodes.node1.getData(), nodes.node2.getData())) {
          return false;
        }
        s.push(new TwoNodes<>(nodes.node1.getLeft(), nodes.node2.getLeft()));
        s.push(new TwoNodes<>(nodes.node1.getRight(), nodes.node2.getRight()));
      }
    }

    return true;
  }

  private static class TwoNodesAndPath<T> extends TwoNodes<T> {
    public final TreePath path;

    public TwoNodesAndPath(TreeLike<T, ?> tree1, TreeLike<T, ?> tree2,
                           TreePath path) {
      super(tree1, tree2);
      this.path = path;
    }
  }

  public static <T> void assertEqualBinaryTrees(TreeLike<T, ?> expected,
                                                TreeLike<T, ?> result)
      throws TestFailure {
    Stack<TwoNodesAndPath<T>> s = new Stack<>();
    s.push(new TwoNodesAndPath<>(expected, result, new TreePath()));

    while (!s.empty()) {
      TwoNodesAndPath<T> nodes = s.pop();

      T expectedData = nodes.node1 != null ? nodes.node1.getData() : null;
      T resultData = nodes.node2 != null ? nodes.node2.getData() : null;

      if (!Objects.equals(expectedData, resultData)) {
        throw new TestFailure()
            .withProperty(TestFailure.PropertyName.RESULT, result)
            .withProperty(TestFailure.PropertyName.EXPECTED, expected)
            .withMismatchInfo(nodes.path, expectedData, resultData);
      }
      if (nodes.node1 != null && nodes.node2 != null) {
        s.push(new TwoNodesAndPath<>(nodes.node1.getLeft(),
                                     nodes.node2.getLeft(),
                                     nodes.path.withLeft()));
        s.push(new TwoNodesAndPath<>(nodes.node1.getRight(),
                                     nodes.node2.getRight(),
                                     nodes.path.withRight()));
      }
    }
  }

  private static class TreePathIntRange<T> {
    public final TreeLike<T, ?> tree;
    public final TreePath path;
    public final IntRange range;

    public TreePathIntRange(TreeLike<T, ?> tree, TreePath path,
                            IntRange range) {
      this.tree = tree;
      this.path = path;
      this.range = range;
    }
  }

  public static void assertTreeIsBst(TreeLike<Integer, ?> tree)
      throws TestFailure {
    Stack<TreePathIntRange<Integer>> s = new Stack<>();
    s.push(new TreePathIntRange<>(tree, new TreePath(), new IntRange()));

    while (!s.empty()) {
      TreePathIntRange<Integer> node = s.pop();
      if (node.tree == null) {
        continue;
      }

      Integer value = node.tree.getData();

      if (!node.range.contains(value)) {
        throw new TestFailure("Binary search tree constraints violation")
            .withProperty(TestFailure.PropertyName.RESULT, tree)
            .withMismatchInfo(node.path, "Value in " + node.range.toString(),
                              value);
      }
      s.push(new TreePathIntRange<>(node.tree.getLeft(), node.path.withLeft(),
                                    node.range.limitFromTop(value)));
      s.push(new TreePathIntRange<>(node.tree.getRight(), node.path.withRight(),
                                    node.range.limitFromBottom(value)));
    }
  }

  public static <T> String binaryTreeToString(TreeLike<T, ?> tree) {
    StringBuilder result = new StringBuilder();
    Queue<TreeLike<T, ?>> nodes = new LinkedList<>();
    Set<TreeLike<T, ?>> visited =
        Collections.newSetFromMap(new IdentityHashMap<>());
    boolean first = true;
    int nullNodesPending = 0;

    result.append("[");
    nodes.add(tree);

    while (!nodes.isEmpty()) {
      TreeLike<T, ?> node = nodes.poll();
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

        result.append('"').append(node.getData()).append('"');

        visited.add(node);
        nodes.add(node.getLeft());
        nodes.add(node.getRight());
      } else {
        nullNodesPending++;
      }
    }

    result.append("]");
    return result.toString();
  }

  private static class TreeInteger<T> {
    public final TreeLike<T, ?> tree;
    public final Integer height;

    public TreeInteger(TreeLike<T, ?> tree, Integer height) {
      this.tree = tree;
      this.height = height;
    }
  }

  public static <T> int binaryTreeHeight(TreeLike<T, ?> tree) {
    Stack<TreeInteger<T>> s = new Stack<>();
    s.push(new TreeInteger<>(tree, 1));
    int height = 0;

    while (!s.empty()) {
      TreeInteger<T> node = s.pop();
      if (node.tree == null) {
        continue;
      }

      height = Integer.max(height, node.height);
      s.push(new TreeInteger<>(node.tree.getLeft(), node.height + 1));
      s.push(new TreeInteger<>(node.tree.getRight(), node.height + 1));
    }

    return height;
  }

  public static <T> int binaryTreeSize(TreeLike<T, ?> tree) {
    Stack<TreeLike<T, ?>> s = new Stack<>();
    s.push(tree);
    int size = 0;

    while (!s.empty()) {
      TreeLike<T, ?> node = s.pop();
      if (node == null) {
        continue;
      }

      size++;
      s.push(node.getLeft());
      s.push(node.getRight());
    }

    return size;
  }

  public static <T> int binaryTreeHash(TreeLike<T, ?> tree) {
    int EMPTY_NODE_HASH = 1000003; // Some random prime
    int result = 0;
    Stack<TreeLike<T, ?>> s = new Stack<>();
    s.push(tree);

    while (!s.empty()) {
      TreeLike<T, ?> node = s.pop();
      if (node == null) {
        result = Objects.hash(result, EMPTY_NODE_HASH);
        continue;
      }

      result = Objects.hash(result, node.getData());
      s.push(node.getRight());
      s.push(node.getLeft());
    }

    return result;
  }
}