package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class ZipList {
  @EpiTest(testDataFile = "zip_list.tsv")

  public static ListNode<Integer> zippingLinkedList(ListNode<Integer> L) {
    // TODO - you fill in here.
    return null;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ZipList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
