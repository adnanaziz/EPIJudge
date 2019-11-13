package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.List;
public class DrawingSkyline {
  @EpiUserType(ctorParams = {int.class, int.class, int.class})

  public static class Rect {
    public int left, right, height;

    public Rect(int left, int right, int height) {
      this.left = left;
      this.right = right;
      this.height = height;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      Rect rectangle = (Rect)o;

      if (left != rectangle.left) {
        return false;
      }
      if (right != rectangle.right) {
        return false;
      }
      return height == rectangle.height;
    }

    @Override
    public String toString() {
      return "[" + left + ", " + right + ", " + height + ']';
    }
  }

  @EpiTest(testDataFile = "drawing_skyline.tsv")

  public static List<Rect> drawingSkylines(List<Rect> buildings) {
    // TODO - you fill in here.
    return null;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DrawingSkyline.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
