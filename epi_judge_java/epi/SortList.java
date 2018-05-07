package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class SortList {
  @EpiTest(testDataFile = "sort_list.tsv")

  public static ListNode<Integer> stableSortList(ListNode<Integer> L) {
    // TODO - you fill in here.
    return null;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SortList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
