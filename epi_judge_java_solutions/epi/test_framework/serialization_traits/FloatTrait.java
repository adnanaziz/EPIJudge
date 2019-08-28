
package epi.test_framework.serialization_traits;

import epi.test_framework.TestUtils;
import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class FloatTrait extends SerializationTrait {
  @Override
  public String name() {
    return "float";
  }

  @Override
  public Object parse(JsonValue jsonObject) {
    return jsonObject.asFloat();
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(argName);
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Float) {
      float val = Math.abs((float)x);
      return Collections.singletonList((int)Math.min(val, Integer.MAX_VALUE));
    }
    throw new RuntimeException("Expected Float");
  }

  @Override
  public boolean argumentsEqual(Object a, Object b) {
    if (a instanceof Float && b instanceof Float) {
      return TestUtils.floatComparison((Float)a, (Float)b);
    }
    throw new RuntimeException("Expected Float");
  }
}
