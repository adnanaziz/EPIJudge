package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class KLargestValuesInBst {
  @EpiTest(testDataFile = "k_largest_values_in_bst.tsv")

  public static List<Integer> findKLargestInBst(BstNode<Integer> tree, int k) {

    List<Integer> kLargestElements = new ArrayList<>();
    findKLargestInBstHelper(tree, k, kLargestElements);
    return kLargestElements;
  }

  private static void findKLargestInBstHelper(BstNode<Integer> tree, int k,
                                              List<Integer> kLargestElements) {
    // Perform reverse inorder traversal.
    if (tree != null && kLargestElements.size() < k) {
      findKLargestInBstHelper(tree.right, k, kLargestElements);
      if (kLargestElements.size() < k) {
        kLargestElements.add(tree.data);
        findKLargestInBstHelper(tree.left, k, kLargestElements);
      }
    }
  }

  @EpiTestComparator
  public static boolean comp(List<Integer> expected, List<Integer> result) {
    if (result == null) {
      return false;
    }
    Collections.sort(expected);
    Collections.sort(result);
    return expected.equals(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "KLargestValuesInBst.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
