
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class LongTraits extends SerializationTraits {
  @Override
  public String name() {
    return "long";
  }

  @Override
  public Object parse(String str) {
    try {
      return Long.parseLong(str);
    } catch (NumberFormatException e) {
      throw new RuntimeException("Long parser: conversion error: " +
                                 e.getMessage());
    }
  }

  @Override
  public Object jsonParse(JsonValue jsonObject) {
    if (jsonObject.isNumber()) {
      return jsonObject.asLong();
    } else {
      throw new RuntimeException("Long parser: conversion error");
    }
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
    } else {
      throw new RuntimeException("Expected Long");
    }
  }
}
