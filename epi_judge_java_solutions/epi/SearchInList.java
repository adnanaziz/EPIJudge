package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SearchInList {

  public static ListNode<Integer> searchList(ListNode<Integer> L, int key) {

    while (L != null && L.data != key) {
      L = L.next;
    }
    // If key was not present in the list, L will have become null.
    return L;
  }

  @EpiTest(testDataFile = "search_in_list.tsv")
  public static int searchListWrapper(ListNode<Integer> L, int key) {
    ListNode<Integer> result = searchList(L, key);
    return result != null ? result.data : -1;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SearchInList.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
