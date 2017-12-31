package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class ListCyclicRightShift {
  @EpiTest(testfile = "list_cyclic_right_shift.tsv")

  public static ListNode<Integer> cyclicallyRightShiftList(ListNode<Integer> L,
                                                           int k) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
