// @library
package epi.test_framework;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.Reader;
import java.io.Serializable;
import java.io.StringReader;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

/*******************************************************************************
 * Copyright (c) 2015, 2016 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * This class serves as the entry point to the minimal_json API.
 * <p>
 * To <strong>parse</strong> a given JSON input, use the <code>parse()</code>
 * methods like in this
 * example:
 * </p>
 * <pre>
 * JsonObject object = Json.parse(string).asObject();
 * </pre>
 * <p>
 * To <strong>create</strong> a JSON data structure to be serialized, use the
 * methods
 * <code>value()</code>, <code>array()</code>, and <code>object()</code>. For
 * example, the following
 * snippet will produce the JSON string <em>{"foo": 23, "bar": true}</em>:
 * </p>
 * <pre>
 * String string = Json.object().add("foo", 23).add("bar", true).toString();
 * </pre>
 * <p>
 * To create a JSON array from a given Java array, you can use one of the
 * <code>array()</code>
 * methods with varargs parameters:
 * </p>
 * <pre>
 * String[] names = ...
 * JsonArray array = Json.array(names);
 * </pre>
 */
final class Json {
  private Json() {
    // not meant to be instantiated
  }

  /**
   * Represents the JSON literal <code>null</code>.
   */
  public static final JsonValue NULL = new JsonLiteral("null");

  /**
   * Represents the JSON literal <code>true</code>.
   */
  public static final JsonValue TRUE = new JsonLiteral("true");

  /**
   * Represents the JSON literal <code>false</code>.
   */
  public static final JsonValue FALSE = new JsonLiteral("false");

  /**
   * Returns a JsonValue instance that represents the given <code>int</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   */
  public static JsonValue value(int value) {
    return new JsonNumber(Integer.toString(value, 10));
  }

  /**
   * Returns a JsonValue instance that represents the given <code>long</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   */
  public static JsonValue value(long value) {
    return new JsonNumber(Long.toString(value, 10));
  }

  /**
   * Returns a JsonValue instance that represents the given <code>float</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   */
  public static JsonValue value(float value) {
    if (Float.isInfinite(value) || Float.isNaN(value)) {
      throw new IllegalArgumentException(
          "Infinite and NaN values not permitted in JSON");
    }
    return new JsonNumber(cutOffPointZero(Float.toString(value)));
  }

  /**
   * Returns a JsonValue instance that represents the given <code>double</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   */
  public static JsonValue value(double value) {
    if (Double.isInfinite(value) || Double.isNaN(value)) {
      throw new IllegalArgumentException(
          "Infinite and NaN values not permitted in JSON");
    }
    return new JsonNumber(cutOffPointZero(Double.toString(value)));
  }

  /**
   * Returns a JsonValue instance that represents the given string.
   *
   * @param string
   *          the string to get a JSON representation for
   * @return a JSON value that represents the given string
   */
  public static JsonValue value(String string) {
    return string == null ? NULL : new JsonString(string);
  }

  /**
   * Returns a JsonValue instance that represents the given <code>boolean</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   */
  public static JsonValue value(boolean value) { return value ? TRUE : FALSE; }

  /**
   * Creates a new empty JsonArray. This is equivalent to creating a new
   * JsonArray using the
   * constructor.
   *
   * @return a new empty JSON array
   */
  public static JsonArray array() { return new JsonArray(); }

  /**
   * Creates a new JsonArray that contains the JSON representations of the given
   * <code>int</code>
   * values.
   *
   * @param values
   *          the values to be included in the new JSON array
   * @return a new JSON array that contains the given values
   */
  public static JsonArray array(int... values) {
    if (values == null) {
      throw new NullPointerException("values is null");
    }
    JsonArray array = new JsonArray();
    for (int value : values) {
      array.add(value);
    }
    return array;
  }

  /**
   * Creates a new JsonArray that contains the JSON representations of the given
   * <code>long</code>
   * values.
   *
   * @param values
   *          the values to be included in the new JSON array
   * @return a new JSON array that contains the given values
   */
  public static JsonArray array(long... values) {
    if (values == null) {
      throw new NullPointerException("values is null");
    }
    JsonArray array = new JsonArray();
    for (long value : values) {
      array.add(value);
    }
    return array;
  }

  /**
   * Creates a new JsonArray that contains the JSON representations of the given
   * <code>float</code>
   * values.
   *
   * @param values
   *          the values to be included in the new JSON array
   * @return a new JSON array that contains the given values
   */
  public static JsonArray array(float... values) {
    if (values == null) {
      throw new NullPointerException("values is null");
    }
    JsonArray array = new JsonArray();
    for (float value : values) {
      array.add(value);
    }
    return array;
  }

  /**
   * Creates a new JsonArray that contains the JSON representations of the given
   * <code>double</code>
   * values.
   *
   * @param values
   *          the values to be included in the new JSON array
   * @return a new JSON array that contains the given values
   */
  public static JsonArray array(double... values) {
    if (values == null) {
      throw new NullPointerException("values is null");
    }
    JsonArray array = new JsonArray();
    for (double value : values) {
      array.add(value);
    }
    return array;
  }

  /**
   * Creates a new JsonArray that contains the JSON representations of the given
   * <code>boolean</code> values.
   *
   * @param values
   *          the values to be included in the new JSON array
   * @return a new JSON array that contains the given values
   */
  public static JsonArray array(boolean... values) {
    if (values == null) {
      throw new NullPointerException("values is null");
    }
    JsonArray array = new JsonArray();
    for (boolean value : values) {
      array.add(value);
    }
    return array;
  }

  /**
   * Creates a new JsonArray that contains the JSON representations of the given
   * strings.
   *
   * @param strings
   *          the strings to be included in the new JSON array
   * @return a new JSON array that contains the given strings
   */
  public static JsonArray array(String... strings) {
    if (strings == null) {
      throw new NullPointerException("values is null");
    }
    JsonArray array = new JsonArray();
    for (String value : strings) {
      array.add(value);
    }
    return array;
  }

  /**
   * Creates a new empty JsonObject. This is equivalent to creating a new
   * JsonObject using the
   * constructor.
   *
   * @return a new empty JSON object
   */
  public static JsonObject object() { return new JsonObject(); }

  /**
   * Parses the given input string as JSON. The input must contain a valid JSON
   * value, optionally
   * padded with whitespace.
   *
   * @param string
   *          the input string, must be valid JSON
   * @return a value that represents the parsed JSON
   * @throws ParseException
   *           if the input is not valid JSON
   */
  public static JsonValue parse(String string) {
    if (string == null) {
      throw new NullPointerException("string is null");
    }
    DefaultHandler handler = new DefaultHandler();
    new JsonParser(handler).parse(string);
    return handler.getValue();
  }

  /**
   * Reads the entire input from the given reader and parses it as JSON. The
   * input must contain a
   * valid JSON value, optionally padded with whitespace.
   * <p>
   * Characters are read in chunks into an input buffer. Hence, wrapping a
   * reader in an additional
   * <code>BufferedReader</code> likely won't improve reading performance.
   * </p>
   *
   * @param reader
   *          the reader to read the JSON value from
   * @return a value that represents the parsed JSON
   * @throws IOException
   *           if an I/O error occurs in the reader
   * @throws ParseException
   *           if the input is not valid JSON
   */
  public static JsonValue parse(Reader reader) throws IOException {
    if (reader == null) {
      throw new NullPointerException("reader is null");
    }
    DefaultHandler handler = new DefaultHandler();
    new JsonParser(handler).parse(reader);
    return handler.getValue();
  }

  private static String cutOffPointZero(String string) {
    if (string.endsWith(".0")) {
      return string.substring(0, string.length() - 2);
    }
    return string;
  }

  static class DefaultHandler extends JsonHandler<JsonArray, JsonObject> {
    protected JsonValue value;

    @Override
    public JsonArray startArray() {
      return new JsonArray();
    }

    @Override
    public JsonObject startObject() {
      return new JsonObject();
    }

    @Override
    public void endNull() {
      value = NULL;
    }

    @Override
    public void endBoolean(boolean bool) {
      value = bool ? TRUE : FALSE;
    }

    @Override
    public void endString(String string) {
      value = new JsonString(string);
    }

    @Override
    public void endNumber(String string) {
      value = new JsonNumber(string);
    }

    @Override
    public void endArray(JsonArray array) {
      value = array;
    }

    @Override
    public void endObject(JsonObject object) {
      value = object;
    }

    @Override
    public void endArrayValue(JsonArray array) {
      array.add(value);
    }

    @Override
    public void endObjectValue(JsonObject object, String name) {
      object.add(name, value);
    }

    JsonValue getValue() { return value; }
  }
}
/*******************************************************************************
 * Copyright (c) 2013, 2015 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * Represents a JSON array, an ordered collection of JSON values.
 * <p>
 * Elements can be added using the <code>add(...)</code> methods which accept
 * instances of
 * {@link JsonValue}, strings, primitive numbers, and boolean values. To replace
 * an element of an
 * array, use the <code>set(int, ...)</code> methods.
 * </p>
 * <p>
 * Elements can be accessed by their index using {@link #get(int)}. This class
 * also supports
 * iterating over the elements in document order using an {@link #iterator()} or
 * an enhanced for
 * loop:
 * </p>
 * <pre>
 * for (JsonValue value : jsonArray) {
 *   ...
 * }
 * </pre>
 * <p>
 * An equivalent {@link List} can be obtained from the method {@link #values()}.
 * </p>
 * <p>
 * Note that this class is <strong>not thread-safe</strong>. If multiple threads
 * access a
 * <code>JsonArray</code> instance concurrently, while at least one of these
 * threads modifies the
 * contents of this array, access to the instance must be synchronized
 * externally. Failure to do so
 * may lead to an inconsistent state.
 * </p>
 * <p>
 * This class is <strong>not supposed to be extended</strong> by clients.
 * </p>
 */
@SuppressWarnings("serial")  // use default serial UID
class JsonArray extends JsonValue implements Iterable<JsonValue> {
  private final List<JsonValue> values;

  /**
   * Creates a new empty JsonArray.
   */
  public JsonArray() { values = new ArrayList<JsonValue>(); }

  /**
   * Creates a new JsonArray with the contents of the specified JSON array.
   *
   * @param array
   *          the JsonArray to get the initial contents from, must not be
   * <code>null</code>
   */
  public JsonArray(JsonArray array) { this(array, false); }

  private JsonArray(JsonArray array, boolean unmodifiable) {
    if (array == null) {
      throw new NullPointerException("array is null");
    }
    if (unmodifiable) {
      values = Collections.unmodifiableList(array.values);
    } else {
      values = new ArrayList<JsonValue>(array.values);
    }
  }

  /**
   * Reads a JSON array from the given reader.
   * <p>
   * Characters are read in chunks and buffered internally, therefore wrapping
   * an existing reader in
   * an additional <code>BufferedReader</code> does <strong>not</strong> improve
   * reading
   * performance.
   * </p>
   *
   * @param reader
   *          the reader to read the JSON array from
   * @return the JSON array that has been read
   * @throws IOException
   *           if an I/O error occurs in the reader
   * @throws ParseException
   *           if the input is not valid JSON
   * @throws UnsupportedOperationException
   *           if the input does not contain a JSON array
   * @deprecated Use {@link Json#parse(Reader)}{@link JsonValue#asArray()
   * .asArray()} instead
   */
  @Deprecated
  public static JsonArray readFrom(Reader reader) throws IOException {
    return JsonValue.readFrom(reader).asArray();
  }

  /**
   * Reads a JSON array from the given string.
   *
   * @param string
   *          the string that contains the JSON array
   * @return the JSON array that has been read
   * @throws ParseException
   *           if the input is not valid JSON
   * @throws UnsupportedOperationException
   *           if the input does not contain a JSON array
   * @deprecated Use {@link Json#parse(String)}{@link JsonValue#asArray()
   * .asArray()} instead
   */
  @Deprecated
  public static JsonArray readFrom(String string) {
    return JsonValue.readFrom(string).asArray();
  }

