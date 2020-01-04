import TestRunner

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

fin :: TestCase -> (Rectangle, Rectangle)
fin c = let [r1,r2] = toRect <$> take 2 c in (r1,r2)

fout :: TestCase -> Rectangle
fout c = toRect (c !! 2)

main = 
    goTest 
        (uncurry intersectRectangle) 
        fin 
        fout
        "../test_data/rectangle_intersection.tsv"