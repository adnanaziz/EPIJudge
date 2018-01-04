package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class RoadNetwork {
  @EpiUserType(ctorParams = {int.class, int.class, int.class})

  public static class HighwaySection {
    public int x, y, distance;

    public HighwaySection(int x, int y, int distance) {
      this.x = x;
      this.y = y;
      this.distance = distance;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      HighwaySection that = (HighwaySection)o;
      return x == that.x && y == that.y && distance == that.distance;
    }

    @Override
    public String toString() {
      return "[" + x + ", " + y + ", " + distance + "]";
    }
  }

  @EpiTest(testfile = "road_network.tsv")

  public static HighwaySection
  findBestProposals(List<HighwaySection> H, List<HighwaySection> P, int n) {
    // Implement this placeholder.
    return new HighwaySection(0, 0, 0);
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
