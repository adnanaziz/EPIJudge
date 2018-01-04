package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

public class DoTerminatedListsOverlap {

  public static ListNode<Integer>
  overlappingNoCycleLists(ListNode<Integer> L1, ListNode<Integer> L2) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "do_terminated_lists_overlap.tsv")
  public static void
  overlappingNoCycleListsWrapper(TestTimer timer, ListNode<Integer> p1,
                                 ListNode<Integer> p2, ListNode<Integer> common)
      throws TestFailureException {
    if (common != null) {
      if (p1 != null) {
        ListNode<Integer> i = p1;
        while (i.next != null) {
          i = i.next;
        }
        i.next = common;
      } else {
        p1 = common;
      }

      if (p2 != null) {
        ListNode<Integer> i = p2;
        while (i.next != null) {
          i = i.next;
        }
        i.next = common;
      } else {
        p2 = common;
      }
    }

    timer.start();
    ListNode<Integer> result = overlappingNoCycleLists(p1, p2);
    timer.stop();

    if (result != common) {
      throw new TestFailureException("Invalid result");
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
