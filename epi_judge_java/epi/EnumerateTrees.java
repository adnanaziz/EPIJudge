package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.LexicographicalListComparator;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class EnumerateTrees {

  public static List<BinaryTreeNode<Integer>>
  generateAllBinaryTrees(int numNodes) {
    // Implement this placeholder.
    return null;
  }

  public static List<Integer> serializeStructure(BinaryTreeNode<Integer> tree) {
    List<Integer> result = new ArrayList<>();
    Stack<BinaryTreeNode<Integer>> stack = new Stack<>();
    stack.push(tree);
    while (!stack.empty()) {
      BinaryTreeNode<Integer> p = stack.pop();
      result.add(p == null ? 0 : 1);
      if (p != null) {
        stack.push(p.left);
        stack.push(p.right);
      }
    }
    return result;
  }

  @EpiTest(testfile = "enumerate_trees.tsv")
  public static List<List<Integer>>
  generateAllBinaryTreesWrapper(TestTimer timer, int numNodes) {
    timer.start();
    List<BinaryTreeNode<Integer>> result = generateAllBinaryTrees(numNodes);
    timer.stop();

    List<List<Integer>> serialized = new ArrayList<>();
    for (BinaryTreeNode<Integer> x : result) {
      serialized.add(serializeStructure(x));
    }
    serialized.sort(new LexicographicalListComparator<>());
    return serialized;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
