package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class PhoneNumberMnemonic {
  @EpiTest(testDataFile = "phone_number_mnemonic.tsv")

  public static List<String> phoneMnemonic(String phoneNumber) {

    List<String> mnemonics = new ArrayList<>();
    phoneMnemonicHelper(phoneNumber, 0, new char[phoneNumber.length()],
                        mnemonics);
    return mnemonics;
  }

  // The mapping from digit to corresponding characters.
  private static final String[] MAPPING = {"0",   "1",   "ABC",  "DEF", "GHI",
                                           "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

  private static void phoneMnemonicHelper(String phoneNumber, int digit,
                                          char[] partialMnemonic,
                                          List<String> mnemonics) {
    if (digit == phoneNumber.length()) {
      // All digits are processed, so add partialMnemonic to mnemonics.
      // (We add a copy since subsequent calls modify partialMnemonic.)
      mnemonics.add(new String(partialMnemonic));
    } else {
      // Try all possible characters for this digit.
      for (int i = 0; i < MAPPING[phoneNumber.charAt(digit) - '0'].length();
           ++i) {
        char c = MAPPING[phoneNumber.charAt(digit) - '0'].charAt(i);
        partialMnemonic[digit] = c;
        phoneMnemonicHelper(phoneNumber, digit + 1, partialMnemonic, mnemonics);
      }
    }
  }

  @EpiTestComparator
  public static boolean comp(List<String> expected, List<String> result) {
    if (result == null) {
      return false;
    }
    Collections.sort(expected);
    Collections.sort(result);
    return expected.equals(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "PhoneNumberMnemonic.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
