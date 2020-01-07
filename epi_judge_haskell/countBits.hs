import TestRunner
import Data.Bits

countBits :: Int -> Int
countBits x = 0 -- TODO

fin :: TestCase -> Int 
fin (x:_) = intData x 

fout :: TestCase -> Int 
fout (_:x:_) = intData x 

main = 
    goTest
        countBits
        fin
        fout
        "../test_data/count_bits.tsv"