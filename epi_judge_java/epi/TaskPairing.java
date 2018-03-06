package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.List;

public class TaskPairing {
  @EpiUserType(ctorParams = {Integer.class, Integer.class})

  public static class PairedTasks {
    public Integer task1;
    public Integer task2;

    public PairedTasks(Integer task1, Integer task2) {
      this.task1 = task1;
      this.task2 = task2;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      PairedTasks that = (PairedTasks)o;

      return task1.equals(that.task1) && task2.equals(that.task2);
    }

    @Override
    public String toString() {
      return "[" + task1 + ", " + task2 + "]";
    }
  }

  @EpiTest(testfile = "task_pairing.tsv")

  public static List<PairedTasks>
  optimumTaskAssignment(List<Integer> taskDurations) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    // The timeout is set to 15 seconds for each test case.
    // If your program ends with TIMEOUT error, and you want to try longer time
    // limit, you can extend the limit by changing the following line.
    long timeoutSeconds = 15;

    System.exit(
        GenericTest
            .runFromAnnotations(args, timeoutSeconds,
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
