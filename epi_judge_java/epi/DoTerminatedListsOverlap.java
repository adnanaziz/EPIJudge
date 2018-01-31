package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

public class DoTerminatedListsOverlap {

  public static ListNode<Integer>
  overlappingNoCycleLists(ListNode<Integer> l0, ListNode<Integer> l1) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "do_terminated_lists_overlap.tsv")
  public static void
  overlappingNoCycleListsWrapper(TestTimer timer, ListNode<Integer> l0,
                                 ListNode<Integer> l1, ListNode<Integer> common)
      throws TestFailureException {
    if (common != null) {
      if (l0 != null) {
        ListNode<Integer> i = l0;
        while (i.next != null) {
          i = i.next;
        }
        i.next = common;
      } else {
        l0 = common;
      }

      if (l1 != null) {
        ListNode<Integer> i = l1;
        while (i.next != null) {
          i = i.next;
        }
        i.next = common;
      } else {
        l1 = common;
      }
    }

    timer.start();
    ListNode<Integer> result = overlappingNoCycleLists(l0, l1);
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
