// @library
package epi.test_framework;

import java.lang.annotation.Annotation;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.function.BiPredicate;

public class GenericTest {
  /**
   * The main test starter. Is intended to be called from {@link
   * #runFromAnnotations(String[], Class)}.
   *
   * @param commandlineArgs - command-line options
   * @param testDataFile    - name of the file containing header and test data
   *                            without path prefix.
   * @param test_func               - method to be tested
   * @param comparator      - optional custom result comparator.
   *                          The 1st argument is expected value,
   *                          the 2nd is the computed result.
   * @param expectedType    - optional custom expected value type if it doesn't
   *                          match m return type
   */
  public static void genericTestMain(String[] commandlineArgs,
                                     String testDataFile, Method test_func,
                                     BiPredicate<Object, Object> comparator,
                                     List<Class<?>> expectedType) {
    try {
      TestConfig config =
          TestConfig.fromCommandLine(testDataFile, commandlineArgs);

      GenericTestHandler testHandler =
          new GenericTestHandler(test_func, comparator, expectedType);
      runTests(testHandler, config);
    } catch (RuntimeException e) {
      System.err.printf("\nCritical error(%s): %s\n", e.getClass().getName(),
                        e.getMessage());
      e.printStackTrace();
    }
  }

  public static void runTests(GenericTestHandler handler, TestConfig config) {
    List<List<String>> testData = TestUtils.splitTsvFile(
        Paths.get(config.testDataDir, config.testDataFile));
    handler.parseSignature(testData.get(0));

    int testNr = 0;
    int testsPassed = 0;
    final int totalTests = testData.size() - 1;
    List<Long> durations = new ArrayList<>();

    for (List<String> testCase : testData.subList(1, testData.size())) {
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
        testOutput = TestUtils.invokeWithTimeout(
            config.timeout, () -> handler.runTest(finalTestCase));
        result =
            testOutput.comparisonResult ? TestResult.PASSED : TestResult.FAILED;

      } catch (TestFailureException e) {
        result = TestResult.FAILED;
        diagnostic = e.getMessage();
      } catch (TimeoutException e) {
        result = TestResult.TIMEOUT;
      } catch (StackOverflowError e) {
        result = TestResult.STACK_OVERFLOW;
      } catch (RuntimeException e) {
        throw e;
      } catch (Throwable e) {
        result = TestResult.UNKNOWN_EXCEPTION;
        diagnostic = e.getClass().getName() + ": " + e.getMessage();
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

      if (result != TestResult.PASSED && config.stopOnError) {
        if (!handler.expectedIsVoid()) {
          testCase = testCase.subList(0, testCase.size() - 1);
        }
        TestUtilsConsole.printFailedTest(handler.paramNames(), testCase,
                                         testOutput, testExplanation);
        break;
      }
    }

    System.out.println();

    if (config.stopOnError) {
      TestUtilsConsole.printPostRunStats(testsPassed, totalTests, durations);
    }
  }

  /**
   * This method prepares arguments for
   * {@link #genericTestMain(String[], String, Method, BiPredicate, List)}
   * method and consequently invokes it for each * method in the class,
   * marked with {@link EpiTest} annotation.
   * It scans the * provided class for custom result comparator
   * (marked with {@link EpiTestComparator} annotation)
   * and for custom expected value type
   * (marked with {@link EpiTestExpectedType} annotation)
   */
  @SuppressWarnings("unchecked")
  public static void runFromAnnotations(String[] commandlineArgs,
                                        Class testClass) {
    BiPredicate<Object, Object> comparator =
        findCustomComparatorByAnnotation(testClass);

    List<Class<?>> expectedType = findCustomExpectedTypeByAnnotation(testClass);

    for (Method m : testClass.getMethods()) {
      EpiTest annotation = m.getAnnotation(EpiTest.class);
      if (annotation != null) {
        genericTestMain(commandlineArgs, annotation.testfile(), m, comparator,
                        expectedType);
      }
    }
  }

  @SuppressWarnings("unchecked")
  private static BiPredicate<Object, Object> findCustomComparatorByAnnotation(
      Class testClass) {
    for (Field f : testClass.getFields()) {
      Annotation annotation = f.getAnnotation(EpiTestComparator.class);
      if (annotation != null) {
        if (!f.getType().equals(BiPredicate.class)) {
          throw new RuntimeException(
              "EpiTestComparator type mismatch. Expected " +
              BiPredicate.class.getName() + ", got: " + f.getType().getName());
        }
        try {
          return (BiPredicate<Object, Object>)f.get(null);
        } catch (IllegalAccessException e) {
          throw new RuntimeException(e.getMessage());
        }
      }
    }

    return null;
  }

  @SuppressWarnings("unchecked")
  private static List<Class<?>> findCustomExpectedTypeByAnnotation(
      Class testClass) {
    for (Field f : testClass.getFields()) {
      Annotation annotation = f.getAnnotation(EpiTestExpectedType.class);
      if (annotation != null) {
        if (!f.getType().equals(List.class)) {
          throw new RuntimeException(
              "EpiTestExpectedType type mismatch. Expected " +
              List.class.getName() + ", got: " + f.getType().getName());
        }
        try {
          return (List<Class<?>>)f.get(null);
        } catch (IllegalAccessException e) {
          throw new RuntimeException(e.getMessage());
        }
      }
    }

    return null;
  }
}
