// @library
package epi.test_framework;

import java.io.IOException;
import java.lang.annotation.Annotation;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.function.BiPredicate;

public class GenericTest {
  /**
   * The main test starter. Is intended to be called from {@link
   * #runFromAnnotations(String[], long, Class)}.
   *
   * @param commandlineArgs - command-line options
   * @param testDataFile    - name of the file containing header and test data
   *                            without path prefix.
   * @param testFunc        - method to be tested
   * @param comparator      - optional custom result comparator.
   *                          The 1st argument is expected value,
   *                          the 2nd is the computed result.
   * @param expectedType    - optional custom expected value type if it doesn't
   *                          match m return type
   */
  public static TestResult genericTestMain(
      String[] commandlineArgs, String testDataFile, Method testFunc,
      BiPredicate<Object, Object> comparator, List<Class<?>> expectedType) {
    JsonObject configOverride = null;
    try {
      configOverride = Json.parse(new String(Files.readAllBytes(Paths.get(TestUtils.getFilePathInJudgeDir("config.json"))))).asObject();
    } catch (IOException e) {
      throw new RuntimeException("config.json file not found");
    }

    try {
      TestConfig config = TestConfig.fromCommandLine(
          testDataFile, configOverride.get("timeoutSeconds").asInt(), configOverride.get("numFailedTestsBeforeStop").asInt(), commandlineArgs);

      Platform.setOutputOpts(config.ttyMode, config.colorMode);

      GenericTestHandler testHandler =
          new GenericTestHandler(testFunc, comparator, expectedType);
      return runTests(testHandler, config);
    } catch (RuntimeException e) {
      System.err.printf("\nCritical error(%s): %s\n", e.getClass().getName(),
                        e.getMessage());
      e.printStackTrace();
      return TestResult.RUNTIME_EXCEPTION;
    }
  }

  public static TestResult runTests(GenericTestHandler handler,
                                    TestConfig config) {
    List<List<String>> testData = TestUtils.splitTsvFile(
        Paths.get(config.testDataDir, config.testDataFile));
    handler.parseSignature(testData.get(0));

    int testNr = 0;
    int testsPassed = 0;
    final int totalTests = testData.size() - 1;
    List<Long> durations = new ArrayList<>();
    TestResult result = TestResult.FAILED;

    for (List<String> testCase : testData.subList(1, testData.size())) {
      testNr++;

      // Since the last field of testData is testExplanation, which is not
      // used for running test, we extract that here.
      final String testExplanation = testCase.get(testCase.size() - 1);
      testCase = testCase.subList(0, testCase.size() - 1);

      TestTimer testTimer = null;
      TestFailure testFailure = new TestFailure();

      try {
        testTimer = handler.runTest(config.timeoutSeconds, testCase);
        result = TestResult.PASSED;
        testsPassed++;
        durations.add(testTimer.getMicroseconds());
      } catch (TestFailure e) {
        result = TestResult.FAILED;
        testFailure = e;
      } catch (TimeoutException e) {
        result = TestResult.TIMEOUT;
        testTimer = e.getTimer();
      } catch (StackOverflowError e) {
        result = TestResult.STACK_OVERFLOW;
      } catch (RuntimeException | Error e) {
        throw e;
      } catch (Exception e) {
        result = TestResult.UNKNOWN_EXCEPTION;
        testFailure =
            new TestFailure(e.getClass().getName())
                .withProperty(TestFailure.PropertyName.EXCEPTION_MESSAGE,
                              e.getMessage());
      }

      TestUtilsConsole.printTestInfo(result, testNr, totalTests,
                                     testFailure.getDescription(), testTimer);

      if (result != TestResult.PASSED) {
        if (config.verbose) {
          if (!handler.expectedIsVoid()) {
            testCase = testCase.subList(0, testCase.size() - 1);
          }
          if (!testExplanation.equals("") && !testExplanation.equals("TODO")) {
            testFailure.withProperty(TestFailure.PropertyName.EXPLANATION,
                                     testExplanation);
          }

          TestUtilsConsole.printFailedTest(handler.paramNames(), testCase,
                                           testFailure);
        }

        final int testsNotPassed = testNr - testsPassed;
        if (testsNotPassed >= config.numFailedTestsBeforeStop) {
          break;
        }
      }
    }

    System.out.println();

    if (config.verbose) {
      TestUtilsConsole.printPostRunStats(testsPassed, totalTests, durations);
    }
    return result;
  }

  /**
   * This method prepares arguments for
   * {@link #genericTestMain(String[], long, String, Method, BiPredicate, List)}
   * method and consequently invokes it for each * method in the class,
   * marked with {@link EpiTest} annotation.
   * It scans the * provided class for custom result comparator
   * (marked with {@link EpiTestComparator} annotation)
   * and for custom expected value type
   * (marked with {@link EpiTestExpectedType} annotation)
   */
  @SuppressWarnings("unchecked")
  public static TestResult runFromAnnotations(String[] commandlineArgs,
                                              Class testClass) {
    BiPredicate<Object, Object> comparator =
        findCustomComparatorByAnnotation(testClass);

    List<Class<?>> expectedType = findCustomExpectedTypeByAnnotation(testClass);

    TestResult result = TestResult.FAILED;
    for (Method m : testClass.getMethods()) {
      EpiTest annotation = m.getAnnotation(EpiTest.class);
      if (annotation != null) {
        result = genericTestMain(commandlineArgs, annotation.testfile(), m,
                                 comparator, expectedType);
      }
    }
    return result;
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
