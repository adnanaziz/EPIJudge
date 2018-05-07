package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class BstMerge {
  @EpiTest(testDataFile = "bst_merge.tsv")

  public static BstNode<Integer> mergeTwoBsts(BstNode<Integer> A,
                                              BstNode<Integer> B) {
    // TODO - you fill in here.
    return null;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "BstMerge.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
