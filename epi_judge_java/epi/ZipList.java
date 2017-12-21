package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class ZipList {
  @EpiTest(testfile = "zip_list.tsv")

  public static ListNode<Integer> zippingLinkedList(ListNode<Integer> L) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
