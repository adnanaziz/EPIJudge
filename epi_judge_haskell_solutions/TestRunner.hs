{-# LANGUAGE NoImplicitPrelude #-}

module TestRunner 
    (
        goTest
    ,   TestCase
    ,   module TestParser
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

type Color = String

yellow   = "\x1b[33m"
colorEnd = "\x1b[0m"

printColored :: Color -> String -> IO () 
printColored c x = printf "%s%s%s" c x colorEnd

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
        else printFailure i n t expected res

printFailure :: (Show b) => Int -> Int -> TestCase -> b -> b -> IO ()
printFailure i n t expected result = do 
    let Explanation expl = last t
    let ins = dropRight 2 t -- Dropping expected and explanation
    printf "\rTest \x1b[91mFAILED\x1b[0m (%5d/%d)\n" i n
    printColored yellow "Arguments"
    printf "\n"
    forM_ ([(1::Int)..] `zip` ins) $ \(idx, x) -> do
        printf "\t"
        printColored yellow ("Input" ++ show idx)
        printf ":           "
        putStrLn (pack (show x))
    printf "\n"
    printColored yellow "Failure info"
    printf "\n\t"
    printColored yellow "explanation"
    putStrLn (pack ":      " `append` expl)
    printf "\t"
    printColored yellow "expected"
    printf ":         "
    printf "%s\n\t" (show expected)
    printColored yellow "result"
    printf ":           "
    printf "%s\n" (show result)
