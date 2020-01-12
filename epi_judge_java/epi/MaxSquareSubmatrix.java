package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class MaxSquareSubmatrix {

  @EpiTest(testDataFile = "max_square_submatrix.tsv")

  public static int maxSquareSubmatrix(List<List<Boolean>> A) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxSquareSubmatrix.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
