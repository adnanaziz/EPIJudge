
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class IntegerTraits extends SerializationTraits {
  @Override
  public String name() {
    return "int";
  }

  @Override
  public Object parse(String str) {
    try {
      return Integer.parseInt(str);
    } catch (NumberFormatException e) {
      throw new RuntimeException("Int parser: conversion error: " +
                                 e.getMessage());
    }
  }

  @Override
  public Object jsonParse(JsonValue jsonObject) {
    if (jsonObject.isNumber()) {
      return jsonObject.asInt();
    } else {
      throw new RuntimeException("Int parser: conversion error");
    }
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(argName);
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Integer) {
      return Collections.singletonList(Math.abs((int)x));
    } else {
      throw new RuntimeException("Expected Integer");
    }
  }
}
