
package epi.test_framework.serialization_traits;

import epi.test_framework.TestFailure;
import epi.test_framework.minimal_json.JsonValue;

import java.util.List;
import java.util.Objects;

public abstract class SerializationTrait {
  public abstract String name();
  public abstract Object parse(JsonValue jsonObject);
  public abstract List<String> getMetricNames(String argName);
  public abstract List<Integer> getMetrics(Object x);
  public boolean isVoid() { return false; }
  boolean argumentsEqual(Object a, Object b) throws TestFailure {
    return Objects.equals(a, b);
  }
}
