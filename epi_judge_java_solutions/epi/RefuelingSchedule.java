package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class RefuelingSchedule {
  private static class CityAndRemainingGas {
    public Integer city;
    public Integer remainingGallons;

    public CityAndRemainingGas(Integer city, Integer remainingGallons) {
      this.city = city;
      this.remainingGallons = remainingGallons;
    }
  }

  private static final int MPG = 20;

  @EpiTest(testfile = "refueling_schedule.tsv")
  // gallons[i] is the amount of gas in city i, and distances[i] is the distance
  // city i to the next city.
  public static int findAmpleCity(List<Integer> gallons,
                                  List<Integer> distances) {
    int remainingGallons = 0;
    CityAndRemainingGas min = new CityAndRemainingGas(0, 0);
    final int numCities = gallons.size();
    for (int i = 1; i < numCities; ++i) {
      remainingGallons += gallons.get(i - 1) - distances.get(i - 1) / MPG;
      if (remainingGallons < min.remainingGallons) {
        min = new CityAndRemainingGas(i, remainingGallons);
      }
    }
    return min.city;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
