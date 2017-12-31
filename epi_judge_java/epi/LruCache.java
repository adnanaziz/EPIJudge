package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;

import java.util.List;

public class LruCache {

  LruCache(final int capacity) {}

  public Integer lookup(Integer key) {
    // Implement this placeholder.
    return 0;
  }

  public void insert(Integer key, Integer value) {
    // Implement this placeholder.
    return;
  }

  public Boolean erase(Object key) {
    // Implement this placeholder.
    return true;
  }

  @EpiUserType(ctorParams = {String.class, int.class, int.class})
  public static class Op {
    String code;
    int arg1;
    int arg2;

    public Op(String code, int arg1, int arg2) {
      this.code = code;
      this.arg1 = arg1;
      this.arg2 = arg2;
    }
  }

  @EpiTest(testfile = "lru_cache.tsv")
  public static void runTest(List<Op> commands) throws TestFailureException {
    if (commands.isEmpty() || !commands.get(0).code.equals("LruCache")) {
      throw new RuntimeException("Expected LruCache as first command");
    }
    LruCache cache = new LruCache(commands.get(0).arg1);
    for (Op op : commands.subList(1, commands.size())) {
      int result;
      switch (op.code) {
      case "lookup":
        result = cache.lookup(op.arg1);
        if (result != op.arg2) {
          throw new TestFailureException("Lookup: expected " +
                                         String.valueOf(op.arg2) + ", got " +
                                         String.valueOf(result));
        }
        break;
      case "insert":
        cache.insert(op.arg1, op.arg2);
        break;
      case "erase":
        result = cache.erase(op.arg1) ? 1 : 0;
        if (result != op.arg2) {
          throw new TestFailureException("Erase: expected " +
                                         String.valueOf(op.arg2) + ", got " +
                                         String.valueOf(result));
        }
        break;
      default:
        throw new RuntimeException("Unexpected command " + op.code);
      }
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