  /**
   * Returns an unmodifiable wrapper for the specified JsonArray. This method
   * allows to provide
   * read-only access to a JsonArray.
   * <p>
   * The returned JsonArray is backed by the given array and reflects subsequent
   * changes. Attempts
   * to modify the returned JsonArray result in an
   * <code>UnsupportedOperationException</code>.
   * </p>
   *
   * @param array
   *          the JsonArray for which an unmodifiable JsonArray is to be
   * returned
   * @return an unmodifiable view of the specified JsonArray
   */
  public static JsonArray unmodifiableArray(JsonArray array) {
    return new JsonArray(array, true);
  }

  /**
   * Appends the JSON representation of the specified <code>int</code> value to
   * the end of this
   * array.
   *
   * @param value
   *          the value to add to the array
   * @return the array itself, to enable method chaining
   */
  public JsonArray add(int value) {
    values.add(Json.value(value));
    return this;
  }

  /**
   * Appends the JSON representation of the specified <code>long</code> value to
   * the end of this
   * array.
   *
   * @param value
   *          the value to add to the array
   * @return the array itself, to enable method chaining
   */
  public JsonArray add(long value) {
    values.add(Json.value(value));
    return this;
  }

  /**
   * Appends the JSON representation of the specified <code>float</code> value
   * to the end of this
   * array.
   *
   * @param value
   *          the value to add to the array
   * @return the array itself, to enable method chaining
   */
  public JsonArray add(float value) {
    values.add(Json.value(value));
    return this;
  }

  /**
   * Appends the JSON representation of the specified <code>double</code> value
   * to the end of this
   * array.
   *
   * @param value
   *          the value to add to the array
   * @return the array itself, to enable method chaining
   */
  public JsonArray add(double value) {
    values.add(Json.value(value));
    return this;
  }

  /**
   * Appends the JSON representation of the specified <code>boolean</code> value
   * to the end of this
   * array.
   *
   * @param value
   *          the value to add to the array
   * @return the array itself, to enable method chaining
   */
  public JsonArray add(boolean value) {
    values.add(Json.value(value));
    return this;
  }

  /**
   * Appends the JSON representation of the specified string to the end of this
   * array.
   *
   * @param value
   *          the string to add to the array
   * @return the array itself, to enable method chaining
   */
  public JsonArray add(String value) {
    values.add(Json.value(value));
    return this;
  }

  /**
   * Appends the specified JSON value to the end of this array.
   *
   * @param value
   *          the JsonValue to add to the array, must not be <code>null</code>
   * @return the array itself, to enable method chaining
   */
  public JsonArray add(JsonValue value) {
    if (value == null) {
      throw new NullPointerException("value is null");
    }
    values.add(value);
    return this;
  }

  /**
   * Replaces the element at the specified position in this array with the JSON
   * representation of
   * the specified <code>int</code> value.
   *
   * @param index
   *          the index of the array element to replace
   * @param value
   *          the value to be stored at the specified array position
   * @return the array itself, to enable method chaining
   * @throws IndexOutOfBoundsException
   *           if the index is out of range, i.e. <code>index &lt; 0</code> or
   *           <code>index &gt;= size</code>
   */
  public JsonArray set(int index, int value) {
    values.set(index, Json.value(value));
    return this;
  }

  /**
   * Replaces the element at the specified position in this array with the JSON
   * representation of
   * the specified <code>long</code> value.
   *
   * @param index
   *          the index of the array element to replace
   * @param value
   *          the value to be stored at the specified array position
   * @return the array itself, to enable method chaining
   * @throws IndexOutOfBoundsException
   *           if the index is out of range, i.e. <code>index &lt; 0</code> or
   *           <code>index &gt;= size</code>
   */
  public JsonArray set(int index, long value) {
    values.set(index, Json.value(value));
    return this;
  }

  /**
   * Replaces the element at the specified position in this array with the JSON
   * representation of
   * the specified <code>float</code> value.
   *
   * @param index
   *          the index of the array element to replace
   * @param value
   *          the value to be stored at the specified array position
   * @return the array itself, to enable method chaining
   * @throws IndexOutOfBoundsException
   *           if the index is out of range, i.e. <code>index &lt; 0</code> or
   *           <code>index &gt;= size</code>
   */
  public JsonArray set(int index, float value) {
    values.set(index, Json.value(value));
    return this;
  }

  /**
   * Replaces the element at the specified position in this array with the JSON
   * representation of
   * the specified <code>double</code> value.
   *
   * @param index
   *          the index of the array element to replace
   * @param value
   *          the value to be stored at the specified array position
   * @return the array itself, to enable method chaining
   * @throws IndexOutOfBoundsException
   *           if the index is out of range, i.e. <code>index &lt; 0</code> or
   *           <code>index &gt;= size</code>
   */
  public JsonArray set(int index, double value) {
    values.set(index, Json.value(value));
    return this;
  }

  /**
   * Replaces the element at the specified position in this array with the JSON
   * representation of
   * the specified <code>boolean</code> value.
   *
   * @param index
   *          the index of the array element to replace
   * @param value
   *          the value to be stored at the specified array position
   * @return the array itself, to enable method chaining
   * @throws IndexOutOfBoundsException
   *           if the index is out of range, i.e. <code>index &lt; 0</code> or
   *           <code>index &gt;= size</code>
   */
  public JsonArray set(int index, boolean value) {
    values.set(index, Json.value(value));
    return this;
  }

  /**
   * Replaces the element at the specified position in this array with the JSON
   * representation of
   * the specified string.
   *
   * @param index
   *          the index of the array element to replace
   * @param value
   *          the string to be stored at the specified array position
   * @return the array itself, to enable method chaining
   * @throws IndexOutOfBoundsException
   *           if the index is out of range, i.e. <code>index &lt; 0</code> or
   *           <code>index &gt;= size</code>
   */
  public JsonArray set(int index, String value) {
    values.set(index, Json.value(value));
    return this;
  }

  /**
   * Replaces the element at the specified position in this array with the
   * specified JSON value.
   *
   * @param index
   *          the index of the array element to replace
   * @param value
   *          the value to be stored at the specified array position, must not
   * be <code>null</code>
   * @return the array itself, to enable method chaining
   * @throws IndexOutOfBoundsException
   *           if the index is out of range, i.e. <code>index &lt; 0</code> or
   *           <code>index &gt;= size</code>
   */
  public JsonArray set(int index, JsonValue value) {
    if (value == null) {
      throw new NullPointerException("value is null");
    }
    values.set(index, value);
    return this;
  }

  /**
   * Removes the element at the specified index from this array.
   *
   * @param index
   *          the index of the element to remove
   * @return the array itself, to enable method chaining
   * @throws IndexOutOfBoundsException
   *           if the index is out of range, i.e. <code>index &lt; 0</code> or
   *           <code>index &gt;= size</code>
   */
  public JsonArray remove(int index) {
    values.remove(index);
    return this;
  }

  /**
   * Returns the number of elements in this array.
   *
   * @return the number of elements in this array
   */
  public int size() { return values.size(); }

  /**
   * Returns <code>true</code> if this array contains no elements.
   *
   * @return <code>true</code> if this array contains no elements
   */
  public boolean isEmpty() { return values.isEmpty(); }

  /**
   * Returns the value of the element at the specified position in this array.
   *
   * @param index
   *          the index of the array element to return
   * @return the value of the element at the specified position
   * @throws IndexOutOfBoundsException
   *           if the index is out of range, i.e. <code>index &lt; 0</code> or
   *           <code>index &gt;= size</code>
   */
  public JsonValue get(int index) { return values.get(index); }

  /**
   * Returns a list of the values in this array in document order. The returned
   * list is backed by
   * this array and will reflect subsequent changes. It cannot be used to modify
   * this array.
   * Attempts to modify the returned list will result in an exception.
   *
   * @return a list of the values in this array
   */
  public List<JsonValue> values() {
    return Collections.unmodifiableList(values);
  }

  /**
   * Returns an iterator over the values of this array in document order. The
   * returned iterator
   * cannot be used to modify this array.
   *
   * @return an iterator over the values of this array
   */
  public Iterator<JsonValue> iterator() {
    final Iterator<JsonValue> iterator = values.iterator();
    return new Iterator<JsonValue>() {

      public boolean hasNext() { return iterator.hasNext(); }

      public JsonValue next() { return iterator.next(); }

      public void remove() { throw new UnsupportedOperationException(); }
    };
  }

  @Override
  void write(JsonWriter writer) throws IOException {
    writer.writeArrayOpen();
    Iterator<JsonValue> iterator = iterator();
    if (iterator.hasNext()) {
      iterator.next().write(writer);
      while (iterator.hasNext()) {
        writer.writeArraySeparator();
        iterator.next().write(writer);
      }
    }
    writer.writeArrayClose();
  }

  @Override
  public boolean isArray() {
    return true;
  }

  @Override
  public JsonArray asArray() {
    return this;
  }

  @Override
  public int hashCode() {
    return values.hashCode();
  }

  /**
   * Indicates whether a given object is "equal to" this JsonArray. An object is
   * considered equal
   * if it is also a <code>JsonArray</code> and both arrays contain the same
   * list of values.
   * <p>
   * If two JsonArrays are equal, they will also produce the same JSON output.
   * </p>
   *
   * @param object
   *          the object to be compared with this JsonArray
   * @return <tt>true</tt> if the specified object is equal to this JsonArray,
   * <code>false</code>
   *         otherwise
   */
  @Override
  public boolean equals(Object object) {
    if (this == object) {
      return true;
    }
    if (object == null) {
      return false;
    }
    if (getClass() != object.getClass()) {
      return false;
    }
    JsonArray other = (JsonArray)object;
    return values.equals(other.values);
  }
}
/*******************************************************************************
 * Copyright (c) 2016 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * A handler for parser events. Instances of this class can be given to a {@link
 * JsonParser}. The
 * parser will then call the methods of the given handler while reading the
 * input.
 * <p>
 * The default implementations of these methods do nothing. Subclasses may
 * override only those
 * methods they are interested in. They can use <code>getLocation()</code> to
 * access the current
 * character position of the parser at any point. The <code>start*</code>
 * methods will be called
 * while the location points to the first character of the parsed element. The
 * <code>end*</code>
 * methods will be called while the location points to the character position
 * that directly follows
 * the last character of the parsed element. Example:
 * </p>
 *
 * <pre>
 * ["lorem ipsum"]
 *  ^            ^
 *  startString  endString
 * </pre>
 * <p>
 * Subclasses that build an object representation of the parsed JSON can return
 * arbitrary handler
 * objects for JSON arrays and JSON objects in {@link #startArray()} and {@link
 * #startObject()}.
 * These handler objects will then be provided in all subsequent parser events
 * for this particular
 * array or object. They can be used to keep track the elements of a JSON array
 * or object.
 * </p>
 *
 * @param <A>
 *          The type of handlers used for JSON arrays
 * @param <O>
 *          The type of handlers used for JSON objects
 * @see JsonParser
 */
abstract class JsonHandler<A, O> {
  JsonParser parser;

  /**
   * Returns the current parser location.
   *
   * @return the current parser location
   */
  protected Location getLocation() { return parser.getLocation(); }

  /**
   * Indicates the beginning of a <code>null</code> literal in the JSON input.
   * This method will be
   * called when reading the first character of the literal.
   */
  public void startNull() {}

  /**
   * Indicates the end of a <code>null</code> literal in the JSON input. This
   * method will be called
   * after reading the last character of the literal.
   */
  public void endNull() {}

  /**
   * Indicates the beginning of a boolean literal (<code>true</code> or
   * <code>false</code>) in the
   * JSON input. This method will be called when reading the first character of
   * the literal.
   */
  public void startBoolean() {}

