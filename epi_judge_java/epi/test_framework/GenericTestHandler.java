// @library
package epi.test_framework;

import java.io.File;
import java.lang.annotation.Annotation;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.lang.reflect.Type;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.function.BiPredicate;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * The central class in generic test runner framework.
 * It is responsible for constructing string deserializers
 * based on the argument types of the tested method (obtained with reflexions)
 * (see {@link #GenericTestHandler(Method, BiPredicate, List)},
 * asserting that the method signature matches the one from the test file header
 * (see {@link #parseSignature(List)} and
 * executing tests on the provided method (which includes
 * the deserialization of the provided arguments and the expected value,
 * invocation of the target method with these arguments and
 * comparison of the computed result with the expected value)
 * (see {@link #runTest(List)}).
 * <p>
 * {@link #parseSignature(List)} and {@link #runTest(List)} throw {@link
 * RuntimeException} in case of any error or assertion failure. This exception
 * terminates testing and, consequently, the test program. If tested method
 * throws {@link TestFailureException} or {@link StackOverflowError}, the
 * current test is marked as failed and the execution goes on. In case of any
 * other exception thrown by the tested method, the test program is terminated.
 * <p>
 */
public class GenericTestHandler implements TestHandler {
  private Method func;
  private List<Type> paramTypes;
  private boolean hasTimerHook;
  private Function<String, Object>[] paramParsers;
  private List<String> paramNames;
  private Function<String, Object> retValueParser;
  private BiPredicate<Object, Object> comparator;
  private boolean customExpectedType;

  /**
   * This constructor initializes type parsers for all arguments and return type
   * of func.
   *
   * @param func            - a method to test.
   * @param comparator   - an optional comparator for result. If comparator is
   *                     null, values are compared with equals().
   * @param expectedType - can be used with a custom comparator that has
   *                     different types for expected and result arguments.
   */
  public GenericTestHandler(Method func, BiPredicate<Object, Object> comparator,
                            List<Class<?>> expectedType) {
    this.func = func;
    this.comparator = comparator;

    hasTimerHook = false;

    paramTypes = Arrays.asList(func.getGenericParameterTypes());
    if (paramTypes.size() >= 1 && paramTypes.get(0).equals(TestTimer.class)) {
      hasTimerHook = true;
      paramTypes = paramTypes.subList(1, paramTypes.size());
    }

    @SuppressWarnings("unchecked")
    Function<String, Object>[] A = new Function[paramTypes.size()];
    paramParsers = A;

    for (int i = 0; i < paramTypes.size(); i++) {
      paramParsers[i] = TestUtilsDeserialization.getTypeParser(
          TestUtilsDeserialization.linearizeType(paramTypes.get(i)));
    }

    paramNames = Arrays.stream(func.getParameters())
                     .map(p -> p.getName())
                     .collect(Collectors.toList());
    if (hasTimerHook) {
      paramNames.remove(0);
    }

    if (expectedType == null) {
      retValueParser = TestUtilsDeserialization.getTypeParser(
          TestUtilsDeserialization.linearizeType(func.getGenericReturnType()));
    } else {
      retValueParser = TestUtilsDeserialization.getTypeParser(expectedType);
    }

    customExpectedType = expectedType != null;
  }

  /**
   * This method ensures that test data header matches with the signature of the
   * method provided in constructor.
   *
   * @param signature - the header from a test data file.
   */
  public void parseSignature(List<String> signature) {
    if (signature.size() != paramTypes.size() + 1) {
      throw new RuntimeException("Signature parameter count mismatch");
    }

    for (int i = 0; i < paramTypes.size(); i++) {
      if (!TestUtilsDeserialization.matchArgumentType(
              paramTypes.get(i),
              TestUtils.filterBracketComments(signature.get(i)))) {
        throw new RuntimeException(Integer.toString(i) +
                                   "th argument type mismatch");
      }
    }

    if (!customExpectedType) {
      if (!TestUtilsDeserialization.matchArgumentType(
              this.func.getGenericReturnType(),
              TestUtils.filterBracketComments(
                  signature.get(signature.size() - 1)))) {
        throw new RuntimeException("Return type mismatch");
      }
    }
  }

  /**
   * This method is invoked for each row in a test data file (except the
   * header). It deserializes the list of arguments and calls the user method
   * with them.
   *
   * @param testArgs - serialized arguments.
   * @return array, that contains [result of comparison of expected and result,
   * expected, result]. Two last entries are omitted in case of the void return
   * type
   */
  public TestOutput runTest(List<String> testArgs) throws Exception {
    try {
      if (testArgs.size() !=
          paramParsers.length + (retValueParser != null ? 1 : 0)) {
        throw new RuntimeException("Invalid argument count");
      }

      List<Object> parsed = new ArrayList<>();
      for (int i = 0; i < paramParsers.length; i++) {
        parsed.add(paramParsers[i].apply(testArgs.get(i)));
      }

      TestTimer timer = new TestTimer();

      if (hasTimerHook) {
        parsed.add(0, timer);
      }

      if (!expectedIsVoid()) {
        Object expected =
            retValueParser.apply(testArgs.get(testArgs.size() - 1));

        timer.start();
        Object result = this.func.invoke(null, parsed.toArray());
        timer.stop();

        return new TestOutput(compareResults(expected, result), timer, expected,
                              result);
      } else {
        timer.start();
        this.func.invoke(null, parsed.toArray());
        timer.stop();

        return new TestOutput(true, timer);
      }
    } catch (IllegalAccessException e) {
      throw new RuntimeException(e.getMessage());
    } catch (InvocationTargetException e) {
      Throwable t = e.getTargetException();
      if (t instanceof StackOverflowError) {
        throw(StackOverflowError) t;
      } else if (t instanceof Exception) {
        throw(Exception) t;
      } else {
        throw new RuntimeException(t.getMessage());
      }
    }
  }

  private boolean compareResults(Object expected, Object result) {
    boolean comparisonResult;
    if (comparator != null) {
      comparisonResult = comparator.test(expected, result);
    } else if (expected == null) {
      comparisonResult = result == null;
    } else if (expected instanceof Float && result instanceof Float) {
      comparisonResult =
          TestUtils.floatComparison((Float)expected, (Float)result);
    } else if (expected instanceof Double && result instanceof Double) {
      comparisonResult =
          TestUtils.doubleComparison((Double)expected, (Double)result);
    } else {
      comparisonResult = expected.equals(result);
    }
    return comparisonResult;
  }

  @Override
  public boolean expectedIsVoid() {
    return retValueParser == null;
  }

  @Override
  public List<String> paramNames() {
    return paramNames;
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

  /**
   * This method prepares arguments for {@link #executeTests(Method, String,
   * BiPredicate, List, String[])} method and consequently invokes it for each
   * method in the class, marked with {@link EpiTest} annotation. It scans the
   * provided class for custom result comparator (marked with {@link
   * EpiTestComparator} annotation) and for custom expected value type (marked
   * with {@link EpiTestExpectedType} annotation)
   */
  @SuppressWarnings("unchecked")
  public static void executeTestsByAnnotation(Class testClass,
                                              String[] commandlineArgs) {
    BiPredicate<Object, Object> comparator =
        findCustomComparatorByAnnotation(testClass);

    List<Class<?>> expectedType = findCustomExpectedTypeByAnnotation(testClass);

    for (Method m : testClass.getMethods()) {
      EpiTest annotation = m.getAnnotation(EpiTest.class);
      if (annotation != null) {
        executeTests(m, annotation.testfile(), comparator, expectedType,
                     commandlineArgs);
      }
    }
  }

  /**
   * The main test runner starter. Is intended to be called from {@link
   * #executeTestsByAnnotation(Class, String[])}.
   *
   * @param m            - method to be tested
   * @param testfile     - name of the file containing header and test data
   *                     without path prefix.
   * @param comparator   - optional custom result comparator. The 1st argument
   *                     is expected value, the 2nd is the computed result.
   * @param expectedType - optional custom expected value type if it doesn't
   * @param commandlineArgs       - command-line options
   */
  public static void executeTests(Method m, String testfile,
                                  BiPredicate<Object, Object> comparator,
                                  List<Class<?>> expectedType,
                                  String[] commandlineArgs) {
    try {
      boolean stopOnAError = true;
      String testDataDir = null;
      for (int i = 0; i < commandlineArgs.length; i++) {
        if (Objects.equals(commandlineArgs[i], "--test_data_dir")) {
          if (i + 1 >= commandlineArgs.length) {
            throw new RuntimeException("Missing param for --test_data_dir");
          }
          testDataDir = commandlineArgs[i + 1];
          i++;
        } else if (Objects.equals(commandlineArgs[i], "--run_all_tests")) {
          stopOnAError = false;
        } else {
          throw new RuntimeException("Unrecognized argument: " +
                                     commandlineArgs[i]);
        }
      }

      if (testDataDir != null && !testDataDir.isEmpty()) {
        if (!Files.isDirectory(Paths.get(testDataDir))) {
          throw new RuntimeException("--test_data_dir argument \"" +
                                     testDataDir + "\" is not a directory");
        }
      } else {
        testDataDir = TestUtils.getDefaultTestDataDirPath();
      }

      TestUtils.runTests(Paths.get(testDataDir, testfile),
                         new GenericTestHandler(m, comparator, expectedType), 0,
                         stopOnAError);
    } catch (RuntimeException e) {
      System.err.println("\nCritical error: " + e.getMessage());
    }
  }
}
