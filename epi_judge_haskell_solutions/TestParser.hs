{-# LANGUAGE NoImplicitPrelude #-}

module TestParser 
    (
        p_tsv
    ,   Data (..) 
    ,   testCases
    ,   intData
    ,   longData
    ,   tuple3Data
    ,   tuple4Data
    ,   uncurry2
    ) where

import EPIPrelude
import Text.Parsec.Text
import Text.Parsec.Char
import Text.Parsec hiding ((<|>), many, optional)

type Name = String

data DataType = 
        TupleDT [DataType] Name
    |   IntDT (Maybe Name)
    |   LongDT (Maybe Name)
    deriving (Show)

data Data = 
        TupleD DataType [Data]
    |   IntD DataType Int
    |   LongD DataType Integer
    |   Explanation Text

instance Show Data where 
    show (TupleD _ ds)   = show ds 
    show (IntD _ x)      = show x
    show (LongD _ x)     = show x 
    show (Explanation x) = show x

p_dts :: Parser [DataType]
p_dts = p_dt `sepBy` tab

p_dt :: Parser DataType
p_dt = choice [
        p_tuple_dt
    ,   p_int_dt
    ,   p_long_dt
    ]
    <?> "Type"

p_d :: Bool -> Parser Char -> [DataType] -> Parser [Data] 
p_d True  _ [] = pure . Explanation . pack <$> (many . noneOf $ "\n\r") 
p_d False _ [] = return []
p_d parseExpl sep (dt@(TupleDT dts _):rest) = do
    [x] <- (p_tuple_d dt dts) `manyTill` (try sep)
    xs  <- p_d parseExpl sep rest 
    return (x:xs)
p_d parseExpl sep (dt@(IntDT _):rest) = do
    [x] <- case rest of
        [] -> pure <$> p_int
        _  -> p_int `manyTill` (try sep)
    xs  <- spaces *> p_d parseExpl sep rest 
    return (IntD dt (read x):xs)
p_d parseExpl sep (dt@(LongDT _):rest) = do 
    [x] <- case rest of
        [] -> pure <$> p_long
        _  -> p_int `manyTill` (try sep)
    xs  <- spaces *> p_d parseExpl sep rest 
    return (LongD dt (read x):xs)

p_int = (++) <$> option "" (string "-") <*> many1 digit

p_long = (++) <$> option "" (string "-") <*> many1 digit

p_tuple_dt = TupleDT
    <$> (string "tuple" 
     *> between (char '(') (char ')') ((spaces *> p_dt) `sepBy` (char ',')))
    <*> between (char '[') (char ']') (many . noneOf $ "[]")

p_tuple_d dt dts = TupleD dt 
    <$> between (char '[') (char ']') (p_d False (char ',') dts)

p_int_dt = IntDT <$> 
    (
        string "int" 
    *>  optional (between (char '[') (char ']') (many . noneOf $ "[]"))
    )

p_long_dt = LongDT <$>
    (
        string "long"
    *>  optional (between (char '[') (char ']') (many . noneOf $ "[]"))
    )

p_tsv = do 
    dts <- p_dts <* eol
    ds  <- p_d True tab dts `endBy` eol
    return (dts,ds)
eol   = try (string "\n\r")
    <|> try (string "\r\n")
    <|> string "\n"
    <|> string "\r"
    <?> "End of line"

testCases :: String -> IO [[Data]]
testCases fileName = do
    contents <- readFile fileName
    case parse p_tsv "" contents of 
        Left err     -> print err >> return [] 
        Right (_,cs) -> return cs

intData :: Data -> Int 
intData (IntD _ x) = x 

longData :: Data -> Integer
longData (LongD _ x) = x

tuple3Data :: Data -> (Data, Data, Data)
tuple3Data (TupleD _ [p,q,r]) = (p,q,r)

tuple4Data :: Data -> (Data, Data, Data, Data)
tuple4Data (TupleD _ [p,q,r,s]) = (p,q,r,s)

uncurry2 :: (a -> b -> c -> d) -> ((a,b,c) -> d)
uncurry2 f (x,y,z) = f x y z 