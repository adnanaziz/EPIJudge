package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;

import java.util.List;

public class CircularQueue {

  public static class Queue {

    public Queue(int capacity) {}

    public void enqueue(Integer x) {
      // Implement this placeholder.
      return;
    }

    public Integer dequeue() {
      // Implement this placeholder.
      return 0;
    }

    public int size() {
      // Implement this placeholder.
      return 0;
    }
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

  @EpiTest(testfile = "circular_queue.tsv")
  public static void queueTest(List<QueueOp> ops) throws TestFailureException {
    Queue q = new Queue(1);

    for (QueueOp op : ops) {
      switch (op.op) {
      case "Queue":
        q = new Queue(op.arg);
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
      case "size":
        int s = q.size();
        if (s != op.arg) {
          throw new TestFailureException("Size: expected " +
                                         String.valueOf(op.arg) + ", got " +
                                         String.valueOf(s));
        }
        break;
      }
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
