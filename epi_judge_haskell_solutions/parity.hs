import TestRunner 
import Data.Bits

parity :: Integer -> Int
parity x = 
    let p = x `xor` (x `shiftR` 32)
        q = p `xor` (p `shiftR` 16)
        r = q `xor` (q `shiftR` 8)
        s = r `xor` (r `shiftR` 4)
        t = s `xor` (s `shiftR` 2)
    in  fromIntegral $ (t `xor` (t `shiftR` 1)) .&. 1

main = goTest 
    parity 
    (longData . head) 
    (intData . head . tail) 
    "../test_data/parity.tsv"