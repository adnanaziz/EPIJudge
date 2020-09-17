package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;
import epi.test_framework.LexicographicalListComparator;

import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

import java.io.File;
import jnr.ffi.LibraryLoader;
import static java.lang.System.mapLibraryName;

public class Anagrams {
  public static interface RustLib {
      int double_input(int i);
  }

  public static String getLibraryPath(String dylib) {
      File f = new File(Anagrams.class.getClassLoader().getResource(mapLibraryName(dylib)).getFile());
      return f.getParent();
  }

  @EpiTest(testDataFile = "anagrams.tsv")

  public static List<List<String>> findAnagrams(List<String> dictionary) {
      String dylib = "rust_ffi";
      System.setProperty("jnr.ffi.library.path", getLibraryPath(dylib));
      RustLib rlib = LibraryLoader.create(RustLib.class).load(dylib);
      int r = rlib.double_input(20);
      System.out.println("Result from rust double_input:  " + r);
      return null;
  }
  @EpiTestComparator
  public static boolean comp(List<List<String>> expected,
          List<List<String>> result) {
      if (result == null) {
          return false;
      }
      for (List<String> l : expected) {
          Collections.sort(l);
      }
      expected.sort(new LexicographicalListComparator<>());
      for (List<String> l : result) {
          Collections.sort(l);
      }
      result.sort(new LexicographicalListComparator<>());
      return expected.equals(result);
  }

  public static void main(String[] args) {
      System.exit(
              GenericTest
              .runFromAnnotations(args, "Anagrams.java",
                  new Object() {}.getClass().getEnclosingClass())
              .ordinal());
  }
}
