package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MaxProductAllButOne {
  @EpiTest(testDataFile = "max_product_all_but_one.tsv")

  public static int findBiggestProductNMinusOneProduct(List<Integer> A) {

    // Builds suffix products.
    int product = 1;
    List<Integer> suffixProducts =
        new ArrayList<>(Collections.nCopies(A.size(), 0));
    for (int i = A.size() - 1; i >= 0; --i) {
      product *= A.get(i);
      suffixProducts.set(i, product);
    }

    // Finds the biggest product of (n - 1) numbers.
    int prefixProduct = 1;
    int maxProduct = Integer.MIN_VALUE;
    for (int i = 0; i < A.size(); ++i) {
      int suffixProduct = i + 1 < A.size() ? suffixProducts.get(i + 1) : 1;
      maxProduct = Math.max(maxProduct, prefixProduct * suffixProduct);
      prefixProduct *= A.get(i);
    }
    return maxProduct;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxProductAllButOne.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