  /**
   * Indicates the end of a boolean literal (<code>true</code> or
   * <code>false</code>) in the JSON
   * input. This method will be called after reading the last character of the
   * literal.
   *
   * @param value
   *          the parsed boolean value
   */
  public void endBoolean(boolean value) {}

  /**
   * Indicates the beginning of a string in the JSON input. This method will be
   * called when reading
   * the opening double quote character (<code>'&quot;'</code>).
   */
  public void startString() {}

  /**
   * Indicates the end of a string in the JSON input. This method will be called
   * after reading the
   * closing double quote character (<code>'&quot;'</code>).
   *
   * @param string
   *          the parsed string
   */
  public void endString(String string) {}

  /**
   * Indicates the beginning of a number in the JSON input. This method will be
   * called when reading
   * the first character of the number.
   */
  public void startNumber() {}

  /**
   * Indicates the end of a number in the JSON input. This method will be called
   * after reading the
   * last character of the number.
   *
   * @param string
   *          the parsed number string
   */
  public void endNumber(String string) {}

  /**
   * Indicates the beginning of an array in the JSON input. This method will be
   * called when reading
   * the opening square bracket character (<code>'['</code>).
   * <p>
   * This method may return an object to handle subsequent parser events for
   * this array. This array
   * handler will then be provided in all calls to {@link
   * #startArrayValue(Object)
   * startArrayValue()}, {@link #endArrayValue(Object) endArrayValue()}, and
   * {@link #endArray(Object) endArray()} for this array.
   * </p>
   *
   * @return a handler for this array, or <code>null</code> if not needed
   */
  public A startArray() { return null; }

  /**
   * Indicates the end of an array in the JSON input. This method will be called
   * after reading the
   * closing square bracket character (<code>']'</code>).
   *
   * @param array
   *          the array handler returned from {@link #startArray()}, or
   * <code>null</code> if not
   *          provided
   */
  public void endArray(A array) {}

  /**
   * Indicates the beginning of an array element in the JSON input. This method
   * will be called when
   * reading the first character of the element, just before the call to the
   * <code>start</code>
   * method for the specific element type ({@link #startString()}, {@link
   * #startNumber()}, etc.).
   *
   * @param array
   *          the array handler returned from {@link #startArray()}, or
   * <code>null</code> if not
   *          provided
   */
  public void startArrayValue(A array) {}

  /**
   * Indicates the end of an array element in the JSON input. This method will
   * be called after
   * reading the last character of the element value, just after the
   * <code>end</code> method for the
   * specific element type (like {@link #endString(String) endString()}, {@link
   * #endNumber(String)
   * endNumber()}, etc.).
   *
   * @param array
   *          the array handler returned from {@link #startArray()}, or
   * <code>null</code> if not
   *          provided
   */
  public void endArrayValue(A array) {}

  /**
   * Indicates the beginning of an object in the JSON input. This method will be
   * called when reading
   * the opening curly bracket character (<code>'{'</code>).
   * <p>
   * This method may return an object to handle subsequent parser events for
   * this object. This
   * object handler will be provided in all calls to {@link
   * #startObjectName(Object)
   * startObjectName()}, {@link #endObjectName(Object, String) endObjectName()},
   * {@link #startObjectValue(Object, String) startObjectValue()},
   * {@link #endObjectValue(Object, String) endObjectValue()}, and {@link
   * #endObject(Object)
   * endObject()} for this object.
   * </p>
   *
   * @return a handler for this object, or <code>null</code> if not needed
   */
  public O startObject() { return null; }

  /**
   * Indicates the end of an object in the JSON input. This method will be
   * called after reading the
   * closing curly bracket character (<code>'}'</code>).
   *
   * @param object
   *          the object handler returned from {@link #startObject()}, or null
   * if not provided
   */
  public void endObject(O object) {}

  /**
   * Indicates the beginning of the name of an object member in the JSON input.
   * This method will be
   * called when reading the opening quote character ('&quot;') of the member
   * name.
   *
   * @param object
   *          the object handler returned from {@link #startObject()}, or
   * <code>null</code> if not
   *          provided
   */
  public void startObjectName(O object) {}

  /**
   * Indicates the end of an object member name in the JSON input. This method
   * will be called after
   * reading the closing quote character (<code>'"'</code>) of the member name.
   *
   * @param object
   *          the object handler returned from {@link #startObject()}, or null
   * if not provided
   * @param name
   *          the parsed member name
   */
  public void endObjectName(O object, String name) {}

  /**
   * Indicates the beginning of the name of an object member in the JSON input.
   * This method will be
   * called when reading the opening quote character ('&quot;') of the member
   * name.
   *
   * @param object
   *          the object handler returned from {@link #startObject()}, or
   * <code>null</code> if not
   *          provided
   * @param name
   *          the member name
   */
  public void startObjectValue(O object, String name) {}

  /**
   * Indicates the end of an object member value in the JSON input. This method
   * will be called after
   * reading the last character of the member value, just after the
   * <code>end</code> method for the
   * specific member type (like {@link #endString(String) endString()}, {@link
   * #endNumber(String)
   * endNumber()}, etc.).
   *
   * @param object
   *          the object handler returned from {@link #startObject()}, or null
   * if not provided
   * @param name
   *          the parsed member name
   */
  public void endObjectValue(O object, String name) {}
}
/*******************************************************************************
 * Copyright (c) 2013, 2015 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

@SuppressWarnings("serial")  // use default serial UID
class JsonLiteral extends JsonValue {
  private final String value;
  private final boolean isNull;
  private final boolean isTrue;
  private final boolean isFalse;

  JsonLiteral(String value) {
    this.value = value;
    isNull = "null".equals(value);
    isTrue = "true".equals(value);
    isFalse = "false".equals(value);
  }

  @Override
  void write(JsonWriter writer) throws IOException {
    writer.writeLiteral(value);
  }

  @Override
  public String toString() {
    return value;
  }

  @Override
  public int hashCode() {
    return value.hashCode();
  }

  @Override
  public boolean isNull() {
    return isNull;
  }

  @Override
  public boolean isTrue() {
    return isTrue;
  }

  @Override
  public boolean isFalse() {
    return isFalse;
  }

  @Override
  public boolean isBoolean() {
    return isTrue || isFalse;
  }

  @Override
  public boolean asBoolean() {
    return isNull ? super.asBoolean() : isTrue;
  }

  @Override
  public boolean equals(Object object) {
    if (this == object) {
      return true;
    }
    if (object == null) {
      return false;
    }
    if (getClass() != object.getClass()) {
      return false;
    }
    JsonLiteral other = (JsonLiteral)object;
    return value.equals(other.value);
  }
}
/*******************************************************************************
 * Copyright (c) 2013, 2015 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

@SuppressWarnings("serial")  // use default serial UID
class JsonNumber extends JsonValue {
  private final String string;

  JsonNumber(String string) {
    if (string == null) {
      throw new NullPointerException("string is null");
    }
    this.string = string;
  }

  @Override
  public String toString() {
    return string;
  }

  @Override
  void write(JsonWriter writer) throws IOException {
    writer.writeNumber(string);
  }

  @Override
  public boolean isNumber() {
    return true;
  }

  @Override
  public int asInt() {
    return Integer.parseInt(string, 10);
  }

  @Override
  public long asLong() {
    return Long.parseLong(string, 10);
  }

  @Override
  public float asFloat() {
    return Float.parseFloat(string);
  }

  @Override
  public double asDouble() {
    return Double.parseDouble(string);
  }

  @Override
  public int hashCode() {
    return string.hashCode();
  }

  @Override
  public boolean equals(Object object) {
    if (this == object) {
      return true;
    }
    if (object == null) {
      return false;
    }
    if (getClass() != object.getClass()) {
      return false;
    }
    JsonNumber other = (JsonNumber)object;
    return string.equals(other.string);
  }
}
/*******************************************************************************
 * Copyright (c) 2013, 2015 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * Represents a JSON object, a set of name/value pairs, where the names are
 * strings and the values
 * are JSON values.
 * <p>
 * Members can be added using the <code>add(String, ...)</code> methods which
 * accept instances of
 * {@link JsonValue}, strings, primitive numbers, and boolean values. To modify
 * certain values of an
 * object, use the <code>set(String, ...)</code> methods. Please note that the
 * <code>add</code>
 * methods are faster than <code>set</code> as they do not search for existing
 * members. On the other
 * hand, the <code>add</code> methods do not prevent adding multiple members
 * with the same name.
 * Duplicate names are discouraged but not prohibited by JSON.
 * </p>
 * <p>
 * Members can be accessed by their name using {@link #get(String)}. A list of
 * all names can be
 * obtained from the method {@link #names()}. This class also supports iterating
 * over the members in
 * document order using an {@link #iterator()} or an enhanced for loop:
 * </p>
 * <pre>
 * for (Member member : jsonObject) {
 *   String name = member.getName();
 *   JsonValue value = member.getValue();
 *   ...
 * }
 * </pre>
 * <p>
 * Even though JSON objects are unordered by definition, instances of this class
 * preserve the order
 * of members to allow processing in document order and to guarantee a
 * predictable output.
 * </p>
 * <p>
 * Note that this class is <strong>not thread-safe</strong>. If multiple threads
 * access a
 * <code>JsonObject</code> instance concurrently, while at least one of these
 * threads modifies the
 * contents of this object, access to the instance must be synchronized
 * externally. Failure to do so
 * may lead to an inconsistent state.
 * </p>
 * <p>
 * This class is <strong>not supposed to be extended</strong> by clients.
 * </p>
 */
@SuppressWarnings("serial")  // use default serial UID
class JsonObject extends JsonValue implements Iterable<Member> {
  private final List<String> names;
  private final List<JsonValue> values;
  private transient HashIndexTable table;

  /**
   * Creates a new empty JsonObject.
   */
  public JsonObject() {
    names = new ArrayList<String>();
    values = new ArrayList<JsonValue>();
    table = new HashIndexTable();
  }

  /**
   * Creates a new JsonObject, initialized with the contents of the specified
   * JSON object.
   *
   * @param object
   *          the JSON object to get the initial contents from, must not be
   * <code>null</code>
   */
  public JsonObject(JsonObject object) { this(object, false); }

  private JsonObject(JsonObject object, boolean unmodifiable) {
    if (object == null) {
      throw new NullPointerException("object is null");
    }
    if (unmodifiable) {
      names = Collections.unmodifiableList(object.names);
      values = Collections.unmodifiableList(object.values);
    } else {
      names = new ArrayList<String>(object.names);
      values = new ArrayList<JsonValue>(object.values);
    }
    table = new HashIndexTable();
    updateHashIndex();
  }

  /**
   * Reads a JSON object from the given reader.
   * <p>
   * Characters are read in chunks and buffered internally, therefore wrapping
   * an existing reader in
   * an additional <code>BufferedReader</code> does <strong>not</strong> improve
   * reading
   * performance.
   * </p>
   *
   * @param reader
   *          the reader to read the JSON object from
   * @return the JSON object that has been read
   * @throws IOException
   *           if an I/O error occurs in the reader
   * @throws ParseException
   *           if the input is not valid JSON
   * @throws UnsupportedOperationException
   *           if the input does not contain a JSON object
   * @deprecated Use {@link Json#parse(Reader)}{@link JsonValue#asObject()
   * .asObject()} instead
   */
  @Deprecated
  public static JsonObject readFrom(Reader reader) throws IOException {
    return JsonValue.readFrom(reader).asObject();
  }

  /**
   * Reads a JSON object from the given string.
   *
   * @param string
   *          the string that contains the JSON object
   * @return the JSON object that has been read
   * @throws ParseException
   *           if the input is not valid JSON
   * @throws UnsupportedOperationException
   *           if the input does not contain a JSON object
   * @deprecated Use {@link Json#parse(String)}{@link JsonValue#asObject()
   * .asObject()} instead
   */
  @Deprecated
  public static JsonObject readFrom(String string) {
    return JsonValue.readFrom(string).asObject();
  }

