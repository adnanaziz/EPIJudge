
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class IntegerTrait extends SerializationTrait {
  @Override
  public String name() {
    return "int";
  }

  @Override
  public Object parse(JsonValue jsonObject) {
    return jsonObject.asInt();
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(argName);
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Integer) {
      return Collections.singletonList(Math.abs((int)x));
    }
    throw new RuntimeException("Expected Integer");
  }
}
