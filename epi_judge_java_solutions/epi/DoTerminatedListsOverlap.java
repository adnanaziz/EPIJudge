package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

public class DoTerminatedListsOverlap {

  public static ListNode<Integer>
  overlappingNoCycleLists(ListNode<Integer> l0, ListNode<Integer> l1) {

    int l0Length = length(l0), l1Length = length(l1);

    // Advances the longer list to get equal length lists.
    if (l0Length > l1Length) {
      l0 = advanceListByK(l0Length - l1Length, l0);
    } else {
      l1 = advanceListByK(l1Length - l0Length, l1);
    }

    while (l0 != null && l1 != null && l0 != l1) {
      l0 = l0.next;
      l1 = l1.next;
    }
    return l0; // nullptr implies there is no overlap between l0 and l1.
  }

  public static ListNode<Integer> advanceListByK(int k, ListNode<Integer> l) {
    while (k-- > 0) {
      l = l.next;
    }
    return l;
  }

  private static int length(ListNode<Integer> l) {
    int length = 0;
    while (l != null) {
      ++length;
      l = l.next;
    }
    return length;
  }

  @EpiTest(testDataFile = "do_terminated_lists_overlap.tsv")
  public static void
  overlappingNoCycleListsWrapper(TimedExecutor executor, ListNode<Integer> l0,
                                 ListNode<Integer> l1, ListNode<Integer> common)
      throws Exception {
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

    final ListNode<Integer> finalL0 = l0;
    final ListNode<Integer> finalL1 = l1;
    ListNode<Integer> result =
        executor.run(() -> overlappingNoCycleLists(finalL0, finalL1));

    if (result != common) {
      throw new TestFailure("Invalid result");
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DoTerminatedListsOverlap.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