  /**
   * Returns an unmodifiable JsonObject for the specified one. This method
   * allows to provide
   * read-only access to a JsonObject.
   * <p>
   * The returned JsonObject is backed by the given object and reflect changes
   * that happen to it.
   * Attempts to modify the returned JsonObject result in an
   * <code>UnsupportedOperationException</code>.
   * </p>
   *
   * @param object
   *          the JsonObject for which an unmodifiable JsonObject is to be
   * returned
   * @return an unmodifiable view of the specified JsonObject
   */
  public static JsonObject unmodifiableObject(JsonObject object) {
    return new JsonObject(object, true);
  }

  /**
   * Appends a new member to the end of this object, with the specified name and
   * the JSON
   * representation of the specified <code>int</code> value.
   * <p>
   * This method <strong>does not prevent duplicate names</strong>. Calling this
   * method with a name
   * that already exists in the object will append another member with the same
   * name. In order to
   * replace existing members, use the method <code>set(name, value)</code>
   * instead. However,
   * <strong> <em>add</em> is much faster than <em>set</em></strong> (because it
   * does not need to
   * search for existing members). Therefore <em>add</em> should be preferred
   * when constructing new
   * objects.
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject add(String name, int value) {
    add(name, Json.value(value));
    return this;
  }

  /**
   * Appends a new member to the end of this object, with the specified name and
   * the JSON
   * representation of the specified <code>long</code> value.
   * <p>
   * This method <strong>does not prevent duplicate names</strong>. Calling this
   * method with a name
   * that already exists in the object will append another member with the same
   * name. In order to
   * replace existing members, use the method <code>set(name, value)</code>
   * instead. However,
   * <strong> <em>add</em> is much faster than <em>set</em></strong> (because it
   * does not need to
   * search for existing members). Therefore <em>add</em> should be preferred
   * when constructing new
   * objects.
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject add(String name, long value) {
    add(name, Json.value(value));
    return this;
  }

  /**
   * Appends a new member to the end of this object, with the specified name and
   * the JSON
   * representation of the specified <code>float</code> value.
   * <p>
   * This method <strong>does not prevent duplicate names</strong>. Calling this
   * method with a name
   * that already exists in the object will append another member with the same
   * name. In order to
   * replace existing members, use the method <code>set(name, value)</code>
   * instead. However,
   * <strong> <em>add</em> is much faster than <em>set</em></strong> (because it
   * does not need to
   * search for existing members). Therefore <em>add</em> should be preferred
   * when constructing new
   * objects.
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject add(String name, float value) {
    add(name, Json.value(value));
    return this;
  }

  /**
   * Appends a new member to the end of this object, with the specified name and
   * the JSON
   * representation of the specified <code>double</code> value.
   * <p>
   * This method <strong>does not prevent duplicate names</strong>. Calling this
   * method with a name
   * that already exists in the object will append another member with the same
   * name. In order to
   * replace existing members, use the method <code>set(name, value)</code>
   * instead. However,
   * <strong> <em>add</em> is much faster than <em>set</em></strong> (because it
   * does not need to
   * search for existing members). Therefore <em>add</em> should be preferred
   * when constructing new
   * objects.
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject add(String name, double value) {
    add(name, Json.value(value));
    return this;
  }

  /**
   * Appends a new member to the end of this object, with the specified name and
   * the JSON
   * representation of the specified <code>boolean</code> value.
   * <p>
   * This method <strong>does not prevent duplicate names</strong>. Calling this
   * method with a name
   * that already exists in the object will append another member with the same
   * name. In order to
   * replace existing members, use the method <code>set(name, value)</code>
   * instead. However,
   * <strong> <em>add</em> is much faster than <em>set</em></strong> (because it
   * does not need to
   * search for existing members). Therefore <em>add</em> should be preferred
   * when constructing new
   * objects.
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject add(String name, boolean value) {
    add(name, Json.value(value));
    return this;
  }

  /**
   * Appends a new member to the end of this object, with the specified name and
   * the JSON
   * representation of the specified string.
   * <p>
   * This method <strong>does not prevent duplicate names</strong>. Calling this
   * method with a name
   * that already exists in the object will append another member with the same
   * name. In order to
   * replace existing members, use the method <code>set(name, value)</code>
   * instead. However,
   * <strong> <em>add</em> is much faster than <em>set</em></strong> (because it
   * does not need to
   * search for existing members). Therefore <em>add</em> should be preferred
   * when constructing new
   * objects.
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject add(String name, String value) {
    add(name, Json.value(value));
    return this;
  }

  /**
   * Appends a new member to the end of this object, with the specified name and
   * the specified JSON
   * value.
   * <p>
   * This method <strong>does not prevent duplicate names</strong>. Calling this
   * method with a name
   * that already exists in the object will append another member with the same
   * name. In order to
   * replace existing members, use the method <code>set(name, value)</code>
   * instead. However,
   * <strong> <em>add</em> is much faster than <em>set</em></strong> (because it
   * does not need to
   * search for existing members). Therefore <em>add</em> should be preferred
   * when constructing new
   * objects.
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add, must not be <code>null</code>
   * @return the object itself, to enable method chaining
   */
  public JsonObject add(String name, JsonValue value) {
    if (name == null) {
      throw new NullPointerException("name is null");
    }
    if (value == null) {
      throw new NullPointerException("value is null");
    }
    table.add(name, names.size());
    names.add(name);
    values.add(value);
    return this;
  }

  /**
   * Sets the value of the member with the specified name to the JSON
   * representation of the
   * specified <code>int</code> value. If this object does not contain a member
   * with this name, a
   * new member is added at the end of the object. If this object contains
   * multiple members with
   * this name, only the last one is changed.
   * <p>
   * This method should <strong>only be used to modify existing
   * objects</strong>. To fill a new
   * object with members, the method <code>add(name, value)</code> should be
   * preferred which is much
   * faster (as it does not need to search for existing members).
   * </p>
   *
   * @param name
   *          the name of the member to replace
   * @param value
   *          the value to set to the member
   * @return the object itself, to enable method chaining
   */
  public JsonObject set(String name, int value) {
    set(name, Json.value(value));
    return this;
  }

  /**
   * Sets the value of the member with the specified name to the JSON
   * representation of the
   * specified <code>long</code> value. If this object does not contain a member
   * with this name, a
   * new member is added at the end of the object. If this object contains
   * multiple members with
   * this name, only the last one is changed.
   * <p>
   * This method should <strong>only be used to modify existing
   * objects</strong>. To fill a new
   * object with members, the method <code>add(name, value)</code> should be
   * preferred which is much
   * faster (as it does not need to search for existing members).
   * </p>
   *
   * @param name
   *          the name of the member to replace
   * @param value
   *          the value to set to the member
   * @return the object itself, to enable method chaining
   */
  public JsonObject set(String name, long value) {
    set(name, Json.value(value));
    return this;
  }

  /**
   * Sets the value of the member with the specified name to the JSON
   * representation of the
   * specified <code>float</code> value. If this object does not contain a
   * member with this name, a
   * new member is added at the end of the object. If this object contains
   * multiple members with
   * this name, only the last one is changed.
   * <p>
   * This method should <strong>only be used to modify existing
   * objects</strong>. To fill a new
   * object with members, the method <code>add(name, value)</code> should be
   * preferred which is much
   * faster (as it does not need to search for existing members).
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject set(String name, float value) {
    set(name, Json.value(value));
    return this;
  }

  /**
   * Sets the value of the member with the specified name to the JSON
   * representation of the
   * specified <code>double</code> value. If this object does not contain a
   * member with this name, a
   * new member is added at the end of the object. If this object contains
   * multiple members with
   * this name, only the last one is changed.
   * <p>
   * This method should <strong>only be used to modify existing
   * objects</strong>. To fill a new
   * object with members, the method <code>add(name, value)</code> should be
   * preferred which is much
   * faster (as it does not need to search for existing members).
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject set(String name, double value) {
    set(name, Json.value(value));
    return this;
  }

  /**
   * Sets the value of the member with the specified name to the JSON
   * representation of the
   * specified <code>boolean</code> value. If this object does not contain a
   * member with this name,
   * a new member is added at the end of the object. If this object contains
   * multiple members with
   * this name, only the last one is changed.
   * <p>
   * This method should <strong>only be used to modify existing
   * objects</strong>. To fill a new
   * object with members, the method <code>add(name, value)</code> should be
   * preferred which is much
   * faster (as it does not need to search for existing members).
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject set(String name, boolean value) {
    set(name, Json.value(value));
    return this;
  }

  /**
   * Sets the value of the member with the specified name to the JSON
   * representation of the
   * specified string. If this object does not contain a member with this name,
   * a new member is
   * added at the end of the object. If this object contains multiple members
   * with this name, only
   * the last one is changed.
   * <p>
   * This method should <strong>only be used to modify existing
   * objects</strong>. To fill a new
   * object with members, the method <code>add(name, value)</code> should be
   * preferred which is much
   * faster (as it does not need to search for existing members).
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add
   * @return the object itself, to enable method chaining
   */
  public JsonObject set(String name, String value) {
    set(name, Json.value(value));
    return this;
  }

  /**
   * Sets the value of the member with the specified name to the specified JSON
   * value. If this
   * object does not contain a member with this name, a new member is added at
   * the end of the
   * object. If this object contains multiple members with this name, only the
   * last one is changed.
   * <p>
   * This method should <strong>only be used to modify existing
   * objects</strong>. To fill a new
   * object with members, the method <code>add(name, value)</code> should be
   * preferred which is much
   * faster (as it does not need to search for existing members).
   * </p>
   *
   * @param name
   *          the name of the member to add
   * @param value
   *          the value of the member to add, must not be <code>null</code>
   * @return the object itself, to enable method chaining
   */
  public JsonObject set(String name, JsonValue value) {
    if (name == null) {
      throw new NullPointerException("name is null");
    }
    if (value == null) {
      throw new NullPointerException("value is null");
    }
    int index = indexOf(name);
    if (index != -1) {
      values.set(index, value);
    } else {
      table.add(name, names.size());
      names.add(name);
      values.add(value);
    }
    return this;
  }

  /**
   * Removes a member with the specified name from this object. If this object
   * contains multiple
   * members with the given name, only the last one is removed. If this object
   * does not contain a
   * member with the specified name, the object is not modified.
   *
   * @param name
   *          the name of the member to remove
   * @return the object itself, to enable method chaining
   */
  public JsonObject remove(String name) {
    if (name == null) {
      throw new NullPointerException("name is null");
    }
    int index = indexOf(name);
    if (index != -1) {
      table.remove(index);
      names.remove(index);
      values.remove(index);
    }
    return this;
  }

  /**
   * Copies all members of the specified object into this object. When the
   * specified object contains
   * members with names that also exist in this object, the existing values in
   * this object will be
   * replaced by the corresponding values in the specified object.
   *
   * @param object
   *          the object to merge
   * @return the object itself, to enable method chaining
   */
  public JsonObject merge(JsonObject object) {
    if (object == null) {
      throw new NullPointerException("object is null");
    }
    for (Member member : object) {
      this.set(member.getName(), member.getValue());
    }
    return this;
  }

  /**
   * Returns the value of the member with the specified name in this object. If
   * this object contains
   * multiple members with the given name, this method will return the last one.
   *
   * @param name
   *          the name of the member whose value is to be returned
   * @return the value of the last member with the specified name, or
   * <code>null</code> if this
   *         object does not contain a member with that name
   */
  public JsonValue get(String name) {
    if (name == null) {
      throw new NullPointerException("name is null");
    }
    int index = indexOf(name);
    return index != -1 ? values.get(index) : null;
  }

