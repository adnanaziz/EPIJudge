package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SwapBits {
    @EpiTest(testDataFile = "swap_bits.tsv")
    public static long swapBits(long x, int i, int j) {
        return swapBitsV2(x, i, j);
    }

    private static long swapBitsV1(long x, int i, int j) {
        // TODO - you fill in here.
        //if both bits have same state(set/unset), no swap is required.
        // if different,
        //  0    0 -> same
        //  1    0 -> diff
        //  xor with 11: 10 xor 11 -> 01
        //  xor with 11: 01 xor 11 -> 10
        long iMask = 0x1L << i;
        long jMask = 0x1L << j;

        long iState = (x & iMask) >> i;
        long jState = (x & jMask) >> j;

        if (iState == jState) return x;

        if (iState == 1) {
            x = x & ~iMask;
            x = x | jMask;
            return x;
        } else { //if (iState == 0) {
            x = x | iMask;
            x = x & ~jMask;
            return x;
        }
    }

    private static long swapBitsV2(long x, int i, int j) {
        if ((x >> i & 1) == (x >> j & 1)) { //same
            return x;
        }

        /*
         XOR (^)
          F F -> F
          T F -> T
          F T -> T
          T T -> F
          Dont confuse with Nand (Not-And) which is Inverse of AND Or NOR (Not OR)
         NAND:
          F F -> T
          T F -> T
          F T -> T
          T T -> F
         bitmask ((0x1 << i | 0x1 << j)) -- is set on both and j
          Eg:     i   j
             0x00010001000 - bit mask
             0xYYY1YYY0YYY -- possible
             0xYYY0YYY1YYY -- possible
             0xYYY1YYY1YYY -- not possible
             0xYYY0YYY0YYY -- not possible
             x             ^ bitmask       => Result
             0xYYY1YYY0YYY ^ 0x00010001000 => 0xYYY0YYY1YYY
             0xYYY0YYY1YYY ^ 0x00010001000 => 0xYYY1YYY0YYY

         */
        return x ^ (0x1L << i | 0x1L << j);

    }

    public static void main(String[] args) {
        System.exit(
                GenericTest
                        .runFromAnnotations(args, "SwapBits.java",
                                new Object() {
                                }.getClass().getEnclosingClass())
                        .ordinal());
    }
}
