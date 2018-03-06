package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SearchInList {

  public static ListNode<Integer> searchList(ListNode<Integer> L, int key) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "search_in_list.tsv")
  public static int searchListWrapper(ListNode<Integer> L, int key) {
    ListNode<Integer> result = searchList(L, key);
    return result != null ? result.data : -1;
  }

  public static void main(String[] args) {
    // The timeout is set to 15 seconds for each test case.
    // If your program ends with TIMEOUT error, and you want to try longer time
    // limit, you can extend the limit by changing the following line.
    long timeoutSeconds = 15;

    System.exit(
        GenericTest
            .runFromAnnotations(args, timeoutSeconds,
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