  /**
   * Returns the <code>int</code> value of the member with the specified name in
   * this object. If
   * this object does not contain a member with this name, the given default
   * value is returned. If
   * this object contains multiple members with the given name, the last one
   * will be picked. If this
   * member's value does not represent a JSON number or if it cannot be
   * interpreted as Java
   * <code>int</code>, an exception is thrown.
   *
   * @param name
   *          the name of the member whose value is to be returned
   * @param defaultValue
   *          the value to be returned if the requested member is missing
   * @return the value of the last member with the specified name, or the given
   * default value if
   *         this object does not contain a member with that name
   */
  public int getInt(String name, int defaultValue) {
    JsonValue value = get(name);
    return value != null ? value.asInt() : defaultValue;
  }

  /**
   * Returns the <code>long</code> value of the member with the specified name
   * in this object. If
   * this object does not contain a member with this name, the given default
   * value is returned. If
   * this object contains multiple members with the given name, the last one
   * will be picked. If this
   * member's value does not represent a JSON number or if it cannot be
   * interpreted as Java
   * <code>long</code>, an exception is thrown.
   *
   * @param name
   *          the name of the member whose value is to be returned
   * @param defaultValue
   *          the value to be returned if the requested member is missing
   * @return the value of the last member with the specified name, or the given
   * default value if
   *         this object does not contain a member with that name
   */
  public long getLong(String name, long defaultValue) {
    JsonValue value = get(name);
    return value != null ? value.asLong() : defaultValue;
  }

  /**
   * Returns the <code>float</code> value of the member with the specified name
   * in this object. If
   * this object does not contain a member with this name, the given default
   * value is returned. If
   * this object contains multiple members with the given name, the last one
   * will be picked. If this
   * member's value does not represent a JSON number or if it cannot be
   * interpreted as Java
   * <code>float</code>, an exception is thrown.
   *
   * @param name
   *          the name of the member whose value is to be returned
   * @param defaultValue
   *          the value to be returned if the requested member is missing
   * @return the value of the last member with the specified name, or the given
   * default value if
   *         this object does not contain a member with that name
   */
  public float getFloat(String name, float defaultValue) {
    JsonValue value = get(name);
    return value != null ? value.asFloat() : defaultValue;
  }

  /**
   * Returns the <code>double</code> value of the member with the specified name
   * in this object. If
   * this object does not contain a member with this name, the given default
   * value is returned. If
   * this object contains multiple members with the given name, the last one
   * will be picked. If this
   * member's value does not represent a JSON number or if it cannot be
   * interpreted as Java
   * <code>double</code>, an exception is thrown.
   *
   * @param name
   *          the name of the member whose value is to be returned
   * @param defaultValue
   *          the value to be returned if the requested member is missing
   * @return the value of the last member with the specified name, or the given
   * default value if
   *         this object does not contain a member with that name
   */
  public double getDouble(String name, double defaultValue) {
    JsonValue value = get(name);
    return value != null ? value.asDouble() : defaultValue;
  }

  /**
   * Returns the <code>boolean</code> value of the member with the specified
   * name in this object. If
   * this object does not contain a member with this name, the given default
   * value is returned. If
   * this object contains multiple members with the given name, the last one
   * will be picked. If this
   * member's value does not represent a JSON <code>true</code> or
   * <code>false</code> value, an
   * exception is thrown.
   *
   * @param name
   *          the name of the member whose value is to be returned
   * @param defaultValue
   *          the value to be returned if the requested member is missing
   * @return the value of the last member with the specified name, or the given
   * default value if
   *         this object does not contain a member with that name
   */
  public boolean getBoolean(String name, boolean defaultValue) {
    JsonValue value = get(name);
    return value != null ? value.asBoolean() : defaultValue;
  }

  /**
   * Returns the <code>String</code> value of the member with the specified name
   * in this object. If
   * this object does not contain a member with this name, the given default
   * value is returned. If
   * this object contains multiple members with the given name, the last one is
   * picked. If this
   * member's value does not represent a JSON string, an exception is thrown.
   *
   * @param name
   *          the name of the member whose value is to be returned
   * @param defaultValue
   *          the value to be returned if the requested member is missing
   * @return the value of the last member with the specified name, or the given
   * default value if
   *         this object does not contain a member with that name
   */
  public String getString(String name, String defaultValue) {
    JsonValue value = get(name);
    return value != null ? value.asString() : defaultValue;
  }

  /**
   * Returns the number of members (name/value pairs) in this object.
   *
   * @return the number of members in this object
   */
  public int size() { return names.size(); }

  /**
   * Returns <code>true</code> if this object contains no members.
   *
   * @return <code>true</code> if this object contains no members
   */
  public boolean isEmpty() { return names.isEmpty(); }

  /**
   * Returns a list of the names in this object in document order. The returned
   * list is backed by
   * this object and will reflect subsequent changes. It cannot be used to
   * modify this object.
   * Attempts to modify the returned list will result in an exception.
   *
   * @return a list of the names in this object
   */
  public List<String> names() { return Collections.unmodifiableList(names); }

  /**
   * Returns an iterator over the members of this object in document order. The
   * returned iterator
   * cannot be used to modify this object.
   *
   * @return an iterator over the members of this object
   */
  public Iterator<Member> iterator() {
    final Iterator<String> namesIterator = names.iterator();
    final Iterator<JsonValue> valuesIterator = values.iterator();
    return new Iterator<Member>() {

      public boolean hasNext() { return namesIterator.hasNext(); }

      public Member next() {
        String name = namesIterator.next();
        JsonValue value = valuesIterator.next();
        return new Member(name, value);
      }

      public void remove() { throw new UnsupportedOperationException(); }

    };
  }

  @Override
  void write(JsonWriter writer) throws IOException {
    writer.writeObjectOpen();
    Iterator<String> namesIterator = names.iterator();
    Iterator<JsonValue> valuesIterator = values.iterator();
    if (namesIterator.hasNext()) {
      writer.writeMemberName(namesIterator.next());
      writer.writeMemberSeparator();
      valuesIterator.next().write(writer);
      while (namesIterator.hasNext()) {
        writer.writeObjectSeparator();
        writer.writeMemberName(namesIterator.next());
        writer.writeMemberSeparator();
        valuesIterator.next().write(writer);
      }
    }
    writer.writeObjectClose();
  }

  @Override
  public boolean isObject() {
    return true;
  }

  @Override
  public JsonObject asObject() {
    return this;
  }

  @Override
  public int hashCode() {
    int result = 1;
    result = 31 * result + names.hashCode();
    result = 31 * result + values.hashCode();
    return result;
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) {
      return true;
    }
    if (obj == null) {
      return false;
    }
    if (getClass() != obj.getClass()) {
      return false;
    }
    JsonObject other = (JsonObject)obj;
    return names.equals(other.names) && values.equals(other.values);
  }

  int indexOf(String name) {
    int index = table.get(name);
    if (index != -1 && name.equals(names.get(index))) {
      return index;
    }
    return names.lastIndexOf(name);
  }

  private synchronized void readObject(ObjectInputStream inputStream)
      throws IOException, ClassNotFoundException {
    inputStream.defaultReadObject();
    table = new HashIndexTable();
    updateHashIndex();
  }

  private void updateHashIndex() {
    int size = names.size();
    for (int i = 0; i < size; i++) {
      table.add(names.get(i), i);
    }
  }

  static class HashIndexTable {
    private final byte[] hashTable = new byte[32];  // must be a power of two

    public HashIndexTable() {}

    public HashIndexTable(HashIndexTable original) {
      System.arraycopy(original.hashTable, 0, hashTable, 0, hashTable.length);
    }

    void add(String name, int index) {
      int slot = hashSlotFor(name);
      if (index < 0xff) {
        // increment by 1, 0 stands for empty
        hashTable[slot] = (byte)(index + 1);
      } else {
        hashTable[slot] = 0;
      }
    }

    void remove(int index) {
      for (int i = 0; i < hashTable.length; i++) {
        if (hashTable[i] == index + 1) {
          hashTable[i] = 0;
        } else if (hashTable[i] > index + 1) {
          hashTable[i]--;
        }
      }
    }

    int get(Object name) {
      int slot = hashSlotFor(name);
      // subtract 1, 0 stands for empty
      return (hashTable[slot] & 0xff) - 1;
    }

    private int hashSlotFor(Object element) {
      return element.hashCode() & hashTable.length - 1;
    }
  }
}
/*******************************************************************************
 * Copyright (c) 2013, 2016 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * A streaming parser for JSON text. The parser reports all events to a given
 * handler.
 */
class JsonParser {
  private static final int MAX_NESTING_LEVEL = 1000;
  private static final int MIN_BUFFER_SIZE = 10;
  private static final int DEFAULT_BUFFER_SIZE = 1024;

  private final JsonHandler<Object, Object> handler;
  private Reader reader;
  private char[] buffer;
  private int bufferOffset;
  private int index;
  private int fill;
  private int line;
  private int lineOffset;
  private int current;
  private StringBuilder captureBuffer;
  private int captureStart;
  private int nestingLevel;

  /*
   * |                      bufferOffset
   *                        v
   * [a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t]        < input
   *                       [l|m|n|o|p|q|r|s|t|?|?]    < buffer
   *                          ^               ^
   *                       |  index           fill
   */

  /**
   * Creates a new JsonParser with the given handler. The parser will report all
   * parser events to
   * this handler.
   *
   * @param handler
   *          the handler to process parser events
   */
  @SuppressWarnings("unchecked")
  public JsonParser(JsonHandler<?, ?> handler) {
    if (handler == null) {
      throw new NullPointerException("handler is null");
    }
    this.handler = (JsonHandler<Object, Object>)handler;
    handler.parser = this;
  }

  /**
   * Parses the given input string. The input must contain a valid JSON value,
   * optionally padded
   * with whitespace.
   *
   * @param string
   *          the input string, must be valid JSON
   * @throws ParseException
   *           if the input is not valid JSON
   */
  public void parse(String string) {
    if (string == null) {
      throw new NullPointerException("string is null");
    }
    int bufferSize = Math.max(MIN_BUFFER_SIZE,
                              Math.min(DEFAULT_BUFFER_SIZE, string.length()));
    try {
      parse(new StringReader(string), bufferSize);
    } catch (IOException exception) {
      // StringReader does not throw IOException
      throw new RuntimeException(exception);
    }
  }

  /**
   * Reads the entire input from the given reader and parses it as JSON. The
   * input must contain a
   * valid JSON value, optionally padded with whitespace.
   * <p>
   * Characters are read in chunks into a default-sized input buffer. Hence,
   * wrapping a reader in an
   * additional <code>BufferedReader</code> likely won't improve reading
   * performance.
   * </p>
   *
   * @param reader
   *          the reader to read the input from
   * @throws IOException
   *           if an I/O error occurs in the reader
   * @throws ParseException
   *           if the input is not valid JSON
   */
  public void parse(Reader reader) throws IOException {
    parse(reader, DEFAULT_BUFFER_SIZE);
  }

  /**
   * Reads the entire input from the given reader and parses it as JSON. The
   * input must contain a
   * valid JSON value, optionally padded with whitespace.
   * <p>
   * Characters are read in chunks into an input buffer of the given size.
   * Hence, wrapping a reader
   * in an additional <code>BufferedReader</code> likely won't improve reading
   * performance.
   * </p>
   *
   * @param reader
   *          the reader to read the input from
   * @param buffersize
   *          the size of the input buffer in chars
   * @throws IOException
   *           if an I/O error occurs in the reader
   * @throws ParseException
   *           if the input is not valid JSON
   */
  public void parse(Reader reader, int buffersize) throws IOException {
    if (reader == null) {
      throw new NullPointerException("reader is null");
    }
    if (buffersize <= 0) {
      throw new IllegalArgumentException("buffersize is zero or negative");
    }
    this.reader = reader;
    buffer = new char[buffersize];
    bufferOffset = 0;
    index = 0;
    fill = 0;
    line = 1;
    lineOffset = 0;
    current = 0;
    captureStart = -1;
    read();
    skipWhiteSpace();
    readValue();
    skipWhiteSpace();
    if (!isEndOfText()) {
      throw error("Unexpected character");
    }
  }

