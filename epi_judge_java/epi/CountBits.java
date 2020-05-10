package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class CountBits {
    @EpiTest(testDataFile = "count_bits.tsv")

    public static short countBits(int x) {
        // TODO - you fill in here.
        return countBitsV3(x);
    }

    private static short countBitsV1(int x) {
        int count = 0;
        while (x != 0) {
            count += (x & 0x1);
            x >>>= 1;
        }
        return (short) count;
    }

    private static short countBitsV2(int x) {
        int count = 0;
        while (x != 0) {
            int idx = x & 0B1111;
            count += bitTable[idx];
            x >>>= 4;
        }
        return (short) count;
    }

    /**
     * This one uses the 'fast' method to clear the LSB (lowest set-bit) using this method: x & (x-1)
     * <p>
     * Insight: clearing the LSB is O(1)
     * <p>
     * 1. Until we reach 0
     * - Clear the LSB (which means we find the lowest set-bit each iteration)
     * - Increment the counter in each loop
     * That way, we jump from set-bit to set-bit until we reach 0 (thereby avoid the iteration when the bits are not set)
     *
     * @see #isolateLowestSetBit
     */
    private static short countBitsV3(int x) {
        short count = 0;
        while (x != 0) {
            x &= (x - 1);
            count++;
        }
        return count;
    }

    private static int[] bitTable = {
            0,//0000 - 0
            1,//0001 - 1
            1,//0010 - 2
            2,//0011 - 3
            1,//0100 - 4
            2,//0101 - 5
            2,//0110 - 6
            3,//0111 - 7
            1,//1000 - 8
            2,//1001 - 9
            2,//1010 - 10
            3,//1011 - 11
            2,//1100 - 12
            3,//1101 - 13
            3,//1110 - 14
            4,//1111 - 15
    };


    /**
     * O(1) fast method for clearing Lowest set-bit (LSB)
     * x & (x- 1)
     */
    public static int clearLowestSetBitFastMethod(final int x) {
        // how the clear LSB works:
                       //if x = 0B11_10;
        int y = x - 1; // = 0B11_01;
        int z = x & y; // = 0B11_10 & 0B11_01  = 0B11_00 (which is same as 0B11_10 with LSB cleared)
        return z; // x & (x - 1)
    }

    public static short isolateLowestSetBit(final long x) {
        /*
        // how the isolation works
        int x = 0B11_10;
        int x_minus_one = 0B11_01; // x - 1
        int reverse(x_minus_one) = 0B00_10; //~(x-1)
        int x_bitwise-and_reverse(x_minus_one) =  (0B11_10 & 0B00_10) == 0B00_10; x & ~(x -1)
        */
        return (short) (x & ~(x - 1));
    }

    public static void main(String[] args) {
        System.exit(
                GenericTest
                        .runFromAnnotations(args, "CountBits.java",
                                new Object() {
                                }.getClass().getEnclosingClass())
                        .ordinal());
    }
}
