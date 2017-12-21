// @library
package epi.test_framework;

public class TestTimer {
  private long start;
  private long stop;
  private static final long NANO_TO_MICRO = 1000;

  public void start() { start = System.nanoTime() / NANO_TO_MICRO; }

  public void stop() {
    if (!stopped()) {
      stop = System.nanoTime() / NANO_TO_MICRO;
    }
  }

  public boolean started() { return start != 0; }

  public boolean stopped() { return stop != 0; }

  public long getMicroseconds() { return stop - start; }

  public boolean hasValidResult() { return started() && stop != 0; }

  public static String durationToString(long dur) {
    final long MICRO_TO_MILLI = 1000;
    final long MICRO_TO_SECOND = 1000000;
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
}
