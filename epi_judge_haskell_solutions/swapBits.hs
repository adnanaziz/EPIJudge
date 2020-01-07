import TestRunner
import Data.Bits 

swapBits :: Integer -> Int -> Int -> Integer
swapBits x i j = 
    let x' = setBit i (getBit j x) x
    in  setBit j (getBit i x) x'
    where
        setBit i 1 y = y .|. (1 `shiftL` i)
        setBit i 0 y = y .&. (complement (1 `shiftL` i))
        getBit i y = (y `shiftR` i) .&. 1

main = goTest
    (uncurry2 swapBits)
    (\(x:y:z:_) -> (longData x, intData y, intData z))
    (\x -> longData (x !! 3))
    "../test_data/swap_bits.tsv"