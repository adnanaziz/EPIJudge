{-# LANGUAGE NoImplicitPrelude #-}

 module TestParser 
    (
        p_tsv
    ,   Data (..) 
    ,   testCases
    ,   time
    ) where

import System.CPUTime
import Data.Text hiding (head, take)
import Text.Parsec hiding ((<|>), many, optional)
import Text.Parsec.Text
import Text.Parsec.Char
import Text.Parsec.Combinator hiding (optional)
import Prelude (
        const
    ,   Maybe
    ,   (^)
    ,   (-)
    ,   div
    ,   fromIntegral
    ,   Bool( True )
    ,   Char
    ,   String
    ,   Either( Left )
    ,   Either( Right )
    ,   print
    ,   (.)
    ,   ($)
    ,   putStrLn
    ,   Show
    ,   Int
    ,   fst 
    ,   snd
    ,   Int
    ,   read
    ,   return
    ,   IO
    )
import Data.Text.IO (readFile)
import Data.List (head, (++), take)
import Control.Applicative

type Name = String

data DataType = 
        TupleDT [DataType] Name
    |   IntDT (Maybe Name)
    deriving (Show)

data Data = 
        TupleD DataType [Data]
    |   IntD DataType Int
    deriving (Show)

p_dts :: Parser [DataType]
p_dts = p_dt `sepBy` tab

p_dt :: Parser DataType
p_dt = choice [
        p_tuple_dt
    ,   p_int_dt
    ]
    <?> "Type"

p_d :: Parser Char -> [DataType] -> Parser [Data] 
p_d _ [] = return []
p_d sep (dt@(TupleDT dts _):rest) = do
    [x] <- (p_tuple_d dt dts) `manyTill` (try sep)
    xs  <- p_d sep rest 
    return (x:xs)
p_d sep (dt@(IntDT _):rest) = do
    [x] <- case rest of
        [] -> (\x -> [x]) <$> p_int
        _  -> p_int `manyTill` (try sep)
    xs  <- spaces *> p_d sep rest 
    return (IntD dt (read x):xs)

p_int = (++) <$> option "" (string "-") <*> many1 digit

p_tuple_dt = TupleDT
    <$> (string "tuple" 
     *> between (char '(') (char ')') ((spaces *> p_dt) `sepBy` (char ',')))
    <*> between (char '[') (char ']') (many . noneOf $ "[]")

p_tuple_d dt dts = TupleD dt 
    <$> between (char '[') (char ']') (p_d (char ',') dts)

p_int_dt = IntDT 
    <$> (string "int"
     *> optional (between (char '[') (char ']') (many . noneOf $ "[]")))

p_tsv = do 
    dts <- p_dts <* eol
    ds  <- p_d tab dts `endBy` (skipMany (noneOf "\n\r") *> eol) 
    return (dts,ds)
eol   = try (string "\n\r")
    <|> try (string "\r\n")
    <|> string "\n"
    <|> string "\r"
    <?> "End of line"

testCases :: String -> IO [[Data]]
testCases fileName = do
    contents <- readFile fileName
    let Right (_,cs)  = parse p_tsv "" contents
    return cs

time :: IO a -> IO (a, Int)
time a = do 
    start <- getCPUTime
    v     <- a
    end   <- getCPUTime 
    let diff = (fromIntegral (end - start)) `div` (10^6)
    return (v,diff)