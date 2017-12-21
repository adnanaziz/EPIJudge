// @library
package epi.test_framework;

public class TestOutput {
  public Boolean comparisonResult;
  public TestTimer timer;
  public Object expected;
  public Object result;

  // For distinguishing between null (returned by user code) and empty value.
  public static Object EMPTY_OBJECT = new Object();

  public TestOutput(Boolean comparisonResult, TestTimer timer, Object expected,
                    Object result) {
    this.comparisonResult = comparisonResult;
    this.timer = timer;
    this.expected = expected;
    this.result = result;
  }

  public TestOutput(Boolean comparisonResult, TestTimer timer) {
    this.comparisonResult = comparisonResult;
    this.timer = timer;
    this.expected = EMPTY_OBJECT;
    this.result = EMPTY_OBJECT;
  }
}
