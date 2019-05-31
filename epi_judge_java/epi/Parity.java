package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class Parity {
  public static short[] preComputedParity ;

  /**Brute Force Solution pg.27*/
  @EpiTest(testDataFile = "parity.tsv")
  public static short parity(long x) {
    // COMPLETE - you fill in here.
    boolean parity = true;
    while(x != 0){
      if((x&1) == 1){
        parity = !parity;
      }
      x = x>>1;
    }
    if(parity) return 0;
    return 1;
  }

  /**optimized brute force solution pg. 27*/
  @EpiTest(testDataFile = "parity.tsv")
  public static short parity1(long x){
    // COMPLETE - you fill in here.
   boolean parity = true;
   while(x!=0){
     x = x&(x-1);
     parity = !parity;
   }
   if(parity) return 0;
    return 1;
  }

  public static short getParity(int x){
    boolean parity = true;
    while(x != 0){
      if((x&1) == 1){
        parity = !parity;
      }
      x = x>>1;
    }
    if(parity) return 0;
    return 1;
  }

  /**using caching - table based approach pg. 28*/
  @EpiTest(testDataFile = "parity.tsv")
  public static short parity2(long x){
    // COMPLETE - you fill in here.
   if(preComputedParity == null){
     preComputedParity = new short[(int)Math.pow(2,16)];
     for(int i=0; i<=preComputedParity.length-1; i++){
       preComputedParity[i] = getParity(i);
     }
   }
    int MASK_SIZE = 16;
    int MASK = 0xFFFF;
    int pt1 = (int)(x&MASK);
    int pt2 = (int)((x>>>(1*MASK_SIZE))&MASK);
    int pt3 = (int)((x>>>(2*MASK_SIZE))&MASK);
    int pt4 = (int)((x>>>(3*MASK_SIZE))&MASK);
    int result = preComputedParity[pt1]^preComputedParity[pt2]^preComputedParity[pt3]^preComputedParity[pt4];
    return (short)result;
  }



  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "Parity.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
