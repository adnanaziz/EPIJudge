
package epi.test_framework;

import epi.TreeLike;
import epi.test_framework.minimal_json.Json;
import epi.test_framework.serialization_traits.SerializationTrait;
import epi.test_framework.serialization_traits.TraitsFactory;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.function.BiFunction;
import java.util.function.BiPredicate;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
/**
 * The central class in generic test runner framework.
 * It is responsible for constructing string deserializers
 * based on the argument types of the tested method (obtained with reflexions)
 * (see {@link #GenericTestHandler(Method, BiPredicate, Field)},
 * asserting that the method signature matches the one from the test file header
 * (see {@link #parseSignature(List)} and
 * executing tests on the provided method (which includes
 * the deserialization of the provided arguments and the expected value,
 * invocation of the target method with these arguments and
 * comparison of the computed result with the expected value)
 * (see {@link #runTest(long, BiFunction, List)}).
 * <p>
 * {@link #parseSignature(List)} and {@link #runTest(long, BiFunction, List)}
 * throw {@link RuntimeException} in case of any error or assertion failure.
 * This exception terminates testing and, consequently, the test program. If
 * tested method throws {@link TestFailure} or {@link StackOverflowError}, the
 * current test is marked as failed and the execution goes on. In case of any
 * other exception thrown by the tested method, the test program is terminated.
 * <p>
 */
public class GenericTestHandler {
  private Method func;
  private List<Type> paramTypes;
  private boolean hasExecutorHook;
  private List<SerializationTrait> paramTraits;
  private List<String> paramNames;
  private SerializationTrait retValueTrait;
  private BiPredicate<Object, Object> comp;
  private boolean customExpectedType;

  /**
   * This constructor initializes type parsers for all arguments and return type
   * of func.
   *
   * @param func         - a method to test.
   * @param comp         - an optional comp for result. If comp is null, values
   *                       are compared with equals().
   * @param expectedType - can be used with a custom comp that has different
   *                       types for expected and result arguments.
   */
  public GenericTestHandler(Method func, BiPredicate<Object, Object> comp,
                            Field expectedType) {
    this.func = func;
    this.comp = comp;
    hasExecutorHook = false;
    paramTypes = List.of(func.getGenericParameterTypes());

    if (paramTypes.size() >= 1 &&
        paramTypes.get(0).equals(TimedExecutor.class)) {
      hasExecutorHook = true;
      paramTypes = paramTypes.subList(1, paramTypes.size());
    }

    if (paramTypes.size() >= 1 && paramTypes.get(0).equals(TestTimer.class)) {
      throw new RuntimeException("This program uses deprecated TestTimer hook");
    }

    paramTraits = paramTypes.stream()
                      .map(TraitsFactory::getTrait)
                      .collect(Collectors.toList());
    paramNames = Arrays.stream(func.getParameters())
                     .map(Parameter::getName)
                     .collect(Collectors.toList());
    if (hasExecutorHook) {
      paramNames.remove(0);
    }

    if (expectedType == null) {
      retValueTrait = TraitsFactory.getTrait(func.getGenericReturnType());
    } else {
      retValueTrait = TraitsFactory.getTrait(expectedType.getGenericType());
    }

    customExpectedType = expectedType != null;
  }

  /**
   * This method ensures that test data header matches with the signature
   * of the method provided in constructor.
   *
   * @param signature - the header from a test data file.
   */
  public void parseSignature(List<String> signature) {
    if (signature.size() != paramTypes.size() + 1) {
      throw new RuntimeException("Signature parameter count mismatch");
    }

    for (int i = 0; i < paramTypes.size(); i++) {
      matchTypeNames(paramTraits.get(i).name(), signature.get(i),
                     String.format("%d argument", i));
    }

    if (!customExpectedType) {
      matchTypeNames(retValueTrait.name(), signature.get(signature.size() - 1),
                     "Return value");
    }
  }

  private void matchTypeNames(String expected, String fromTestData,
                              String sourceName) {
    if (!expected.equals(TestUtils.filterBracketComments(fromTestData))) {
      throw new RuntimeException(
          String.format("%s type mismatch: expected %s, got %s", sourceName,
                        expected, fromTestData));
    }
  }

