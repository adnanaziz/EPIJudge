package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.HashSet;
import java.util.Set;

public class DoListsOverlap {

  public static ListNode<Integer> overlappingLists(ListNode<Integer> l0,
                                                   ListNode<Integer> l1) {

    // Store the start of cycle if any.
    ListNode<Integer> root0 = IsListCyclic.hasCycle(l0);
    ListNode<Integer> root1 = IsListCyclic.hasCycle(l1);

    if (root0 == null && root1 == null) {
      // Both lists don't have cycles.
      return DoTerminatedListsOverlap.overlappingNoCycleLists(l0, l1);
    } else if ((root0 != null && root1 == null) ||
               (root0 == null && root1 != null)) {
      // One list has cycle, and one list has no cycle.
      return null;
    }
    // Both lists have cycles.
    ListNode<Integer> temp = root1;
    do {
      temp = temp.next;
    } while (temp != root0 && temp != root1);

    // l0 and l1 do not end in the same cycle.
    if (temp != root0) {
      return null; // Cycles are disjoint.
    }

    // l0 and l1 end in the same cycle, locate the overlapping node if they
    // first overlap before cycle starts.
    int stem0Length = distance(l0, root0), stem1Length = distance(l1, root1);
    if (stem0Length > stem1Length) {
      l0 = DoTerminatedListsOverlap.advanceListByK(stem0Length - stem1Length,
                                                   l0);
    } else {
      l1 = DoTerminatedListsOverlap.advanceListByK(stem1Length - stem0Length,
                                                   l1);
    }
    while (l0 != l1 && l0 != root0 && l1 != root1) {
      l0 = l0.next;
      l1 = l1.next;
    }

    // If l0 == l1 before reaching root0, it means the overlap first occurs
    // before the cycle starts; otherwise, the first overlapping node is not
    // unique, so we can return any node on the cycle.
    return l0 == l1 ? l0 : root0;
  }

  // Calculates the distance between a and b.
  private static int distance(ListNode<Integer> a, ListNode<Integer> b) {
    int dis = 0;
    while (a != b) {
      a = a.next;
      ++dis;
    }
    return dis;
  }

  @EpiTest(testDataFile = "do_lists_overlap.tsv")
  public static void
  overlappingListsWrapper(TimedExecutor executor, ListNode<Integer> l0,
                          ListNode<Integer> l1, ListNode<Integer> common,
                          int cycle0, int cycle1) throws Exception {
    if (common != null) {
      if (l0 == null) {
        l0 = common;
      } else {
        ListNode<Integer> it = l0;
        while (it.next != null) {
          it = it.next;
        }
        it.next = common;
      }

      if (l1 == null) {
        l1 = common;
      } else {
        ListNode<Integer> it = l1;
        while (it.next != null) {
          it = it.next;
        }
        it.next = common;
      }
    }

    if (cycle0 != -1 && l0 != null) {
      ListNode<Integer> last = l0;
      while (last.next != null) {
        last = last.next;
      }
      ListNode<Integer> it = l0;
      while (cycle0-- > 0) {
        if (it == null) {
          throw new RuntimeException("Invalid input data");
        }
        it = it.next;
      }
      last.next = it;
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

    Set<Integer> commonNodes = new HashSet<>();
    ListNode<Integer> it = common;
    while (it != null && !commonNodes.contains(it.data)) {
      commonNodes.add(it.data);
      it = it.next;
    }

    final ListNode<Integer> finalL0 = l0;
    final ListNode<Integer> finalL1 = l1;
    ListNode<Integer> result =
        executor.run(() -> overlappingLists(finalL0, finalL1));

    if (!((commonNodes.isEmpty() && result == null) ||
          (result != null && commonNodes.contains(result.data)))) {
      throw new TestFailure("Invalid result");
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DoListsOverlap.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
