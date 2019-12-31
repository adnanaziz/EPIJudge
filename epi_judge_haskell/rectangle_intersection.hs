import TestParser

data Rectangle = Rectangle {
        _x :: Int
    ,   _y :: Int 
    ,   _width :: Int 
    ,   _height :: Int
    } deriving (Show, Eq)

intersectRectangle :: Rectangle -> Rectangle -> Rectangle
intersectRectangle r1 r2
    | r3x <= r3x' && r3y <= r3y' = Rectangle r3x r3y (r3x' - r3x) (r3y' - r3y)
    | otherwise = Rectangle 0 0 (-1) (-1) 
    where 
        r3x  = max (_x r1) (_x r2)
        r3x' = min (_x r1 + _width r1) (_x r2 + _width r2)
        r3y  = max (_y r1) (_y r2)
        r3y' = min (_y r1 + _height r1) (_y r2 + _height r2)

toRect :: Data -> Rectangle
toRect (TupleD _ [IntD _ x, IntD _ y, IntD _ w, IntD _ h]) = Rectangle x y w h

runTests :: [Int] -> [[Data]] -> IO () 
runTests rts [] = putStrLn "All tests passed" 
    >> putStrLn ("Average running time: " ++ show (sum rts `div` length rts) ++ "us")
    >> return ()
runTests rts (ts:rest) = do
    let [r1,r2,r3] = toRect <$> ts 
    (res, rt) <- time $ return $ intersectRectangle r1 r2
    if res == r3 
        then putStrLn "OK" >> runTests (rt:rts) rest 
        else do 
            putStrLn "Failed for test case shown below"
            putStrLn ("r1: " ++ show r1)
            putStrLn ("r2: " ++ show r2) 
            putStrLn ("expected: " ++ show r3) 
            putStrLn ("actual  : " ++ show res)

main = do
    ts <- testCases "../test_data/rectangle_intersection.tsv"
    runTests [] ts