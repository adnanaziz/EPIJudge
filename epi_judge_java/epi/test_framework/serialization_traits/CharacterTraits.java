
package epi.test_framework.serialization_traits;

import epi.test_framework.minimal_json.JsonValue;

import java.util.Collections;
import java.util.List;

public class CharacterTraits extends SerializationTraits {
  @Override
  public String name() {
    return "string";
  }

  @Override
  public Object parse(String str) {
    if (str.length() != 1) {
      throw new RuntimeException(
          "Character parser: string must contain exactly 1 char");
    }
    return str.charAt(0);
  }

  @Override
  public Object jsonParse(JsonValue jsonObject) {
    if (jsonObject.isString()) {
      return parse(jsonObject.asString());
    } else {
      throw new RuntimeException("Character parser: conversion error");
    }
  }

  @Override
  public List<String> getMetricNames(String argName) {
    return Collections.singletonList(argName);
  }

  @Override
  public List<Integer> getMetrics(Object x) {
    if (x instanceof Character) {
      return Collections.singletonList((int)(Character)x);
    } else {
      throw new RuntimeException("Expected Character");
    }
  }
}
