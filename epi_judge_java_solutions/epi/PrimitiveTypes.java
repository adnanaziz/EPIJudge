package epi;

public class PrimitiveTypes {
    public int rightPropagateRightMostSetBit(int x){
        return x | (x - 1);
    }
    public boolean isPowerOfTwo(long x){
        return (x & (x - 1)) == 0;
    }
}

class TDPrimitiveTypes{
    public static void main(String[] args) {
        System.out.println(new PrimitiveTypes().isPowerOfTwo(64));
        System.out.println(new PrimitiveTypes().rightPropagateRightMostSetBit(64));
    }
}
