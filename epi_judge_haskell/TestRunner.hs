{-# LANGUAGE NoImplicitPrelude #-}

module TestRunner 
    (
        goTest
    ,   Data(..)
    ,   TestCase
    ) where 

import EPIPrelude
import TestParser
import System.CPUTime

time :: IO a -> IO (a, Int)
time a = do 
    start <- getCPUTime
    v     <- a
    end   <- getCPUTime 
    let diff = (fromIntegral (end - start)) `div` (10^6)
    return (v,diff)

type TestCase = [Data]

goTest :: (Show a, Eq b, Show b) =>
        (a -> b)
    ->  (TestCase -> a)
    ->  (TestCase -> b)
    ->  String
    ->  IO ()
goTest f fin fout fileName = do 
    ts <- testCases fileName
    runTests f fin fout ts 

runTests :: (Show a, Eq b, Show b) => 
       (a -> b) 
    -> (TestCase -> a)
    -> (TestCase -> b)
    -> [TestCase] 
    -> IO ()
runTests f fin fout ts = runTests' [] 1 (length ts) f fin fout ts

color_yellow = "\x1b[33m"
color_end    = "\x1b[0m"

runTests' :: (Show a, Eq b, Show b) =>
        [Int]                    -- Run times of test cases
    ->  Int                      -- Test case number
    ->  Int                      -- Total number of test cases
    ->  (a -> b)                 -- Function to test 
    ->  (TestCase -> a)          -- Test case to function input
    ->  (TestCase -> b)          -- Test case to expected output
    ->  [TestCase]               -- List of test cases
    ->  IO ()                    
runTests' rts _ _ _ _ _ [] = do
    printf "\nAverage running time: %4d us" (sum rts `div` length rts)
    printf "\nMedian running time:  %4d us\n" (sort rts !! (length rts `div` 2))
    putStrLn . pack $ "*** You've passed ALL tests. Congratulations! ***"
    return ()
runTests' rts i n f fin fout (t:ts) = do
    let input            = fin t 
        expected         = fout t
    (res, rt) <- time $ return $ f input 
    if res == expected 
        then do
            printf "\rTest \x1b[32mPASSED\x1b[0m (%5d/%d) [%4d us]" i n rt 
            runTests' (rt:rts) (i+1) n f fin fout ts
        else printFailure i n t

printFailure :: Int -> Int -> TestCase -> IO ()
printFailure i n t = do 
    let Explanation expl = last t
    let ins = dropRight 2 t -- Dropping expected and explanation
    printf "\rTest \x1b[91mFAILED\x1b[0m (%5d/%d)\n" i n
    printf "%sArguments%s\n" color_yellow color_end
    forM_ ([(1::Int)..] `zip` ins) $ \(idx, x) -> do
        printf 
            "\t%sInput%d%s:     " 
            color_yellow 
            idx 
            color_end 
        putStrLn (pack (replicate 6 ' ') `append` pack (show x))
    printf "\n%sFailure info%s\n" color_yellow color_end
    printf "\t%sexplanation%s:" color_yellow color_end
    putStrLn (pack (replicate 6 ' ') `append` expl)
