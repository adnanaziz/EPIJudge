// @library
package epi.test_framework;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
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
public class GenericTestHandler {
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
                     .map(Parameter::getName)
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
      Throwable t = e.getCause();
      if (t instanceof Exception) {
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
      // TODO Add binary trees comparison
      comparisonResult = expected.equals(result);
    }
    return comparisonResult;
  }

  public boolean expectedIsVoid() { return retValueParser == null; }

  public List<String> paramNames() { return paramNames; }
}
