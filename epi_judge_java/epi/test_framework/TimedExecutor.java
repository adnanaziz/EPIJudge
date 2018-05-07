
package epi.test_framework;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class TimedExecutor {
  private TestTimer timer;
  private long timeoutSeconds;

  public TimedExecutor(long timeoutSeconds) {
    this.timer = new TestTimer();
    this.timeoutSeconds = timeoutSeconds;
  }

  /**
   * Invokes func with a specified timeoutSeconds.
   * If func takes more than timeoutSeconds seconds to run,
   * TimeoutException is thrown.
   * If timeoutSeconds == 0, it simply calls the function.
   *
   * @return whatever func returns
   */
  public <ReturnType> ReturnType run(Callable<ReturnType> func)
      throws Exception {
    if (timeoutSeconds == 0) {
      // Timeout is disabled.
      return timedCall(func);
    } else {
      try {
        final ExecutorService executor = Executors.newSingleThreadExecutor();
        final Future<ReturnType> future =
            executor.submit(() -> { return timedCall(func); });

        // This does not cancel the already-scheduled task.
        executor.shutdown();

        return future.get(timeoutSeconds, TimeUnit.SECONDS);

      } catch (java.util.concurrent.TimeoutException e) {
        throw new epi.test_framework.TimeoutException(timeoutSeconds);
      } catch (InterruptedException e) {
        throw new RuntimeException(e.getMessage());
      } catch (ExecutionException e) {
        Throwable cause = e.getCause();
        if (cause instanceof Exception) {
          throw(Exception) e.getCause();
        } else {
          throw new Exception(cause);
        }
      }
    }
  }

  private <ReturnType> ReturnType timedCall(Callable<ReturnType> func)
      throws Exception {
    timer.start();
    ReturnType result = func.call();
    timer.stop();
    return result;
  }

  /**
   * Invokes func with a specified timeoutSeconds.
   * If func takes more than timeoutSeconds seconds to run,
   * TimeoutException is thrown.
   * If timeoutSeconds == 0, it simply calls the function.
   */
  public void run(Runnable func) throws Exception {
    run(() -> {
      func.run();
      return null;
    });
  }

  public TestTimer getTimer() { return timer; }
}
