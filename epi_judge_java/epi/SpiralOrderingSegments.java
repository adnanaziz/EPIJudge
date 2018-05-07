package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import java.util.List;
public class SpiralOrderingSegments {
  @EpiTest(testDataFile = "spiral_ordering_segments.tsv")

  public static List<Integer>
  matrixInSpiralOrder(List<List<Integer>> squareMatrix) {
    // TODO - you fill in here.
    return null;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SpiralOrderingSegments.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
