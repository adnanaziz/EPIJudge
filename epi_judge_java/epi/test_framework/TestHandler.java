// @library
package epi.test_framework;

import java.util.List;

public interface TestHandler {
  void parseSignature(List<String> signature);
  TestOutput runTest(List<String> arguments) throws Exception;

  boolean expectedIsVoid();

  List<String> paramNames();
}
