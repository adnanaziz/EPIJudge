
package epi.test_framework;

public class TimeoutException extends Exception {
  private TestTimer timer;

  TimeoutException(long durationMs) { timer = new TestTimer(durationMs); }

  TestTimer getTimer() { return timer; }
}