  /**
   * This method is invoked for each row in a test data file (except the
   * header). It deserializes the list of arguments and calls the user method
   * with them.
   *
   * @param timeoutSeconds - number of seconds to timeout.
   * @param metricsOverride -
   * @param testArgs - serialized arguments.
   * @return array, that contains [result of comparison of expected and result,
   * expected, result]. Two last entries are omitted in case of the void return
   * type
   */
  public TestOutput runTest(
      long timeoutSeconds,
      BiFunction<List<Integer>, List<Object>, List<Integer>> metricsOverride,
      List<String> testArgs) throws Exception, Error {
    try {
      int expectedParamCount = paramTraits.size() + (expectedIsVoid() ? 0 : 1);
      if (testArgs.size() != expectedParamCount) {
        throw new RuntimeException(
            String.format("Invalid argument count: expected %d, actual %d",
                          expectedParamCount, testArgs.size()));
      }

      List<Object> parsed = new ArrayList<>();
      for (int i = 0; i < paramTraits.size(); i++) {
        parsed.add(paramTraits.get(i).parse(Json.parse(testArgs.get(i))));
      }
      List<Integer> metrics = calculateMetrics(parsed);
      metrics = metricsOverride.apply(metrics, parsed);

      Object result;
      TimedExecutor executor = new TimedExecutor(timeoutSeconds);

      if (hasExecutorHook) {
        parsed.add(0, executor);
        result = func.invoke(null, parsed.toArray());
      } else {
        result = executor.run(() -> func.invoke(null, parsed.toArray()));
      }

      if (!expectedIsVoid()) {
        Object expected =
            retValueTrait.parse(Json.parse(testArgs.get(testArgs.size() - 1)));
        assertResultsEqual(expected, result);
      }

      return new TestOutput(executor.getTimer(), metrics);
    } catch (IllegalAccessException e) {
      throw new RuntimeException(e.getMessage());
    } catch (InvocationTargetException e) {
      Throwable t = e.getCause();
      if (t instanceof Exception) {
        throw(Exception) t;
      } else if (t instanceof Error) {
        throw(Error) t;
      } else {
        // Improbable except for intended attempts to break the code, but anyway
        throw new RuntimeException(t);
      }
    }
  }

  @SuppressWarnings("unchecked")
  private void assertResultsEqual(Object expected, Object result)
      throws TestFailure {
    boolean comparisonResult;
    if (comp != null) {
      comparisonResult = comp.test(expected, result);
    } else if (expected == null) {
      comparisonResult = result == null;
    } else if (expected instanceof Float && result instanceof Float) {
      comparisonResult =
          TestUtils.floatComparison((Float)expected, (Float)result);
    } else if (expected instanceof Double && result instanceof Double) {
      comparisonResult =
          TestUtils.doubleComparison((Double)expected, (Double)result);
    } else if (expected instanceof TreeLike<?, ?> && result instanceof
                                                         TreeLike<?, ?>) {
      BinaryTreeUtils.assertEqualBinaryTrees((TreeLike<Object, ?>)expected,
                                             (TreeLike<Object, ?>)result);
      return;
    } else {
      comparisonResult = expected.equals(result);
    }
    if (!comparisonResult) {
      throw new TestFailure()
          .withProperty(TestFailure.PropertyName.EXPECTED, expected)
          .withProperty(TestFailure.PropertyName.RESULT, result);
    }
  }

  public List<String> metricNames() {
    return IntStream.range(0, Math.min(paramTraits.size(), paramNames.size()))
        .mapToObj(i -> paramTraits.get(i).getMetricNames(paramNames.get(i)))
        .flatMap(Collection::stream)
        .collect(Collectors.toList());
  }

  private List<Integer> calculateMetrics(List<Object> params) {
    return IntStream.range(0, Math.min(paramTraits.size(), params.size()))
        .mapToObj(i -> paramTraits.get(i).getMetrics(params.get(i)))
        .flatMap(Collection::stream)
        .collect(Collectors.toList());
  }

  public boolean expectedIsVoid() { return retValueTrait.isVoid(); }

  public List<String> paramNames() { return paramNames; }
}
