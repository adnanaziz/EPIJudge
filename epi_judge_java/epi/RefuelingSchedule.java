package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class RefuelingSchedule {

  @EpiTest(testfile = "refueling_schedule.tsv")
  // gallons[i] is the amount of gas in city i, and distances[i] is the distance
  // city i to the next city.
  public static int findAmpleCity(List<Integer> gallons,
                                  List<Integer> distances) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
