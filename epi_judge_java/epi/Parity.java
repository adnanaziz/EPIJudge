package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class Parity {
    @EpiTest(testDataFile = "parity.tsv")
    public static short parity(long x) {
        // TODO - you fill in here.
        /**
         * Calculate parity using folding (because XOR is associative and commutative)
         * basic idea: For 64-bit integer, separate them into 2 32-bit integers and XOR them to get 1 32-bit integer
         * after that, fold them again (using XOR) as 2 16-bit integers
         * do it until you have only 1-bit integer - which would be the parity
         * Isolate the parity bit with and bitwise-and (&) with 0x1
         * Time complexity for this is: O(log(n)) where n is number of bits
         */
        x ^= x >>> 32; //unsigned shift (treats signed-bit as normal bit)
        x ^= x >>> 16; //these don't matter (could do signed shift '>>') because we are operating only on the last 32-bits
        x ^= x >>> 8;
        x ^= x >>> 4;
        x ^= x >>> 2;
        x ^= x >>> 1;
        return (short) (x & 1);
    }

    public static void main(String[] args) {
        System.exit(
                GenericTest
                        .runFromAnnotations(args, "Parity.java",
                                new Object() {
                                }.getClass().getEnclosingClass())
                        .ordinal());
    }
}
