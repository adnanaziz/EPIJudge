import TestRunner
import Data.Bits

countBits :: Int -> Int
countBits 0 = 0
countBits x
    | x .&. 1 == 1 = 1 + countBits (x `shiftR` 1)
    | otherwise    = countBits (x `shiftR` 1)

main = goTest 
    countBits 
    (intData . head) 
    (intData . head . tail) 
    "../test_data/count_bits.tsv"