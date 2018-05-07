package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MaxOfSlidingWindow {
  @EpiUserType(ctorParams = {int.class, double.class})

  public static class TrafficElement implements Comparable<TrafficElement> {
    public int time;
    public double volume;

    public TrafficElement(int time, double volume) {
      this.time = time;
      this.volume = volume;
    }

    @Override
    public int compareTo(TrafficElement o) {
      int volumeCmp = Double.compare(volume, o.volume);
      return volumeCmp != 0 ? volumeCmp : time - o.time;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }
      return compareTo((TrafficElement)o) == 0;
    }

    @Override
    public String toString() {
      return "[" + time + ", " + volume + ']';
    }
  }

  @EpiTest(testDataFile = "max_of_sliding_window.tsv")

  public static List<TrafficElement>
  computeTrafficVolumes(List<TrafficElement> A, int w) {

    QueueWithMaxUsingDeque.QueueWithMax<TrafficElement> slidingWindow =
        new QueueWithMaxUsingDeque.QueueWithMax<>();
    List<TrafficElement> maximumVolumes = new ArrayList<>();
    for (TrafficElement trafficInfo : A) {
      slidingWindow.enqueue(trafficInfo);
      while (trafficInfo.time - slidingWindow.head().time > w) {
        slidingWindow.dequeue();
      }
      maximumVolumes.add(
          new TrafficElement(trafficInfo.time, slidingWindow.max().volume));
    }
    return maximumVolumes;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxOfSlidingWindow.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
