package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Arrays;
import java.util.List;

public class EvenOddListMerge {
  @EpiTest(testDataFile = "even_odd_list_merge.tsv")

  public static ListNode<Integer> evenOddMerge(ListNode<Integer> L) {

    if (L == null) {
      return L;
    }

    ListNode<Integer> evenDummyHead = new ListNode<>(0, null),
                      oddDummyHead = new ListNode<>(0, null);
    List<ListNode<Integer>> tails = Arrays.asList(evenDummyHead, oddDummyHead);
    int turn = 0;
    for (ListNode<Integer> iter = L; iter != null; iter = iter.next) {
      tails.get(turn).next = iter;
      tails.set(turn, tails.get(turn).next);
      turn ^= 1;
    }
    tails.get(1).next = null;
    tails.get(0).next = oddDummyHead.next;
    return evenDummyHead.next;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "EvenOddListMerge.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
