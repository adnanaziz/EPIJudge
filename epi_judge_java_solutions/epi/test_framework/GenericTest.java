
package epi.test_framework;

import epi.test_framework.minimal_json.Json;
import epi.test_framework.minimal_json.JsonObject;
import epi.test_framework.minimal_json.JsonValue;
import epi.test_framework.minimal_json.Member;
import epi.test_framework.minimal_json.WriterConfig;

import java.io.IOException;
import java.io.PrintWriter;
import java.lang.annotation.Annotation;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.function.BiPredicate;
import java.util.function.Consumer;

public class GenericTest {
  /**
   * The main test starter. Is intended to be called from {@link
   * #runFromAnnotations(String[], String, Class)}.
   *  @param commandlineArgs - command-line options
   * @param testFile        - name of the file we are running
   * @param testDataFile    - name of the file containing header and test data
   *                          without path prefix
   * @param testFunc        - method to be tested
   * @param comparator      - optional custom result comparator.
   *                          The 1st argument is expected value,
   *                          the 2nd is the computed result
   * @param expectedType    - optional custom expected value type if it doesn't
   */
  private static TestResult
  genericTestMain(String[] commandlineArgs, String testFile,
                  String testDataFile, Method testFunc,
                  BiPredicate<Object, Object> comparator, Field expectedType,
                  Consumer<TestConfig> programConfig) {
    JsonObject configOverride = null;
    try {
      configOverride =
          Json.parse(new String(Files.readAllBytes(Paths.get(
                         TestUtils.getFilePathInJudgeDir("config.json")))))
              .asObject();
    } catch (IOException e) {
      throw new RuntimeException("config.json file not found");
    }

    try {
      TestConfig config = TestConfig.fromCommandLine(
          testFile, testDataFile, configOverride.get("timeoutSeconds").asInt(),
          configOverride.get("numFailedTestsBeforeStop").asInt(),
          commandlineArgs);

      if (programConfig != null) {
        programConfig.accept(config);
      }

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

  private static TestResult runTests(GenericTestHandler handler,
                                     TestConfig config) {
    List<List<String>> testData = TestUtils.splitTsvFile(
        Paths.get(config.testDataDir, config.testDataFile));
    handler.parseSignature(testData.get(0));

    List<String> metricNames =
        config.metricNamesOverride.apply(handler.metricNames());

    int testNr = 0;
    int testsPassed = 0;
    final int totalTests = testData.size() - 1;
    List<List<Integer>> metrics = new ArrayList<>();
    List<Long> durations = new ArrayList<>();
    TestResult result = TestResult.FAILED;

    for (List<String> testCase : testData.subList(1, testData.size())) {
      testNr++;

      // Since the last field of testData is testExplanation, which is not
      // used for running test, we extract that here.
      final String testExplanation = testCase.get(testCase.size() - 1);
      testCase = testCase.subList(0, testCase.size() - 1);

      TestOutput testOutput = new TestOutput(null, null);
      TestFailure testFailure = new TestFailure();

      try {
        testOutput = handler.runTest(config.timeoutSeconds,
                                     config.metricsOverride, testCase);
        result = TestResult.PASSED;
        testsPassed++;
        metrics.add(testOutput.metrics);
        durations.add(testOutput.timer.getMicroseconds());
      } catch (TestFailure e) {
        result = TestResult.FAILED;
        testFailure = e;
      } catch (TimeoutException e) {
        result = TestResult.TIMEOUT;
        testOutput.timer = e.getTimer();
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
                                     testFailure.getDescription(),
                                     testOutput.timer);

      if (result != TestResult.PASSED) {
        if (!handler.expectedIsVoid()) {
          testCase = testCase.subList(0, testCase.size() - 1);
        }
        if (!testExplanation.equals("") && !testExplanation.equals("TODO")) {
          testFailure.withProperty(TestFailure.PropertyName.EXPLANATION,
                                   testExplanation);
        }

        TestUtilsConsole.printFailedTest(handler.paramNames(), testCase,
                                         testFailure);

        final int testsNotPassed = testNr - testsPassed;
        if (testsNotPassed >= config.numFailedTestsBeforeStop) {
          break;
        }
      }
    }

    if (config.updateJs) {
      updateTestPassed(config.testFile, testsPassed);
    }

    System.out.println();

    if (!durations.isEmpty()) {
      String complexity = "";
      if (!metricNames.isEmpty() && !metrics.isEmpty() &&
          config.analyzeComplexity) {
        TestUtilsConsole.showComplexityNotification();
      }

      TestUtilsConsole.printPostRunStats(testsPassed, totalTests, complexity,
                                         durations);
    }
    return result;
  }

  @SuppressWarnings("unchecked")
  private static void updateTestPassed(String testFile, int testsPassed) {
    Path problemMappingFilePath =
        Paths.get(TestUtils.getFilePathInJudgeDir("problem_mapping.js"));
    JsonValue chapterToProblemToLanguageSolutionMapping = null;
    final String JS_BEGIN_PATTERN = "problem_mapping = ";
    final String JS_END_PATTERN = ";";
    try {
      String jsFileStr = new String(Files.readAllBytes(problemMappingFilePath));
      jsFileStr =
          jsFileStr.replace(JS_BEGIN_PATTERN, "").replace(JS_END_PATTERN, "");
      chapterToProblemToLanguageSolutionMapping = Json.parse(jsFileStr);
    } catch (IOException e) {
      throw new RuntimeException("problem_mapping.js file not found");
    }

    testFile = "Java: " + testFile;
    for (Member chapter :
         chapterToProblemToLanguageSolutionMapping.asObject()) {
      for (Member problem : chapter.getValue().asObject()) {
        for (Member language : problem.getValue().asObject()) {
          if (testFile.equals(language.getName())) {
            language.getValue().asObject().set("passed", testsPassed);
            try (PrintWriter problemMappingFile = new PrintWriter(
                     problemMappingFilePath.toAbsolutePath().toString())) {
              problemMappingFile.print(JS_BEGIN_PATTERN);
              chapterToProblemToLanguageSolutionMapping.writeTo(
                  problemMappingFile, WriterConfig.PRETTY_PRINT);
              problemMappingFile.print(JS_END_PATTERN);
            } catch (IOException e) {
              throw new RuntimeException("problem_mapping.js file not found");
            }
            return;
          }
        }
      }
    }
  }

  /**
   * This method prepares arguments for
   * {@link #genericTestMain(String[], String, String, Method, BiPredicate,
   * Field, Consumer)} method and consequently invokes it for each * method in
   * the class, marked with {@link EpiTest} annotation. It scans the * provided
   * class for custom result comparator (marked with {@link EpiTestComparator}
   * annotation) and for custom expected value type (marked with {@link
   * EpiTestExpectedType} annotation)
   */
  @SuppressWarnings("unchecked")
  public static TestResult runFromAnnotations(String[] commandlineArgs,
                                              String testFile,
                                              Class testClass) {
    BiPredicate<Object, Object> comparator =
        findCustomComparatorByAnnotation(testClass);
    Field expectedType = findCustomExpectedTypeByAnnotation(testClass);
    Consumer<TestConfig> programConfig =
        findProgramConfigByAnnotation(testClass);

    Method testFunc = findMethodWithAnnotation(testClass, EpiTest.class);
    if (testFunc == null) {
      throw new RuntimeException("Missing method with EpiTest annotation");
    }

    return genericTestMain(commandlineArgs, testFile,
                           testFunc.getAnnotation(EpiTest.class).testDataFile(),
                           testFunc, comparator, expectedType, programConfig);
  }

  private static Field
  findFieldWithAnnotation(Class testClass,
                          Class<? extends Annotation> annotationClass) {
    for (Field f : testClass.getFields()) {
      if (f.getAnnotation(annotationClass) != null) {
        return f;
      }
    }
    return null;
  }

  private static Method
  findMethodWithAnnotation(Class testClass,
                           Class<? extends Annotation> annotationClass) {
    for (Method m : testClass.getMethods()) {
      if (m.getAnnotation(annotationClass) != null) {
        return m;
      }
    }
    return null;
  }

  private static BiPredicate<Object, Object>
  findCustomComparatorByAnnotation(Class testClass) {
    Method m = findMethodWithAnnotation(testClass, EpiTestComparator.class);
    if (m == null) {
      return null;
    }
    return (expected, result) -> {
      try {
        return (Boolean)m.invoke(null, expected, result);
      } catch (IllegalAccessException | InvocationTargetException e) {
        throw new RuntimeException(e);
      }
    };
  }

  private static Consumer<TestConfig>
  findProgramConfigByAnnotation(Class testClass) {
    Method m = findMethodWithAnnotation(testClass, EpiProgramConfig.class);
    if (m == null) {
      return null;
    }
    return (config) -> {
      try {
        m.invoke(null, config);
      } catch (IllegalAccessException | InvocationTargetException e) {
        throw new RuntimeException(e);
      }
    };
  }

  private static Field findCustomExpectedTypeByAnnotation(Class testClass) {
    return findFieldWithAnnotation(testClass, EpiTestExpectedType.class);
  }
}
