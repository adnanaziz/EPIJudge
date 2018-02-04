// @library
package epi.test_framework;

/**
 * Tested function is allowed to throw this exception
 * in order to mark the current test as failed.
 */
public class TestFailureException extends Exception {
  public TestFailureException(String message) { super(message); }
}
