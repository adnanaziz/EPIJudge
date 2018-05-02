package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Iterator;
import java.util.List;

public class MajorityElement {

  public static String majoritySearch(Iterator<String> stream) {

    String candidate = "";
    int candidateCount = 0;
    while (stream.hasNext()) {
      String it = stream.next();
      if (candidateCount == 0) {
        candidate = it;
        candidateCount = 1;
      } else if (candidate.equals(it)) {
        ++candidateCount;
      } else {
        --candidateCount;
      }
    }
    return candidate;
  }

  @EpiTest(testDataFile = "majority_element.tsv")
  public static String majoritySearchWrapper(List<String> stream) {
    return majoritySearch(stream.iterator());
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MajorityElement.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
