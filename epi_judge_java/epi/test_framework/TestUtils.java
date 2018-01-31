// @library
package epi.test_framework;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;
import java.util.stream.Stream;

public class TestUtils {
  private static List<List<String>> splitTsvFile(Path dataFile) {
    List<List<String>> result = new ArrayList<>();
    Stream<String> inputData = null;
    try {
      inputData = Files.lines(dataFile);
    } catch (IOException e) {
      throw new RuntimeException("Test data file not found");
    }
    List<String> asList =
        inputData.collect(ArrayList::new, ArrayList::add, ArrayList::addAll);
    final String FIELD_DELIM = "\t";
    for (String line : asList) {
      result.add(Arrays.asList(line.split(FIELD_DELIM)));
    }
    return result;
  }

  public static void runTests(Path testDataPath, TestHandler handler,
                              long timeout, boolean stopOnError) {
    List<List<String>> testData = splitTsvFile(testDataPath);
    handler.parseSignature(testData.get(0));

    List<String> paramNames = handler.paramNames();

    int firstTestIdx = 1;
    int testNr = 0;
    final int totalTests = testData.size() - firstTestIdx;
    int testsPassed = 0;
    List<Long> durations = new ArrayList<>();

    for (List<String> testCase :
         testData.subList(firstTestIdx, testData.size())) {
      testNr++;

      // Since the last field of test_data is test_explanation, which is not
      // used for running test, we extract that here.
      final String testExplanation = testCase.get(testCase.size() - 1);
      testCase = testCase.subList(0, testCase.size() - 1);

      TestResult result = TestResult.FAILED;
      TestOutput testOutput = null;
      String diagnostic = "";

      try {
        final List<String> finalTestCase = testCase;
        if (timeout != 0) {
          final ExecutorService executor = Executors.newSingleThreadExecutor();
          final Future<TestOutput> future =
              executor.submit(() -> handler.runTest(finalTestCase));

          executor
              .shutdown();  // This does not cancel the already-scheduled task.
          testOutput = future.get(timeout, TimeUnit.MILLISECONDS);
          if (testOutput.comparisonResult) {
            result = TestResult.PASSED;
          }
        } else {
          testOutput = handler.runTest(finalTestCase);
          if (testOutput.comparisonResult) {
            result = TestResult.PASSED;
          }
        }

      } catch (TestFailureException e) {
        result = TestResult.FAILED;
        diagnostic = e.getMessage();
      } catch (StackOverflowError e) {
        result = TestResult.STACK_OVERFLOW;
      } catch (ExecutionException e) {
        Throwable cause = e.getCause();
        if (cause instanceof TestFailureException) {
          result = TestResult.FAILED;
          diagnostic = cause.getMessage();
        } else if (cause instanceof StackOverflowError) {
          result = TestResult.STACK_OVERFLOW;
        } else if (cause instanceof TimeoutException) {
          result = TestResult.TIMEOUT;
        } else if (cause instanceof RuntimeException) {
          throw(RuntimeException) cause;
        } else {
          result = TestResult.UNKNOWN_EXCEPTION;
          diagnostic = e.toString();
        }
      } catch (TimeoutException e) {
        result = TestResult.TIMEOUT;
      } catch (RuntimeException | InterruptedException e) {
        e.printStackTrace();
        System.exit(0);
      } catch (Exception e) {
        result = TestResult.UNKNOWN_EXCEPTION;
        diagnostic = e.toString();
      }

      if (testOutput == null) {
        testOutput = new TestOutput(false, new TestTimer());
        // Append expected value if execution ended due to an exception
        if (!handler.expectedIsVoid()) {
          testOutput.expected = testCase.get(testCase.size() - 1);
        }
      }

      TestUtilsConsole.printTestInfo(result, testNr, totalTests, diagnostic,
                                     testOutput.timer);

      if (result == TestResult.PASSED) {
        testsPassed++;
      }

      if (testOutput.timer.hasValidResult()) {
        durations.add(testOutput.timer.getMicroseconds());
      }

      if (result != TestResult.PASSED && stopOnError) {
        if (!handler.expectedIsVoid()) {
          testCase = testCase.subList(0, testCase.size() - 1);
        }
        TestUtilsConsole.printFailedTest(paramNames, testCase, testOutput,
                                         testExplanation);
        break;
      }
    }
    System.out.println();
    if (stopOnError) {
      if (!durations.isEmpty()) {
        final int durationsSize = durations.size();
        System.out.println(
            "Average running time: " +
            TestTimer.durationToString(
                durations.stream().mapToLong(Long::longValue).sum() /
                durationsSize));

        Collections.sort(durations);
        System.out.println("Median running time:  " +
                           TestTimer.durationToString(
                               (durationsSize % 2 == 1)
                                   ? durations.get(durationsSize / 2)
                                   : (durations.get(durationsSize / 2 - 1) +
                                      durations.get(durationsSize / 2)) /
                                         2));
      }

      if (testsPassed < totalTests) {
        System.out.println("*** You've passed " + String.valueOf(testsPassed) +
                           "/" + String.valueOf(totalTests) + " tests. ***");
      } else {
        System.out.println("*** You've passed ALL tests. Congratulations! ***");
      }
    }
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

  /**
   * Serialized type name can contain multiple comments, enclosed into brackets.
   * This method removes all such comments.
   */
  public static String filterBracketComments(String s) {
    final String BRACKET_ENCLOSED_COMMENT = "(\\[[^\\]]*\\])";
    return s.replaceAll(BRACKET_ENCLOSED_COMMENT, "").replaceAll(" ", "");
  }
}
