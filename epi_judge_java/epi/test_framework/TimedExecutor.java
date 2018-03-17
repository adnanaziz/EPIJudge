// @library
package epi.test_framework;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class TimedExecutor {
  private TestTimer timer;
  private long timeoutMs;

  public TimedExecutor(long timeoutMs) {
    this.timer = new TestTimer();
    this.timeoutMs = timeoutMs;
  }

  /**
   * Invokes func with a specified timeout.
   * If func takes more than timeout milliseconds to run,
   * TimeoutException is thrown.
   * If timeout == 0, it simply calls the function.
   *
   * @return whatever func returns
   */
  public <ReturnType> ReturnType run(Callable<ReturnType> func)
      throws Exception {
    if (timeoutMs == 0) {
      // timeout is disabled
      timer.start();
      ReturnType result = func.call();
      timer.stop();
      return result;
    } else {
      try {
        final ExecutorService executor = Executors.newSingleThreadExecutor();
        final Future<ReturnType> future = executor.submit(() -> {
          timer.start();
          ReturnType result = func.call();
          timer.stop();
          return result;
        });

        // This does not cancel the already-scheduled task.
        executor.shutdown();

        return future.get(timeoutMs, TimeUnit.MILLISECONDS);

      } catch (java.util.concurrent.TimeoutException e) {
        throw new epi.test_framework.TimeoutException(timeoutMs);
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

  /**
   * Invokes func with a specified timeout.
   * If func takes more than timeout milliseconds to run,
   * TimeoutException is thrown.
   * If timeout == 0, it simply calls the function.
   */
  public void run(Runnable func) throws Exception {
    run(() -> {
      func.run();
      return null;
    });
  }

  public TestTimer getTimer() { return timer; }
}
