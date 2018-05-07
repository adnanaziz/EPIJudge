
package epi.test_framework.serialization_traits;

import epi.test_framework.TestUtils;
import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class FloatTraits extends SerializationTraits {
  @Override
  public String name() {
    return "float";
  }

  @Override
  public Object parse(String str) {
    try {
      return Float.parseFloat(str);
    } catch (NumberFormatException e) {
      throw new RuntimeException("Float parser: conversion error: " +
                                 e.getMessage());
    }
  }

  @Override
  public Object jsonParse(JsonValue jsonObject) {
    if (jsonObject.isNumber()) {
      return jsonObject.asFloat();
    } else {
      throw new RuntimeException("Float parser: conversion error");
    }
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
    } else {
      throw new RuntimeException("Expected Float");
    }
  }

  @Override
  public boolean argumentsEqual(Object a, Object b) {
    if (a instanceof Float && b instanceof Float) {
      return TestUtils.floatComparison((Float)a, (Float)b);
    } else {
      throw new RuntimeException("Expected Float");
    }
  }
}
