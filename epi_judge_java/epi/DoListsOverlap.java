package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.HashSet;
import java.util.Set;

public class DoListsOverlap {

  public static ListNode<Integer> overlappingLists(ListNode<Integer> L1,
                                                   ListNode<Integer> L2) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "do_lists_overlap.tsv")
  public static void
  overlappingListsWrapper(TestTimer timer, ListNode<Integer> l1,
                          ListNode<Integer> l2, ListNode<Integer> common,
                          int cycle1, int cycle2) throws TestFailureException {
    if (common != null) {
      if (l1 == null) {
        l1 = common;
      } else {
        ListNode<Integer> it = l1;
        while (it.next != null) {
          it = it.next;
        }
        it.next = common;
      }

      if (l2 == null) {
        l2 = common;
      } else {
        ListNode<Integer> it = l2;
        while (it.next != null) {
          it = it.next;
        }
        it.next = common;
      }
    }

    if (cycle1 != -1 && l1 != null) {
      ListNode<Integer> last = l1;
      while (last.next != null) {
        last = last.next;
      }
      ListNode<Integer> it = l1;
      while (cycle1-- > 0) {
        if (it == null) {
          throw new RuntimeException("Invalid input data");
        }
        it = it.next;
      }
      last.next = it;
    }

    if (cycle2 != -1 && l2 != null) {
      ListNode<Integer> last = l2;
      while (last.next != null) {
        last = last.next;
      }
      ListNode<Integer> it = l2;
      while (cycle2-- > 0) {
        if (it == null) {
          throw new RuntimeException("Invalid input data");
        }
        it = it.next;
      }
      last.next = it;
    }

    Set<Integer> commonNodes = new HashSet<>();
    ListNode<Integer> it = common;
    while (it != null && !commonNodes.contains(it.data)) {
      commonNodes.add(it.data);
      it = it.next;
    }

    timer.start();
    ListNode<Integer> result = overlappingLists(l1, l2);
    timer.stop();

    if (!((commonNodes.isEmpty() && result == null) ||
          (result != null && commonNodes.contains(result.data)))) {
      throw new TestFailureException("Invalid result");
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
