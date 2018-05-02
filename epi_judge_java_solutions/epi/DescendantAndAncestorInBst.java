package epi;

import epi.test_framework.BinaryTreeUtils;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

public class DescendantAndAncestorInBst {

  public static boolean
  pairIncludesAncestorAndDescendantOfM(BstNode<Integer> possibleAncOrDesc0,
                                       BstNode<Integer> possibleAncOrDesc1,
                                       BstNode<Integer> middle) {

    BstNode<Integer> search0 = possibleAncOrDesc0, search1 = possibleAncOrDesc1;

    // Perform interleaved searching from possibleAncOrDesc0 and
    // possibleAncOrDesc1 for middle.
    while (search0 != possibleAncOrDesc1 && search0 != middle &&
           search1 != possibleAncOrDesc0 && search1 != middle &&
           (search0 != null || search1 != null)) {
      if (search0 != null) {
        search0 = search0.data > middle.data ? search0.left : search0.right;
      }
      if (search1 != null) {
        search1 = search1.data > middle.data ? search1.left : search1.right;
      }
    }

    // If both searches were unsuccessful, or we got from possibleAncOrDesc0
    // to possibleAncOrDesc1 without seeing middle, or from possibleAncOrDesc1
    // to possibleAncOrDesc0 without seeing middle, middle cannot lie between
    // possibleAncOrDesc0 and possibleAncOrDesc1.
    if (search0 == possibleAncOrDesc1 || search1 == possibleAncOrDesc0 ||
        (search0 != middle && search1 != middle)) {
      return false;
    }

    // If we get here, we already know one of possibleAncOrDesc0 or
    // possibleAncOrDesc1 has a path to middle. Check if middle has a path to
    // possibleAncOrDesc1 or to possibleAncOrDesc0.
    return search0 == middle ? searchTarget(middle, possibleAncOrDesc1)
                             : searchTarget(middle, possibleAncOrDesc0);
  }

  private static boolean searchTarget(BstNode<Integer> from,
                                      BstNode<Integer> target) {
    while (from != null && from != target) {
      from = from.data > target.data ? from.left : from.right;
    }
    return from == target;
  }

  @EpiTest(testDataFile = "descendant_and_ancestor_in_bst.tsv")
  public static boolean pairIncludesAncestorAndDescendantOfMWrapper(
      TimedExecutor executor, BstNode<Integer> tree, int possibleAncOrDesc0,
      int possibleAncOrDesc1, int middle) throws Exception {
    final BstNode<Integer> candidate0 =
        BinaryTreeUtils.mustFindNode(tree, possibleAncOrDesc0);
    final BstNode<Integer> candidate1 =
        BinaryTreeUtils.mustFindNode(tree, possibleAncOrDesc1);
    final BstNode<Integer> middleNode =
        BinaryTreeUtils.mustFindNode(tree, middle);

    return executor.run(()
                            -> pairIncludesAncestorAndDescendantOfM(
                                candidate0, candidate1, middleNode));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DescendantAndAncestorInBst.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
