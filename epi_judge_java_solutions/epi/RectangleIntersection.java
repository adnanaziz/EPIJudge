package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

public class RectangleIntersection {

  @EpiUserType(ctorParams = {int.class, int.class, int.class, int.class})
  public static class Rect {
    int x, y, width, height;

    public Rect(int x, int y, int width, int height) {
      this.x = x;
      this.y = y;
      this.width = width;
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

      if (x != rectangle.x) {
        return false;
      }
      if (y != rectangle.y) {
        return false;
      }
      if (width != rectangle.width) {
        return false;
      }
      return height == rectangle.height;
    }

    @Override
    public int hashCode() {
      int result = x;
      result = 31 * result + y;
      result = 31 * result + width;
      result = 31 * result + height;
      return result;
    }

    @Override
    public String toString() {
      return "[" + x + ", " + y + ", " + width + ", " + height + "]";
    }
  }

  @EpiTest(testDataFile = "rectangle_intersection.tsv")
  public static Rect intersectRectangle(Rect r1, Rect r2) {

    if (!isIntersect(r1, r2)) {
      return new Rect(0, 0, -1, -1); // No intersection.
    }
    return new Rect(
        Math.max(r1.x, r2.x), Math.max(r1.y, r2.y),
        Math.min(r1.x + r1.width, r2.x + r2.width) - Math.max(r1.x, r2.x),
        Math.min(r1.y + r1.height, r2.y + r2.height) - Math.max(r1.y, r2.y));
  }

  private static boolean isIntersect(Rect r1, Rect r2) {
    return r1.x <= r2.x + r2.width && r1.x + r1.width >= r2.x &&
        r1.y <= r2.y + r2.height && r1.y + r1.height >= r2.y;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RectangleIntersection.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
