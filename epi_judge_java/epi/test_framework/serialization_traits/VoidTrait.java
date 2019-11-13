
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class VoidTrait extends SerializationTrait {
  @Override
  public String name() {
    return "void";
  }

  @Override
  public Object parse(JsonValue jsonObject) {
    throw new RuntimeException("Can't parse void");
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.emptyList();
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    return Collections.emptyList();
  }

  @Override
  public boolean isVoid() {
    return true;
  }
}
