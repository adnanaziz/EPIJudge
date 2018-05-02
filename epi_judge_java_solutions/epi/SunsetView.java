package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;
import java.util.List;
import java.util.stream.Collectors;

public class SunsetView {

  private static class BuildingWithHeight {
    public Integer id;
    public Integer height;

    public BuildingWithHeight(Integer id, Integer height) {
      this.id = id;
      this.height = height;
    }
  }

  public static List<Integer>
  examineBuildingsWithSunset(Iterator<Integer> sequence) {

    int buildingIdx = 0;
    Deque<BuildingWithHeight> candidates = new ArrayDeque<>();
    while (sequence.hasNext()) {
      Integer buildingHeight = sequence.next();
      while (!candidates.isEmpty() &&
             (Integer.compare(buildingHeight, candidates.peekFirst().height) >=
              0)) {
        candidates.removeFirst();
      }
      candidates.addFirst(
          new BuildingWithHeight(buildingIdx++, buildingHeight));
    }
    return candidates.stream().map(c -> c.id).collect(Collectors.toList());
  }

  @EpiTest(testDataFile = "sunset_view.tsv")
  public static List<Integer>
  examineBuildingsWithSunsetWrapper(List<Integer> sequence) {
    return examineBuildingsWithSunset(sequence.iterator());
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SunsetView.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
