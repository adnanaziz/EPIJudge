package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class TreeLevelOrder {
  @EpiTest(testDataFile = "tree_level_order.tsv")

  public static List<List<Integer>>
  binaryTreeDepthOrder(BinaryTreeNode<Integer> tree) {

    List<List<Integer>> result = new ArrayList<>();
    if (tree == null) {
      return result;
    }

    List<BinaryTreeNode<Integer>> currDepthNodes = List.of(tree);
    while (!currDepthNodes.isEmpty()) {
      result.add(currDepthNodes.stream()
                     .map(curr -> curr.data)
                     .collect(Collectors.toList()));
      currDepthNodes = currDepthNodes.stream()
                           .map(curr -> Arrays.asList(curr.left, curr.right))
                           .flatMap(List::stream)
                           .filter(child -> child != null)
                           .collect(Collectors.toList());
    }
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TreeLevelOrder.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
