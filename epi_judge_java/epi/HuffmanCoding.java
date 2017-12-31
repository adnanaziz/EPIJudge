package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class HuffmanCoding {
  @EpiUserType(ctorParams = {String.class, double.class})

  public static class CharWithFrequency {
    public char c;
    public double freq;
    public String code;

    public CharWithFrequency(String s, double freq) {
      if (s.length() != 1) {
        throw new RuntimeException(
            "CharWithFrequency parser: string length is not 1");
      }
      this.c = s.charAt(0);
      this.freq = freq;
    }
  }

  @EpiTest(testfile = "huffman_coding.tsv")

  public static Double huffmanEncoding(List<CharWithFrequency> symbols) {
    // Implement this placeholder.
    return 0.0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
