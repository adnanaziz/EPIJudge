package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Set;

public class DefectiveJugs {
  @EpiUserType(ctorParams = {int.class, int.class})

  public static class Jug {
    public int low, high;

    public Jug() {}

    public Jug(int low, int high) {
      this.low = low;
      this.high = high;
    }
  }

  private static class VolumeRange {
    public Integer low;
    public Integer high;

    public VolumeRange(Integer low, Integer high) {
      this.low = low;
      this.high = high;
    }

    @Override
    public boolean equals(Object obj) {
      if (obj == null || !(obj instanceof VolumeRange)) {
        return false;
      }
      if (this == obj) {
        return true;
      }
      VolumeRange vr = (VolumeRange)obj;
      return low.equals(vr.low) && high.equals(vr.high);
    }

    @Override
    public int hashCode() {
      return Objects.hash(low, high);
    }
  }

  @EpiTest(testDataFile = "defective_jugs.tsv")

  public static boolean checkFeasible(List<Jug> jugs, int L, int H) {

    return checkFeasibleHelper(jugs, L, H, new HashSet<>());
  }

  private static boolean checkFeasibleHelper(List<Jug> jugs, int L, int H,
                                             Set<VolumeRange> c) {
    if (L > H || c.contains(new VolumeRange(L, H)) || (L < 0 && H < 0)) {
      return false;
    }

    // Checks the volume for each jug to see if it is possible.
    if (jugs.stream().anyMatch(
            j
            -> (L <= j.low && j.high <= H) ||
                   checkFeasibleHelper(jugs, L - j.low, H - j.high, c))) {
      return true;
    }
    c.add(new VolumeRange(L, H)); // Marks this as impossible.
    return false;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DefectiveJugs.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
