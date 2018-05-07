
package epi.test_framework.serialization_traits;

import epi.test_framework.TestUtils;
import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class DoubleTraits extends SerializationTraits {
  @Override
  public String name() {
    return "float";
  }

  @Override
  public Object parse(String str) {
    try {
      return Double.parseDouble(str);
    } catch (NumberFormatException e) {
      throw new RuntimeException("Double parser: conversion error: " +
                                 e.getMessage());
    }
  }

  @Override
  public Object jsonParse(JsonValue jsonObject) {
    if (jsonObject.isNumber()) {
      return jsonObject.asDouble();
    } else {
      throw new RuntimeException("Double parser: conversion error");
    }
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(argName);
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Double) {
      double val = Math.abs((double)x);
      return Collections.singletonList((int)Math.min(val, Integer.MAX_VALUE));
    } else {
      throw new RuntimeException("Expected Double");
    }
  }

  @Override
  public boolean argumentsEqual(Object a, Object b) {
    if (a instanceof Double && b instanceof Double) {
      return TestUtils.doubleComparison((Double)a, (Double)b);
    } else {
      throw new RuntimeException("Expected Double");
    }
  }
}
