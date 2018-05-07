
package epi.test_framework;

import java.util.Collections;
import java.util.List;

public class TestTimer {
  private long start;
  private long stop;

  public TestTimer() {}

  public TestTimer(long durationMs) {
    stop = System.nanoTime();
    start = stop - durationMs * 1000000;
  }

  public void start() { start = System.nanoTime(); }

  public void stop() {
    if (!stopped()) {
      stop = System.nanoTime();
    }
  }

  public boolean started() { return start != 0; }

  public boolean stopped() { return stop != 0; }

  public long getMicroseconds() {
    final long NANO_TO_MICRO = 1000;
    return (stop - start) / NANO_TO_MICRO;
  }

  public boolean hasValidResult() { return started() && stop != 0; }

  public static String durationToString(long dur) {
    final long MICRO_TO_MILLI = 1000;
    final long MICRO_TO_SECOND = MICRO_TO_MILLI * 1000;
    final String FORMAT = "%4d";

    if (dur == 0) {
      return "  <1 us";
    } else if (dur < MICRO_TO_MILLI) {
      return String.format(FORMAT + " us", dur);
    } else if (dur < MICRO_TO_SECOND) {
      return String.format(FORMAT + " ms", dur / MICRO_TO_MILLI);
    } else {
      return String.format(FORMAT + "  s", dur / MICRO_TO_SECOND);
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
