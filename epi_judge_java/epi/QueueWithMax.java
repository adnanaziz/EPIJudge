package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;

import java.util.List;
import java.util.NoSuchElementException;

public class QueueWithMax {

  public void enqueue(Integer x) {
    // Implement this placeholder.
    return;
  }

  public Integer dequeue() {
    // Implement this placeholder.
    return 0;
  }

  public Integer max() {
    // Implement this placeholder.
    return 0;
  }

  @EpiUserType(ctorParams = {String.class, int.class})
  public static class QueueOp {
    public String op;
    public int arg;

    public QueueOp(String op, int arg) {
      this.op = op;
      this.arg = arg;
    }
  }

  @EpiTest(testfile = "queue_with_max.tsv")
  public static void queueTest(List<QueueOp> ops) throws TestFailureException {
    try {
      QueueWithMax q = new QueueWithMax();

      for (QueueOp op : ops) {
        switch (op.op) {
        case "QueueWithMax":
          q = new QueueWithMax();
          break;
        case "enqueue":
          q.enqueue(op.arg);
          break;
        case "dequeue":
          int result = q.dequeue();
          if (result != op.arg) {
            throw new TestFailureException("Dequeue: expected " +
                                           String.valueOf(op.arg) + ", got " +
                                           String.valueOf(result));
          }
          break;
        case "max":
          int s = q.max();
          if (s != op.arg) {
            throw new TestFailureException("Max: expected " +
                                           String.valueOf(op.arg) + ", got " +
                                           String.valueOf(s));
          }
          break;
        }
      }
    } catch (NoSuchElementException e) {
      throw new TestFailureException("Unexpected NoSuchElement exception");
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
