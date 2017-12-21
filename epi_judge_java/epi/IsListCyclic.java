package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

public class IsListCyclic {
  public static ListNode<Integer> hasCycle(ListNode<Integer> head) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "is_list_cyclic.tsv")
  public static void HasCycleWrapper(TestTimer timer, ListNode<Integer> head, int cycle_idx)
      throws TestFailureException {
    int cycle_length = 0;
    if (cycle_idx != -1) {
      if (head == null) {
        throw new RuntimeException("Can't cycle empty list");
      }
      ListNode<Integer> cycle_start = null, cursor = head;
      while (cursor.next != null) {
        if (cursor.data == cycle_idx) {
          cycle_start = cursor;
        }
        cursor = cursor.next;
        if (cycle_start != null) {
          cycle_length++;
        }
      }
      if (cursor.data == cycle_idx)
        cycle_start = cursor;
      if (cycle_start == null) {
        throw new RuntimeException("Can't find a cycle start");
      }
      cursor.next = cycle_start;
      cycle_length++;
    }

    timer.start();
    ListNode<Integer> result = hasCycle(head);
    timer.stop();

    if (cycle_idx == -1) {
      if (result != null) {
        throw new TestFailureException("Found a non-existing cycle");
      }
    } else {
      if (result == null) {
        throw new TestFailureException("Existing cycle was not found");
      }

      ListNode<Integer> cursor = result;
      do {
        cursor = cursor.next;
        cycle_length--;
        if (cursor == null || cycle_length < 0) {
          throw new TestFailureException(
              "Returned node does not belong to the cycle or is not the closest node to the head");
        }
      } while (cursor != result);

      if (cycle_length != 0) {
        throw new TestFailureException(
            "Returned node does not belong to the cycle or is not the closest node to the head");
      }
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
