package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
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

    int minLeft = Integer.MAX_VALUE, maxRight = Integer.MIN_VALUE;
    for (Rect building : buildings) {
      minLeft = Math.min(minLeft, building.left);
      maxRight = Math.max(maxRight, building.right);
    }

    List<Integer> heights =
        new ArrayList<>(Collections.nCopies(maxRight - minLeft + 1, 0));
    for (Rect building : buildings) {
      for (int i = building.left; i <= building.right; ++i) {
        heights.set(i - minLeft,
                    Math.max(heights.get(i - minLeft), building.height));
      }
    }

    List<Rect> result = new ArrayList<>();
    int left = 0;
    for (int i = 1; i < heights.size(); ++i) {
      if (heights.get(i) != heights.get(i - 1)) {
        result.add(
            new Rect(left + minLeft, i - 1 + minLeft, heights.get(i - 1)));
        left = i;
      }
    }
    result.add(
        new Rect(left + minLeft, maxRight, heights.get(heights.size() - 1)));
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DrawingSkyline.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
