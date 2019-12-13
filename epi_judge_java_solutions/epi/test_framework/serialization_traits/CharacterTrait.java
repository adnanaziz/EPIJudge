
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class CharacterTrait extends SerializationTrait {
  @Override
  public String name() {
    return "string";
  }

  @Override
  public Object parse(JsonValue jsonObject) {
    String arg = jsonObject.asString();
    if (arg.length() != 1) {
      throw new RuntimeException(
          "Character parser: string must contain exactly 1 char");
    }
    return arg.charAt(0);
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(argName);
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Character) {
      return Collections.singletonList((int)(Character)x);
    }
    throw new RuntimeException("Expected Character");
  }
}
