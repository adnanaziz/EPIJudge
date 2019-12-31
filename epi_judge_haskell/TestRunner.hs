module TestRunner 
    (
        goTest
    ,   Data(..)
    ) where 
    
import TestParser
import System.CPUTime
import Text.Printf
import Data.List (sort)

time :: IO a -> IO (a, Int)
time a = do 
    start <- getCPUTime
    v     <- a
    end   <- getCPUTime 
    let diff = (fromIntegral (end - start)) `div` (10^6)
    return (v,diff)

goTest :: (Show a, Eq b, Show b) =>
        (a -> b)
    ->  ([Data] -> (a,b))
    ->  String
    ->  IO ()
goTest f cnv fileName = do 
    ts <- testCases fileName
    runTests f cnv ts 

runTests :: (Show a, Eq b, Show b) => 
        (a -> b) 
    -> ([Data] -> (a,b)) 
    -> [[Data]] 
    -> IO ()
runTests f cnv ts = runTests' [] 1 (length ts) f cnv ts

runTests' :: (Show a, Eq b, Show b) =>
        [Int]
    ->  Int 
    ->  Int
    ->  (a -> b)
    ->  ([Data] -> (a,b))
    ->  [[Data]]
    ->  IO ()
runTests' rts _ _ _ _ [] = do
    printf "\nAverage running time: %4d us" (sum rts `div` length rts)
    printf "\nMedian running time:  %4d us\n" (sort rts !! (length rts `div` 2))
    putStrLn "*** You've passed ALL tests. Congratulations! ***"
    return ()
runTests' rts i n f cnv (t:ts) = do 
    let (input,expected) = cnv t 
    (res, rt) <- time $ return $ f input 
    if res == expected 
        then do
            printf "\rTest \x1b[1;32;40mPASSED\x1b[0m (%d/%d) [%4d us]" i n rt 
--            putStr $ "\rTest \x1b[1;32;40mPASSED\x1b[0m (" ++ show i ++ "/" ++ show n ++ ") [" 
            runTests' (rt:rts) (i+1) n f cnv ts
        else do 
            putStrLn "Failed for test case shown below"
            putStrLn ("input: " ++ show input)
            putStrLn ("expected: " ++ show expected) 
            putStrLn ("actual  : " ++ show res)
