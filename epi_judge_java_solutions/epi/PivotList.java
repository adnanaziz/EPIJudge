package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PivotList {

  public static ListNode<Integer> listPivoting(ListNode<Integer> l, int x) {

    ListNode<Integer> lessHead = new ListNode<>(0, null);
    ListNode<Integer> equalHead = new ListNode<>(0, null);
    ListNode<Integer> greaterHead = new ListNode<>(0, null);
    ListNode<Integer> lessIter = lessHead;
    ListNode<Integer> equalIter = equalHead;
    ListNode<Integer> greaterIter = greaterHead;
    // Populates the three lists.
    ListNode<Integer> iter = l;
    while (iter != null) {
      if (iter.data < x) {
        lessIter.next = iter;
        lessIter = iter;
      } else if (iter.data == x) {
        equalIter.next = iter;
        equalIter = iter;
      } else { // iter.data > x.
        greaterIter.next = iter;
        greaterIter = iter;
      }
      iter = iter.next;
    }
    // Combines the three lists.
    greaterIter.next = null;
    equalIter.next = greaterHead.next;
    lessIter.next = equalHead.next;
    return lessHead.next;
  }

  public static List<Integer> linkedToList(ListNode<Integer> l) {
    List<Integer> v = new ArrayList<>();
    while (l != null) {
      v.add(l.data);
      l = l.next;
    }
    return v;
  }

  @EpiTest(testDataFile = "pivot_list.tsv")
  public static void listPivotingWrapper(TimedExecutor executor,
                                         ListNode<Integer> l, int x)
      throws Exception {
    List<Integer> original = linkedToList(l);

    final ListNode<Integer> finalL = l;
    l = executor.run(() -> listPivoting(finalL, x));

    List<Integer> pivoted = linkedToList(l);

    int mode = -1;
    for (Integer i : pivoted) {
      switch (mode) {
      case -1:
        if (i == x) {
          mode = 0;
        } else if (i > x) {
          mode = 1;
        }
        break;
      case 0:
        if (i < x) {
          throw new TestFailure("List is not pivoted");
        } else if (i > x) {
          mode = 1;
        }
        break;
      case 1:
        if (i <= x) {
          throw new TestFailure("List is not pivoted");
        }
      }
    }

    Collections.sort(original);
    Collections.sort(pivoted);
    if (!original.equals(pivoted))
      throw new TestFailure("Result list contains different values");
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "PivotList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
