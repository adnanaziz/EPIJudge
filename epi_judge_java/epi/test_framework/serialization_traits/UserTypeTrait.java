
package epi.test_framework.serialization_traits;

import epi.test_framework.EpiUserType;
import epi.test_framework.minimal_json.JsonArray;
import epi.test_framework.minimal_json.JsonValue;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class UserTypeTrait extends SerializationTrait {
  private EpiUserType typeInfo;
  private List<SerializationTrait> ctorParamTraits;
  private Constructor<?> ctor;

  public UserTypeTrait(Class<?> userType, EpiUserType userTypeInfo) {
    this.typeInfo = userTypeInfo;
    ctorParamTraits = Arrays.stream(userTypeInfo.ctorParams())
                          .map(TraitsFactory::getTrait)
                          .collect(Collectors.toList());

    try {
      ctor = userType.getDeclaredConstructor(userTypeInfo.ctorParams());
    } catch (NoSuchMethodException e) {
      throw new RuntimeException(String.format(
          "%s does not have a constructor with signature %s",
          userType.getTypeName(), Arrays.toString(userTypeInfo.ctorParams())));
    }
  }

  @Override
  public String name() {
    StringBuilder sb = new StringBuilder();

    sb.append("tuple(");
    boolean first = true;
    for (SerializationTrait t : ctorParamTraits) {
      if (first) {
        first = false;
      } else {
        sb.append(",");
      }
      sb.append(t.name());
    }
    sb.append(")");
    return sb.toString();
  }

  @Override
  public Object parse(JsonValue jsonObject) {
    JsonArray a = jsonObject.asArray();
    if (a.size() != ctorParamTraits.size()) {
      throw new RuntimeException(
          String.format("Tuple parser: expected %d values, provided %d",
                        ctorParamTraits.size(), a.size()));
    }
    Object[] params = new Object[ctorParamTraits.size()];
    for (int i = 0; i < ctorParamTraits.size(); i++) {
      params[i] = ctorParamTraits.get(i).parse(a.get(i));
    }
    try {
      return ctor.newInstance(params);
    } catch (InstantiationException | IllegalAccessException |
             InvocationTargetException e) {
      throw new RuntimeException("Tuple parser: " + e.getMessage());
    }
  }

  @Override
  public List<String> getMetricNames(String argName) {
    // TODO: Find how to provide custom metrics.
    return Collections.emptyList();
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    return Collections.emptyList();
  }
}
