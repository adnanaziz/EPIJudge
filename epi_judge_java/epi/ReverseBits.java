package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ReverseBits {
    @EpiTest(testDataFile = "reverse_bits.tsv")
    public static long reverseBits(long x) {
        // TODO - you fill in here.
        return reverseBitsV1(x);
    }

    public static long reverseBitsV0(long x) {
        //[12345678] -> [87654321]
        //swapBits the bits to reverse it?
        for (int i = 0, j = 63; i < 32; i++, j--) {
            x = swapBits(x, i, j);
        }
        return x;
    }

    public static long reverseBitsV1(long x) {
        long byte0 = reverseByte(x, 7);
        long byte1 = reverseByte(x, 6);
        long byte2 = reverseByte(x, 5);
        long byte3 = reverseByte(x, 4);
        long byte4 = reverseByte(x, 3);
        long byte5 = reverseByte(x, 2);
        long byte6 = reverseByte(x, 1);
        long byte7 = reverseByte(x, 0);
        return (byte7 << 56)
                | (byte6 << 48)
                | (byte5 << 40)
                | (byte4 << 32)
                | (byte3 << 24)
                | (byte2 << 16)
                | (byte1 << 8)
                | (byte0)
                ;
    }

    private static int reverseByte(long x, int byteSection) {
        int shift = byteSection * 8;
        return reverseByte((byte) (x >>> shift));
    }

    private static int reverseByte(byte val) {
        int b0 = reverseBitsTable[(val >>> 6 & 0b11)]; //first 2-bit
        int b2 = reverseBitsTable[(val >>> 4) & 0b11]; // 2nd 2-bit
        int b4 = reverseBitsTable[(val >>> 2) & 0b11]; // 3rd 2-bit
        int b6 = reverseBitsTable[val & 0b11]; // 4th 2-bit
        return  ((b6 << 6) | (b4 << 4) | (b2 << 2) | (b0));
    }

    private static int[] reverseBitsTable = {
            0b00, //00 -> 00
            0b10, //01 -> 10
            0b01, //10 -> 01
            0b11, //11 -> 11
    };

    private static long swapBits(long x, int i, int j) {
        if ((x >> i & 1) == (x >> j & 1)) return x;

        return x ^ (0x1L << i | 0x1L << j);
    }

    public static void main(String[] args) {
        System.exit(
                GenericTest
                        .runFromAnnotations(args, "ReverseBits.java",
                                new Object() {
                                }.getClass().getEnclosingClass())
                        .ordinal());
    }
}