  private void readValue() throws IOException {
    switch (current) {
      case 'n':
        readNull();
        break;
      case 't':
        readTrue();
        break;
      case 'f':
        readFalse();
        break;
      case '"':
        readString();
        break;
      case '[':
        readArray();
        break;
      case '{':
        readObject();
        break;
      case '-':
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        readNumber();
        break;
      default:
        throw expected("value");
    }
  }

  private void readArray() throws IOException {
    Object array = handler.startArray();
    read();
    if (++nestingLevel > MAX_NESTING_LEVEL) {
      throw error("Nesting too deep");
    }
    skipWhiteSpace();
    if (readChar(']')) {
      nestingLevel--;
      handler.endArray(array);
      return;
    }
    do {
      skipWhiteSpace();
      handler.startArrayValue(array);
      readValue();
      handler.endArrayValue(array);
      skipWhiteSpace();
    } while (readChar(','));
    if (!readChar(']')) {
      throw expected("',' or ']'");
    }
    nestingLevel--;
    handler.endArray(array);
  }

  private void readObject() throws IOException {
    Object object = handler.startObject();
    read();
    if (++nestingLevel > MAX_NESTING_LEVEL) {
      throw error("Nesting too deep");
    }
    skipWhiteSpace();
    if (readChar('}')) {
      nestingLevel--;
      handler.endObject(object);
      return;
    }
    do {
      skipWhiteSpace();
      handler.startObjectName(object);
      String name = readName();
      handler.endObjectName(object, name);
      skipWhiteSpace();
      if (!readChar(':')) {
        throw expected("':'");
      }
      skipWhiteSpace();
      handler.startObjectValue(object, name);
      readValue();
      handler.endObjectValue(object, name);
      skipWhiteSpace();
    } while (readChar(','));
    if (!readChar('}')) {
      throw expected("',' or '}'");
    }
    nestingLevel--;
    handler.endObject(object);
  }

  private String readName() throws IOException {
    if (current != '"') {
      throw expected("name");
    }
    return readStringInternal();
  }

  private void readNull() throws IOException {
    handler.startNull();
    read();
    readRequiredChar('u');
    readRequiredChar('l');
    readRequiredChar('l');
    handler.endNull();
  }

  private void readTrue() throws IOException {
    handler.startBoolean();
    read();
    readRequiredChar('r');
    readRequiredChar('u');
    readRequiredChar('e');
    handler.endBoolean(true);
  }

  private void readFalse() throws IOException {
    handler.startBoolean();
    read();
    readRequiredChar('a');
    readRequiredChar('l');
    readRequiredChar('s');
    readRequiredChar('e');
    handler.endBoolean(false);
  }

  private void readRequiredChar(char ch) throws IOException {
    if (!readChar(ch)) {
      throw expected("'" + ch + "'");
    }
  }

  private void readString() throws IOException {
    handler.startString();
    handler.endString(readStringInternal());
  }

  private String readStringInternal() throws IOException {
    read();
    startCapture();
    while (current != '"') {
      if (current == '\\') {
        pauseCapture();
        readEscape();
        startCapture();
      } else if (current < 0x20) {
        throw expected("valid string character");
      } else {
        read();
      }
    }
    String string = endCapture();
    read();
    return string;
  }

  private void readEscape() throws IOException {
    read();
    switch (current) {
      case '"':
      case '/':
      case '\\':
        captureBuffer.append((char)current);
        break;
      case 'b':
        captureBuffer.append('\b');
        break;
      case 'f':
        captureBuffer.append('\f');
        break;
      case 'n':
        captureBuffer.append('\n');
        break;
      case 'r':
        captureBuffer.append('\r');
        break;
      case 't':
        captureBuffer.append('\t');
        break;
      case 'u':
        char[] hexChars = new char[4];
        for (int i = 0; i < 4; i++) {
          read();
          if (!isHexDigit()) {
            throw expected("hexadecimal digit");
          }
          hexChars[i] = (char)current;
        }
        captureBuffer.append((char)Integer.parseInt(new String(hexChars), 16));
        break;
      default:
        throw expected("valid escape sequence");
    }
    read();
  }

  private void readNumber() throws IOException {
    handler.startNumber();
    startCapture();
    readChar('-');
    int firstDigit = current;
    if (!readDigit()) {
      throw expected("digit");
    }
    if (firstDigit != '0') {
      while (readDigit()) {
      }
    }
    readFraction();
    readExponent();
    handler.endNumber(endCapture());
  }

  private boolean readFraction() throws IOException {
    if (!readChar('.')) {
      return false;
    }
    if (!readDigit()) {
      throw expected("digit");
    }
    while (readDigit()) {
    }
    return true;
  }

  private boolean readExponent() throws IOException {
    if (!readChar('e') && !readChar('E')) {
      return false;
    }
    if (!readChar('+')) {
      readChar('-');
    }
    if (!readDigit()) {
      throw expected("digit");
    }
    while (readDigit()) {
    }
    return true;
  }

  private boolean readChar(char ch) throws IOException {
    if (current != ch) {
      return false;
    }
    read();
    return true;
  }

  private boolean readDigit() throws IOException {
    if (!isDigit()) {
      return false;
    }
    read();
    return true;
  }

  private void skipWhiteSpace() throws IOException {
    while (isWhiteSpace()) {
      read();
    }
  }

  private void read() throws IOException {
    if (index == fill) {
      if (captureStart != -1) {
        captureBuffer.append(buffer, captureStart, fill - captureStart);
        captureStart = 0;
      }
      bufferOffset += fill;
      fill = reader.read(buffer, 0, buffer.length);
      index = 0;
      if (fill == -1) {
        current = -1;
        index++;
        return;
      }
    }
    if (current == '\n') {
      line++;
      lineOffset = bufferOffset + index;
    }
    current = buffer[index++];
  }

  private void startCapture() {
    if (captureBuffer == null) {
      captureBuffer = new StringBuilder();
    }
    captureStart = index - 1;
  }

  private void pauseCapture() {
    int end = current == -1 ? index : index - 1;
    captureBuffer.append(buffer, captureStart, end - captureStart);
    captureStart = -1;
  }

  private String endCapture() {
    int start = captureStart;
    int end = index - 1;
    captureStart = -1;
    if (captureBuffer.length() > 0) {
      captureBuffer.append(buffer, start, end - start);
      String captured = captureBuffer.toString();
      captureBuffer.setLength(0);
      return captured;
    }
    return new String(buffer, start, end - start);
  }

  Location getLocation() {
    int offset = bufferOffset + index - 1;
    int column = offset - lineOffset + 1;
    return new Location(offset, line, column);
  }

  private ParseException expected(String expected) {
    if (isEndOfText()) {
      return error("Unexpected end of input");
    }
    return error("Expected " + expected);
  }

  private ParseException error(String message) {
    return new ParseException(message, getLocation());
  }

  private boolean isWhiteSpace() {
    return current == ' ' || current == '\t' || current == '\n' ||
        current == '\r';
  }

  private boolean isDigit() { return current >= '0' && current <= '9'; }

  private boolean isHexDigit() {
    return current >= '0' && current <= '9' ||
        current >= 'a' && current <= 'f' || current >= 'A' && current <= 'F';
  }

  private boolean isEndOfText() { return current == -1; }
}
/*******************************************************************************
 * Copyright (c) 2013, 2015 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

@SuppressWarnings("serial")  // use default serial UID
class JsonString extends JsonValue {
  private final String string;

  JsonString(String string) {
    if (string == null) {
      throw new NullPointerException("string is null");
    }
    this.string = string;
  }

  @Override
  void write(JsonWriter writer) throws IOException {
    writer.writeString(string);
  }

  @Override
  public boolean isString() {
    return true;
  }

  @Override
  public String asString() {
    return string;
  }

  @Override
  public int hashCode() {
    return string.hashCode();
  }

  @Override
  public boolean equals(Object object) {
    if (this == object) {
      return true;
    }
    if (object == null) {
      return false;
    }
    if (getClass() != object.getClass()) {
      return false;
    }
    JsonString other = (JsonString)object;
    return string.equals(other.string);
  }
}
/*******************************************************************************
 * Copyright (c) 2013, 2016 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * Represents a JSON value. This can be a JSON <strong>object</strong>, an
 * <strong> array</strong>,
 * a <strong>number</strong>, a <strong>string</strong>, or one of the literals
 * <strong>true</strong>, <strong>false</strong>, and <strong>null</strong>.
 * <p>
 * The literals <strong>true</strong>, <strong>false</strong>, and
 * <strong>null</strong> are
 * represented by the constants {@link #TRUE}, {@link #FALSE}, and {@link
 * #NULL}.
 * </p>
 * <p>
 * JSON <strong>objects</strong> and <strong>arrays</strong> are represented by
 * the subtypes
 * {@link JsonObject} and {@link JsonArray}. Instances of these types can be
 * created using the
 * public constructors of these classes.
 * </p>
 * <p>
 * Instances that represent JSON <strong>numbers</strong>,
 * <strong>strings</strong> and
 * <strong>boolean</strong> values can be created using the static factory
 * methods
 * {@link #valueOf(String)}, {@link #valueOf(long)}, {@link #valueOf(double)},
 * etc.
 * </p>
 * <p>
 * In order to find out whether an instance of this class is of a certain type,
 * the methods
 * {@link #isObject()}, {@link #isArray()}, {@link #isString()}, {@link
 * #isNumber()} etc. can be
 * used.
 * </p>
 * <p>
 * If the type of a JSON value is known, the methods {@link #asObject()}, {@link
 * #asArray()},
 * {@link #asString()}, {@link #asInt()}, etc. can be used to get this value
 * directly in the
 * appropriate target type.
 * </p>
 * <p>
 * This class is <strong>not supposed to be extended</strong> by clients.
 * </p>
 */
@SuppressWarnings("serial")  // use default serial UID
abstract class JsonValue implements Serializable {
  /**
   * Represents the JSON literal <code>true</code>.
   * @deprecated Use <code>Json.TRUE</code> instead
   */
  @Deprecated public static final JsonValue TRUE = new JsonLiteral("true");

  /**
   * Represents the JSON literal <code>false</code>.
   * @deprecated Use <code>Json.FALSE</code> instead
   */
  @Deprecated public static final JsonValue FALSE = new JsonLiteral("false");

  /**
   * Represents the JSON literal <code>null</code>.
   * @deprecated Use <code>Json.NULL</code> instead
   */
  @Deprecated public static final JsonValue NULL = new JsonLiteral("null");

  JsonValue() {}

  /**
   * Reads a JSON value from the given reader.
   * <p>
   * Characters are read in chunks and buffered internally, therefore wrapping
   * an existing reader in
   * an additional <code>BufferedReader</code> does <strong>not</strong> improve
   * reading
   * performance.
   * </p>
   *
   * @param reader
   *          the reader to read the JSON value from
   * @return the JSON value that has been read
   * @throws IOException
   *           if an I/O error occurs in the reader
   * @throws ParseException
   *           if the input is not valid JSON
   * @deprecated Use {@link Json#parse(Reader)} instead
   */
  @Deprecated
  public static JsonValue readFrom(Reader reader) throws IOException {
    return Json.parse(reader);
  }

  /**
   * Reads a JSON value from the given string.
   *
   * @param text
   *          the string that contains the JSON value
   * @return the JSON value that has been read
   * @throws ParseException
   *           if the input is not valid JSON
   * @deprecated Use {@link Json#parse(String)} instead
   */
  @Deprecated
  public static JsonValue readFrom(String text) {
    return Json.parse(text);
  }

