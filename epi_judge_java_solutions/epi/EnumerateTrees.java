package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.LexicographicalListComparator;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

public class EnumerateTrees {

  public static List<BinaryTreeNode<Integer>>
  generateAllBinaryTrees(int numNodes) {

    List<BinaryTreeNode<Integer>> result = new ArrayList<>();
    if (numNodes == 0) { // Empty tree, add as an null.
      result.add(null);
    }

    for (int numLeftTreeNodes = 0; numLeftTreeNodes < numNodes;
         ++numLeftTreeNodes) {
      int numRightTreeNodes = numNodes - 1 - numLeftTreeNodes;
      List<BinaryTreeNode<Integer>> leftSubtrees =
          generateAllBinaryTrees(numLeftTreeNodes);
      List<BinaryTreeNode<Integer>> rightSubtrees =
          generateAllBinaryTrees(numNodes - 1 - numLeftTreeNodes);
      // Generates all combinations of leftSubtrees and rightSubtrees.
      for (BinaryTreeNode<Integer> left : leftSubtrees) {
        for (BinaryTreeNode<Integer> right : rightSubtrees) {
          result.add(new BinaryTreeNode<>(0, left, right));
        }
      }
    }
    return result;
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

  @EpiTest(testDataFile = "enumerate_trees.tsv")
  public static List<List<Integer>>
  generateAllBinaryTreesWrapper(TimedExecutor executor, int numNodes)
      throws Exception {
    List<BinaryTreeNode<Integer>> result =
        executor.run(() -> generateAllBinaryTrees(numNodes));

    List<List<Integer>> serialized = new ArrayList<>();
    for (BinaryTreeNode<Integer> x : result) {
      serialized.add(serializeStructure(x));
    }
    serialized.sort(new LexicographicalListComparator<>());
    return serialized;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "EnumerateTrees.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
