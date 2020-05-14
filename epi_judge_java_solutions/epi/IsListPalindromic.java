package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class IsListPalindromic {
  @EpiTest(testDataFile = "is_list_palindromic.tsv")

  public static boolean isLinkedListAPalindrome(ListNode<Integer> L) {

    // Finds the second half of L.
    ListNode<Integer> slow = L, fast = L;
    while (fast != null && fast.next != null) {
      fast = fast.next.next;
      slow = slow.next;
    }

    // Compare the first half and the reversed second half lists.
    ListNode<Integer> firstHalfIter = L;
    ListNode<Integer> secondHalfIter = ReverseList.reverseList(slow);
    while (secondHalfIter != null && firstHalfIter != null) {
      if (!secondHalfIter.data.equals(firstHalfIter.data)) {
        return false;
      }
      secondHalfIter = secondHalfIter.next;
      firstHalfIter = firstHalfIter.next;
    }
    return true;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IsListPalindromic.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
