
package epi.test_framework;

import java.util.Collections;
import java.util.List;

public class TestTimer {
  private long start = 0;
  private long durationUs = 0;

  public TestTimer() {}

  public TestTimer(long durationSeconds) {
    final long SECOND_TO_MICRO = 1000000;
    this.durationUs = durationSeconds * SECOND_TO_MICRO;
  }

  public void start() { start = System.nanoTime(); }

  public void stop() {
    final double NANO_TO_MICRO = 0.001;
    durationUs += (long)((System.nanoTime() - start) * NANO_TO_MICRO);
  }

  public long getMicroseconds() { return durationUs; }

  public static String durationToString(long dur) {
    final long MILLI_TO_MICRO = 1000;
    final long SECOND_TO_MICRO = MILLI_TO_MICRO * 1000;
    final String DURATION_FORMAT = "%4d";

    if (dur == 0) {
      return "  <1 us";
    } else if (dur < MILLI_TO_MICRO) {
      return String.format(DURATION_FORMAT + " us", dur);
    } else if (dur < SECOND_TO_MICRO) {
      return String.format(DURATION_FORMAT + " ms", dur / MILLI_TO_MICRO);
    } else {
      return String.format(DURATION_FORMAT + "  s", dur / SECOND_TO_MICRO);
    }
  }

  public static long[] avgAndMedianFromDuration(List<Long> durations) {
    Collections.sort(durations);
    long avg =
        durations.stream().mapToLong(Long::longValue).sum() / durations.size();
    long median = (durations.size() % 2 == 1)
                      ? durations.get(durations.size() / 2)
                      : (durations.get(durations.size() / 2 - 1) +
                         durations.get(durations.size() / 2)) /
                            2;
    return new long[] {avg, median};
  }
}
