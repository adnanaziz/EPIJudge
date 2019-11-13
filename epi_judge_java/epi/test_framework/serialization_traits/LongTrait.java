
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class LongTrait extends SerializationTrait {
  @Override
  public String name() {
    return "long";
  }

  @Override
  public Object parse(JsonValue jsonObject) {
    return jsonObject.asLong();
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(argName);
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Long) {
      long val = Math.abs((long)x);
      return Collections.singletonList((int)Math.min(val, Integer.MAX_VALUE));
    }
    throw new RuntimeException("Expected Long");
  }
}
