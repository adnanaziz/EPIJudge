package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.List;

public class SearchEntryEqualToIndex {

  public static int searchEntryEqualToItsIndex(List<Integer> A) {
    // Implement this placeholder.
    return 0;
  }

  @EpiTest(testfile = "search_entry_equal_to_index.tsv")
  public static void searchEntryEqualToItsIndexWrapper(TestTimer timer,
                                                       List<Integer> A)
      throws TestFailureException {
    timer.start();
    int result = searchEntryEqualToItsIndex(A);
    timer.stop();

    if (result != -1) {
      if (A.get(result) != result) {
        throw new TestFailureException("Entry does not equal to its index");
      }
    } else {
      for (int i = 0; i < A.size(); ++i) {
        if (A.get(i) == i) {
          throw new TestFailureException(
              "There are entries which equal to its index");
        }
      }
    }
  }

  public static void main(String[] args) {
    GenericTest.runFromAnnotations(
        args, new Object() {}.getClass().getEnclosingClass());
  }
}