  /**
   * Returns a JsonValue instance that represents the given <code>int</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   * @deprecated Use <code>Json.value()</code> instead
   */
  @Deprecated
  public static JsonValue valueOf(int value) {
    return Json.value(value);
  }

  /**
   * Returns a JsonValue instance that represents the given <code>long</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   * @deprecated Use <code>Json.value()</code> instead
   */
  @Deprecated
  public static JsonValue valueOf(long value) {
    return Json.value(value);
  }

  /**
   * Returns a JsonValue instance that represents the given <code>float</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   * @deprecated Use <code>Json.value()</code> instead
   */
  @Deprecated
  public static JsonValue valueOf(float value) {
    return Json.value(value);
  }

  /**
   * Returns a JsonValue instance that represents the given <code>double</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   * @deprecated Use <code>Json.value()</code> instead
   */
  @Deprecated
  public static JsonValue valueOf(double value) {
    return Json.value(value);
  }

  /**
   * Returns a JsonValue instance that represents the given string.
   *
   * @param string
   *          the string to get a JSON representation for
   * @return a JSON value that represents the given string
   * @deprecated Use <code>Json.value()</code> instead
   */
  @Deprecated
  public static JsonValue valueOf(String string) {
    return Json.value(string);
  }

  /**
   * Returns a JsonValue instance that represents the given <code>boolean</code>
   * value.
   *
   * @param value
   *          the value to get a JSON representation for
   * @return a JSON value that represents the given value
   * @deprecated Use <code>Json.value()</code> instead
   */
  @Deprecated
  public static JsonValue valueOf(boolean value) {
    return Json.value(value);
  }

  /**
   * Detects whether this value represents a JSON object. If this is the case,
   * this value is an
   * instance of {@link JsonObject}.
   *
   * @return <code>true</code> if this value is an instance of JsonObject
   */
  public boolean isObject() { return false; }

  /**
   * Detects whether this value represents a JSON array. If this is the case,
   * this value is an
   * instance of {@link JsonArray}.
   *
   * @return <code>true</code> if this value is an instance of JsonArray
   */
  public boolean isArray() { return false; }

  /**
   * Detects whether this value represents a JSON number.
   *
   * @return <code>true</code> if this value represents a JSON number
   */
  public boolean isNumber() { return false; }

  /**
   * Detects whether this value represents a JSON string.
   *
   * @return <code>true</code> if this value represents a JSON string
   */
  public boolean isString() { return false; }

  /**
   * Detects whether this value represents a boolean value.
   *
   * @return <code>true</code> if this value represents either the JSON literal
   * <code>true</code> or
   *         <code>false</code>
   */
  public boolean isBoolean() { return false; }

  /**
   * Detects whether this value represents the JSON literal <code>true</code>.
   *
   * @return <code>true</code> if this value represents the JSON literal
   * <code>true</code>
   */
  public boolean isTrue() { return false; }

  /**
   * Detects whether this value represents the JSON literal <code>false</code>.
   *
   * @return <code>true</code> if this value represents the JSON literal
   * <code>false</code>
   */
  public boolean isFalse() { return false; }

  /**
   * Detects whether this value represents the JSON literal <code>null</code>.
   *
   * @return <code>true</code> if this value represents the JSON literal
   * <code>null</code>
   */
  public boolean isNull() { return false; }

  /**
   * Returns this JSON value as {@link JsonObject}, assuming that this value
   * represents a JSON
   * object. If this is not the case, an exception is thrown.
   *
   * @return a JSONObject for this value
   * @throws UnsupportedOperationException
   *           if this value is not a JSON object
   */
  public JsonObject asObject() {
    throw new UnsupportedOperationException("Not an object: " + toString());
  }

  /**
   * Returns this JSON value as {@link JsonArray}, assuming that this value
   * represents a JSON array.
   * If this is not the case, an exception is thrown.
   *
   * @return a JSONArray for this value
   * @throws UnsupportedOperationException
   *           if this value is not a JSON array
   */
  public JsonArray asArray() {
    throw new UnsupportedOperationException("Not an array: " + toString());
  }

  /**
   * Returns this JSON value as an <code>int</code> value, assuming that this
   * value represents a
   * JSON number that can be interpreted as Java <code>int</code>. If this is
   * not the case, an
   * exception is thrown.
   * <p>
   * To be interpreted as Java <code>int</code>, the JSON number must neither
   * contain an exponent
   * nor a fraction part. Moreover, the number must be in the
   * <code>Integer</code> range.
   * </p>
   *
   * @return this value as <code>int</code>
   * @throws UnsupportedOperationException
   *           if this value is not a JSON number
   * @throws NumberFormatException
   *           if this JSON number can not be interpreted as <code>int</code>
   * value
   */
  public int asInt() {
    throw new UnsupportedOperationException("Not a number: " + toString());
  }

  /**
   * Returns this JSON value as a <code>long</code> value, assuming that this
   * value represents a
   * JSON number that can be interpreted as Java <code>long</code>. If this is
   * not the case, an
   * exception is thrown.
   * <p>
   * To be interpreted as Java <code>long</code>, the JSON number must neither
   * contain an exponent
   * nor a fraction part. Moreover, the number must be in the <code>Long</code>
   * range.
   * </p>
   *
   * @return this value as <code>long</code>
   * @throws UnsupportedOperationException
   *           if this value is not a JSON number
   * @throws NumberFormatException
   *           if this JSON number can not be interpreted as <code>long</code>
   * value
   */
  public long asLong() {
    throw new UnsupportedOperationException("Not a number: " + toString());
  }

  /**
   * Returns this JSON value as a <code>float</code> value, assuming that this
   * value represents a
   * JSON number. If this is not the case, an exception is thrown.
   * <p>
   * If the JSON number is out of the <code>Float</code> range, {@link
   * Float#POSITIVE_INFINITY} or
   * {@link Float#NEGATIVE_INFINITY} is returned.
   * </p>
   *
   * @return this value as <code>float</code>
   * @throws UnsupportedOperationException
   *           if this value is not a JSON number
   */
  public float asFloat() {
    throw new UnsupportedOperationException("Not a number: " + toString());
  }

  /**
   * Returns this JSON value as a <code>double</code> value, assuming that this
   * value represents a
   * JSON number. If this is not the case, an exception is thrown.
   * <p>
   * If the JSON number is out of the <code>Double</code> range, {@link
   * Double#POSITIVE_INFINITY} or
   * {@link Double#NEGATIVE_INFINITY} is returned.
   * </p>
   *
   * @return this value as <code>double</code>
   * @throws UnsupportedOperationException
   *           if this value is not a JSON number
   */
  public double asDouble() {
    throw new UnsupportedOperationException("Not a number: " + toString());
  }

  /**
   * Returns this JSON value as String, assuming that this value represents a
   * JSON string. If this
   * is not the case, an exception is thrown.
   *
   * @return the string represented by this value
   * @throws UnsupportedOperationException
   *           if this value is not a JSON string
   */
  public String asString() {
    throw new UnsupportedOperationException("Not a string: " + toString());
  }

  /**
   * Returns this JSON value as a <code>boolean</code> value, assuming that this
   * value is either
   * <code>true</code> or <code>false</code>. If this is not the case, an
   * exception is thrown.
   *
   * @return this value as <code>boolean</code>
   * @throws UnsupportedOperationException
   *           if this value is neither <code>true</code> or <code>false</code>
   */
  public boolean asBoolean() {
    throw new UnsupportedOperationException("Not a boolean: " + toString());
  }

  /**
   * Writes the JSON representation of this value to the given writer in its
   * minimal form, without
   * any additional whitespace.
   * <p>
   * Writing performance can be improved by using a {@link
   * java.io.BufferedWriter BufferedWriter}.
   * </p>
   *
   * @param writer
   *          the writer to write this value to
   * @throws IOException
   *           if an I/O error occurs in the writer
   */
  public void writeTo(Writer writer) throws IOException {
    writeTo(writer, WriterConfig.MINIMAL);
  }

  /**
   * Writes the JSON representation of this value to the given writer using the
   * given formatting.
   * <p>
   * Writing performance can be improved by using a {@link
   * java.io.BufferedWriter BufferedWriter}.
   * </p>
   *
   * @param writer
   *          the writer to write this value to
   * @param config
   *          a configuration that controls the formatting or <code>null</code>
   * for the minimal form
   * @throws IOException
   *           if an I/O error occurs in the writer
   */
  public void writeTo(Writer writer, WriterConfig config) throws IOException {
    if (writer == null) {
      throw new NullPointerException("writer is null");
    }
    if (config == null) {
      throw new NullPointerException("config is null");
    }
    WritingBuffer buffer = new WritingBuffer(writer, 128);
    write(config.createWriter(buffer));
    buffer.flush();
  }

  /**
   * Returns the JSON string for this value in its minimal form, without any
   * additional whitespace.
   * The result is guaranteed to be a valid input for the method {@link
   * #readFrom(String)} and to
   * create a value that is <em>equal</em> to this object.
   *
   * @return a JSON string that represents this value
   */
  @Override
  public String toString() {
    return toString(WriterConfig.MINIMAL);
  }

  /**
   * Returns the JSON string for this value using the given formatting.
   *
   * @param config
   *          a configuration that controls the formatting or <code>null</code>
   * for the minimal form
   * @return a JSON string that represents this value
   */
  public String toString(WriterConfig config) {
    StringWriter writer = new StringWriter();
    try {
      writeTo(writer, config);
    } catch (IOException exception) {
      // StringWriter does not throw IOExceptions
      throw new RuntimeException(exception);
    }
    return writer.toString();
  }

  /**
   * Indicates whether some other object is "equal to" this one according to the
   * contract specified
   * in {@link Object#equals(Object)}.
   * <p>
   * Two JsonValues are considered equal if and only if they represent the same
   * JSON text. As a
   * consequence, two given JsonObjects may be different even though they
   * contain the same set of
   * names with the same values, but in a different order.
   * </p>
   *
   * @param object
   *          the reference object with which to compare
   * @return true if this object is the same as the object argument; false
   * otherwise
   */
  @Override
  public boolean equals(Object object) {
    return super.equals(object);
  }

  @Override
  public int hashCode() {
    return super.hashCode();
  }

