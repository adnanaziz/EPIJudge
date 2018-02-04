// @library
package epi.test_framework;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.*;
import java.util.stream.Stream;

public class TestUtils {
  public static List<List<String>> splitTsvFile(Path tsvFile) {
    final String FIELD_DELIM = "\t";

    Stream<String> inputData = null;
    try {
      inputData = Files.lines(tsvFile);
    } catch (IOException e) {
      throw new RuntimeException("Test data file not found");
    }

    List<String> asList =
        inputData.collect(ArrayList::new, ArrayList::add, ArrayList::addAll);

    List<List<String>> result = new ArrayList<>();
    for (String line : asList) {
      result.add(Arrays.asList(line.split(FIELD_DELIM)));
    }
    return result;
  }

  public static String getDefaultTestDataDirPath() {
    final int MAX_SEARCH_DEPTH = 4;
    final String ENV_KEY = "EPI_TEST_DATA_DIR";
    final String DIR_NAME = "test_data";

    String env_result = System.getenv(ENV_KEY);
    if (env_result != null && !env_result.isEmpty()) {
      if (!Files.isDirectory(Paths.get(env_result))) {
        throw new RuntimeException(ENV_KEY +
                                   " environment variable is set to \"" +
                                   env_result + "\", but it's not a directory");
      }
      return env_result;
    }

    Path path = Paths.get(".").toAbsolutePath();
    for (int i = 0; i < MAX_SEARCH_DEPTH; i++) {
      if (Files.isDirectory(path.resolve(DIR_NAME))) {
        return path.resolve(DIR_NAME).toString();
      }
      path = path.getParent();
      if (path == null) {
        break;
      }
    }

    throw new RuntimeException(
        "Can't find test data directory. Specify it with " + ENV_KEY +
        " environment variable (you may need to restart PC) or start the program with \"--test_data_dir <path>\" command-line option");
  }

  /**
   * Serialized type name can contain multiple comments, enclosed into brackets.
   * This method removes all such comments.
   */
  public static String filterBracketComments(String s) {
    final String BRACKET_ENCLOSED_COMMENT = "(\\[[^\\]]*\\])";
    return s.replaceAll(BRACKET_ENCLOSED_COMMENT, "").replaceAll(" ", "");
  }

  /**
   * Invokes func with a specified timeout.
   * If func takes more than timeout milliseconds to run,
   * TimeoutException is thrown.
   * If timeout == 0, it simply calls the function.
   *
   * @return whatever func returns
   */
  public static <ReturnType> ReturnType
  invokeWithTimeout(int timeout, Callable<ReturnType> func) throws Throwable {
    if (timeout == 0) {
      // timeout is disabled
      return func.call();
    } else {
      try {
        final ExecutorService executor = Executors.newSingleThreadExecutor();
        final Future<ReturnType> future = executor.submit(func);
        executor
            .shutdown();  // This does not cancel the already-scheduled task.

        return future.get(timeout, TimeUnit.MILLISECONDS);
      } catch (java.util.concurrent.TimeoutException e) {
        throw new epi.test_framework.TimeoutException();
      } catch (InterruptedException e) {
        throw new RuntimeException(e.getMessage());
      } catch (ExecutionException e) {
        throw e.getCause();
      }
    }
  }

  /**
   * Non-exact float comparison
   */
  public static boolean floatComparison(Float f1, Float f2) {
    float eps = 1E-4f;
    return Math.abs(f1 - f2) <= eps * Math.max(Math.abs(f1), Math.abs(f2));
  }

  /**
   * Non-exact double comparison
   */
  public static boolean doubleComparison(Double d1, Double d2) {
    double eps = 1E-6;
    return Math.abs(d1 - d2) <= eps * Math.max(Math.abs(d1), Math.abs(d2));
  }
}
