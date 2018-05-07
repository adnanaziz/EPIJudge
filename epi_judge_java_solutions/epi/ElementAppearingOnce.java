package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
import java.util.stream.IntStream;

public class ElementAppearingOnce {
  @EpiTest(testDataFile = "element_appearing_once.tsv")

  public static int findElementAppearsOnce(List<Integer> A) {

    int[] counts = new int[32];
    for (int x : A) {
      for (int i = 0; i < 32; ++i) {
        counts[i] += x & 1;
        x >>= 1;
      }
    }

    return IntStream.range(0, 32).map(i -> (counts[i] % 3) << i).sum();
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ElementAppearingOnce.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