  abstract void write(JsonWriter writer) throws IOException;
}
/*******************************************************************************
 * Copyright (c) 2013, 2015 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

class JsonWriter {
  private static final int CONTROL_CHARACTERS_END = 0x001f;

  private static final char[] QUOT_CHARS = {'\\', '"'};
  private static final char[] BS_CHARS = {'\\', '\\'};
  private static final char[] LF_CHARS = {'\\', 'n'};
  private static final char[] CR_CHARS = {'\\', 'r'};
  private static final char[] TAB_CHARS = {'\\', 't'};
  // In JavaScript, U+2028 and U+2029 characters count as line endings and must
  // be encoded.
  // http://stackoverflow.com/questions/2965293/javascript-parse-error-on-u2028-unicode-character
  private static final char[] UNICODE_2028_CHARS = {'\\', 'u', '2',
                                                    '0',  '2', '8'};
  private static final char[] UNICODE_2029_CHARS = {'\\', 'u', '2',
                                                    '0',  '2', '9'};
  private static final char[] HEX_DIGITS = {'0', '1', '2', '3', '4', '5',
                                            '6', '7', '8', '9', 'a', 'b',
                                            'c', 'd', 'e', 'f'};

  protected final Writer writer;

  JsonWriter(Writer writer) { this.writer = writer; }

  protected void writeLiteral(String value) throws IOException {
    writer.write(value);
  }

  protected void writeNumber(String string) throws IOException {
    writer.write(string);
  }

  protected void writeString(String string) throws IOException {
    writer.write('"');
    writeJsonString(string);
    writer.write('"');
  }

  protected void writeArrayOpen() throws IOException { writer.write('['); }

  protected void writeArrayClose() throws IOException { writer.write(']'); }

  protected void writeArraySeparator() throws IOException { writer.write(','); }

  protected void writeObjectOpen() throws IOException { writer.write('{'); }

  protected void writeObjectClose() throws IOException { writer.write('}'); }

  protected void writeMemberName(String name) throws IOException {
    writer.write('"');
    writeJsonString(name);
    writer.write('"');
  }

  protected void writeMemberSeparator() throws IOException {
    writer.write(':');
  }

  protected void writeObjectSeparator() throws IOException {
    writer.write(',');
  }

  protected void writeJsonString(String string) throws IOException {
    int length = string.length();
    int start = 0;
    for (int index = 0; index < length; index++) {
      char[] replacement = getReplacementChars(string.charAt(index));
      if (replacement != null) {
        writer.write(string, start, index - start);
        writer.write(replacement);
        start = index + 1;
      }
    }
    writer.write(string, start, length - start);
  }

  private static char[] getReplacementChars(char ch) {
    if (ch > '\\') {
      if (ch < '\u2028' || ch > '\u2029') {
        // The lower range contains 'a' .. 'z'. Only 2 checks required.
        return null;
      }
      return ch == '\u2028' ? UNICODE_2028_CHARS : UNICODE_2029_CHARS;
    }
    if (ch == '\\') {
      return BS_CHARS;
    }
    if (ch > '"') {
      // This range contains '0' .. '9' and 'A' .. 'Z'. Need 3 checks to get
      // here.
      return null;
    }
    if (ch == '"') {
      return QUOT_CHARS;
    }
    if (ch > CONTROL_CHARACTERS_END) {
      return null;
    }
    if (ch == '\n') {
      return LF_CHARS;
    }
    if (ch == '\r') {
      return CR_CHARS;
    }
    if (ch == '\t') {
      return TAB_CHARS;
    }
    return new char[] {'\\',
                       'u',
                       '0',
                       '0',
                       HEX_DIGITS[ch >> 4 & 0x000f],
                       HEX_DIGITS[ch & 0x000f]};
  }
}
/*******************************************************************************
 * Copyright (c) 2016 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * An immutable object that represents a location in the parsed text.
 */
class Location {
  /**
   * The absolute character index, starting at 0.
   */
  public final int offset;

  /**
   * The line number, starting at 1.
   */
  public final int line;

  /**
   * The column number, starting at 1.
   */
  public final int column;

  Location(int offset, int line, int column) {
    this.offset = offset;
    this.column = column;
    this.line = line;
  }

  @Override
  public String toString() {
    return line + ":" + column;
  }

  @Override
  public int hashCode() {
    return offset;
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) {
      return true;
    }
    if (obj == null) {
      return false;
    }
    if (getClass() != obj.getClass()) {
      return false;
    }
    Location other = (Location)obj;
    return offset == other.offset && column == other.column &&
        line == other.line;
  }

} /*******************************************************************************
   * Copyright (c) 2013, 2016 EclipseSource.
   *
   * Permission is hereby granted, free of charge, to any person obtaining a
   *copy of this software and associated documentation files (the "Software"),
   *to deal in the Software without restriction, including without limitation
   *the rights to use, copy, modify, merge, publish, distribute, sublicense,
   *and/or sell copies of the Software, and to permit persons to whom the
   *Software is furnished to do so, subject to the following conditions:
   *
   * The above copyright notice and this permission notice shall be included in
   *all
   * copies or substantial portions of the Software.
   *
   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   *FROM,
   * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   *THE
   * SOFTWARE.
   ******************************************************************************/

/**
 * An unchecked exception to indicate that an input does not qualify as valid
 * JSON.
 */
@SuppressWarnings("serial")  // use default serial UID
class ParseException extends RuntimeException {
  private final Location location;

  ParseException(String message, Location location) {
    super(message + " at " + location);
    this.location = location;
  }

  /**
   * Returns the location at which the error occurred.
   *
   * @return the error location
   */
  public Location getLocation() { return location; }

  /**
   * Returns the absolute character index at which the error occurred. The
   * offset of the first
   * character of a document is 0.
   *
   * @return the character offset at which the error occurred, will be &gt;= 0
   * @deprecated Use {@link #getLocation()} instead
   */
  @Deprecated
  public int getOffset() {
    return location.offset;
  }

  /**
   * Returns the line number in which the error occurred. The number of the
   * first line is 1.
   *
   * @return the line in which the error occurred, will be &gt;= 1
   * @deprecated Use {@link #getLocation()} instead
   */
  @Deprecated
  public int getLine() {
    return location.line;
  }

  /**
   * Returns the column number at which the error occurred, i.e. the number of
   * the character in its
   * line. The number of the first character of a line is 1.
   *
   * @return the column in which the error occurred, will be &gt;= 1
   * @deprecated Use {@link #getLocation()} instead
   */
  @Deprecated
  public int getColumn() {
    return location.column;
  }
}
/*******************************************************************************
 * Copyright (c) 2015 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * Enables human readable JSON output by inserting whitespace between
 * values.after commas and
 * colons. Example:
 *
 * <pre>
 * jsonValue.writeTo(writer, PrettyPrint.singleLine());
 * </pre>
 */
class PrettyPrint extends WriterConfig {
  private final char[] indentChars;

  protected PrettyPrint(char[] indentChars) { this.indentChars = indentChars; }

  /**
   * Print every value on a separate line. Use tabs (<code>\t</code>) for
   * indentation.
   *
   * @return A PrettyPrint instance for wrapped mode with tab indentation
   */
  public static PrettyPrint singleLine() { return new PrettyPrint(null); }

  /**
   * Print every value on a separate line. Use the given number of spaces for
   * indentation.
   *
   * @param number
   *          the number of spaces to use
   * @return A PrettyPrint instance for wrapped mode with spaces indentation
   */
  public static PrettyPrint indentWithSpaces(int number) {
    if (number < 0) {
      throw new IllegalArgumentException("number is negative");
    }
    char[] chars = new char[number];
    Arrays.fill(chars, ' ');
    return new PrettyPrint(chars);
  }

  /**
   * Do not break lines, but still insert whitespace between values.
   *
   * @return A PrettyPrint instance for single-line mode
   */
  public static PrettyPrint indentWithTabs() {
    return new PrettyPrint(new char[] {'\t'});
  }

  @Override
  protected JsonWriter createWriter(Writer writer) {
    return new PrettyPrintWriter(writer, indentChars);
  }

  private static class PrettyPrintWriter extends JsonWriter {
    private final char[] indentChars;
    private int indent;

    private PrettyPrintWriter(Writer writer, char[] indentChars) {
      super(writer);
      this.indentChars = indentChars;
    }

    @Override
    protected void writeArrayOpen() throws IOException {
      indent++;
      writer.write('[');
      writeNewLine();
    }

    @Override
    protected void writeArrayClose() throws IOException {
      indent--;
      writeNewLine();
      writer.write(']');
    }

    @Override
    protected void writeArraySeparator() throws IOException {
      writer.write(',');
      if (!writeNewLine()) {
        writer.write(' ');
      }
    }

    @Override
    protected void writeObjectOpen() throws IOException {
      indent++;
      writer.write('{');
      writeNewLine();
    }

    @Override
    protected void writeObjectClose() throws IOException {
      indent--;
      writeNewLine();
      writer.write('}');
    }

    @Override
    protected void writeMemberSeparator() throws IOException {
      writer.write(':');
      writer.write(' ');
    }

    @Override
    protected void writeObjectSeparator() throws IOException {
      writer.write(',');
      if (!writeNewLine()) {
        writer.write(' ');
      }
    }

    private boolean writeNewLine() throws IOException {
      if (indentChars == null) {
        return false;
      }
      writer.write('\n');
      for (int i = 0; i < indent; i++) {
        writer.write(indentChars);
      }
      return true;
    }
  }
}
/*******************************************************************************
 * Copyright (c) 2015 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * Controls the formatting of the JSON output. Use one of the available
 * constants.
 */
abstract class WriterConfig {
  /**
   * Write JSON in its minimal form, without any additional whitespace. This is
   * the default.
   */
  public static WriterConfig MINIMAL = new WriterConfig() {
    @Override
    JsonWriter createWriter(Writer writer) {
      return new JsonWriter(writer);
    }
  };

  /**
   * Write JSON in pretty-print, with each value on a separate line and an
   * indentation of two
   * spaces.
   */
  public static WriterConfig PRETTY_PRINT = PrettyPrint.indentWithSpaces(2);

  abstract JsonWriter createWriter(Writer writer);
}
/*******************************************************************************
 * Copyright (c) 2015 EclipseSource.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * A lightweight writing buffer to reduce the amount of write operations to be
 * performed on the
 * underlying writer. This implementation is not thread-safe. It deliberately
 * deviates from the
 * contract of Writer. In particular, it does not flush or close the wrapped
 * writer nor does it
 * ensure that the wrapped writer is open.
 */
class WritingBuffer extends Writer {
  private final Writer writer;
  private final char[] buffer;
  private int fill = 0;

  WritingBuffer(Writer writer) { this(writer, 16); }

  WritingBuffer(Writer writer, int bufferSize) {
    this.writer = writer;
    buffer = new char[bufferSize];
  }

  @Override
  public void write(int c) throws IOException {
    if (fill > buffer.length - 1) {
      flush();
    }
    buffer[fill++] = (char)c;
  }

  @Override
  public void write(char[] cbuf, int off, int len) throws IOException {
    if (fill > buffer.length - len) {
      flush();
      if (len > buffer.length) {
        writer.write(cbuf, off, len);
        return;
      }
    }
    System.arraycopy(cbuf, off, buffer, fill, len);
    fill += len;
  }

  @Override
  public void write(String str, int off, int len) throws IOException {
    if (fill > buffer.length - len) {
      flush();
      if (len > buffer.length) {
        writer.write(str, off, len);
        return;
      }
    }
    str.getChars(off, off + len, buffer, fill);
    fill += len;
  }

  /**
   * Flushes the internal buffer but does not flush the wrapped writer.
   */
  @Override
  public void flush() throws IOException {
    writer.write(buffer, 0, fill);
    fill = 0;
  }

  /**
   * Does not close or flush the wrapped writer.
   */
  @Override
  public void close() throws IOException {}
}

/**
 * Represents a member of a JSON object, a pair of a name and a value.
 */
class Member {
  private final String name;
  private final JsonValue value;

  Member(String name, JsonValue value) {
    this.name = name;
    this.value = value;
  }

  /**
   * Returns the name of this member.
   *
   * @return the name of this member, never <code>null</code>
   */
  public String getName() { return name; }

  /**
   * Returns the value of this member.
   *
   * @return the value of this member, never <code>null</code>
   */
  public JsonValue getValue() { return value; }

  @Override
  public int hashCode() {
    int result = 1;
    result = 31 * result + name.hashCode();
    result = 31 * result + value.hashCode();
    return result;
  }

  /**
   * Indicates whether a given object is "equal to" this JsonObject. An object
   * is considered equal
   * if it is also a <code>JsonObject</code> and both objects contain the same
   * members <em>in
   * the same order</em>.
   * <p>
   * If two JsonObjects are equal, they will also produce the same JSON output.
   * </p>
   *
   * @param object
   *          the object to be compared with this JsonObject
   * @return <tt>true</tt> if the specified object is equal to this JsonObject,
   * <code>false</code>
   *         otherwise
   */
  @Override
  public boolean equals(Object object) {
    if (this == object) {
      return true;
    }
    if (object == null) {
      return false;
    }
    if (getClass() != object.getClass()) {
      return false;
    }
    Member other = (Member)object;
    return name.equals(other.name) && value.equals(other.value);
  }
}
