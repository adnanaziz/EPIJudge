package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PivotList {
  public static ListNode<Integer> listPivoting(ListNode<Integer> L, int x) {
    // Implement this placeholder.
    return null;
  }

  public static List<Integer> linkedToList(ListNode<Integer> ll) {
    List<Integer> l = new ArrayList<>();
    while (ll != null) {
      l.add(ll.data);
      ll = ll.next;
    }
    return l;
  }

  @EpiTest(testfile = "pivot_list.tsv")
  public static void listPivotingWrapper(TestTimer timer, ListNode<Integer> ll, int x)
      throws TestFailureException {
    List<Integer> original = linkedToList(ll);

    timer.start();
    ll = listPivoting(ll, x);
    timer.stop();

    List<Integer> pivoted = linkedToList(ll);

    int mode = -1;
    for (Integer i : pivoted) {
      switch (mode) {
        case -1:
          if (i == x)
            mode = 0;
          else if (i > x)
            mode = 1;
          break;
        case 0:
          if (i < x)
            throw new TestFailureException("List is not pivoted");
          else if (i > x)
            mode = 1;
          break;
        case 1:
          if (i <= x)
            throw new TestFailureException("List is not pivoted");
      }
    }

    Collections.sort(original);
    Collections.sort(pivoted);
    if (!original.equals(pivoted))
      throw new TestFailureException("Result list contains different values");
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
