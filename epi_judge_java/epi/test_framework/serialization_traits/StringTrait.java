
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class StringTrait extends SerializationTrait {
  @Override
  public String name() {
    return "string";
  }

  @Override
  public Object parse(JsonValue jsonObject) {
    return jsonObject.asString();
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(String.format("size(%s)", argName));
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof String) {
      return Collections.singletonList(((String)x).length());
    }
    throw new RuntimeException("Expected String");
  }

  // TODO Custom parser that throws TestFailure with mismatch info
}
