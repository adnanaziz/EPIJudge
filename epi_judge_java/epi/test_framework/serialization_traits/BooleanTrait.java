
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;
import java.util.Objects;

public class BooleanTrait extends SerializationTrait {
  @Override
  public String name() {
    return "bool";
  }

  @Override
  public Object parse(JsonValue jsonObject) {
    return jsonObject.asBoolean();
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.emptyList();
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Boolean) {
      return Collections.emptyList();
    } else {
      throw new RuntimeException("Expected Boolean");
    }
  }
}
