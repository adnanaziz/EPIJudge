{-# LANGUAGE NoImplicitPrelude #-}

import Data.Text hiding (head)
import Text.Parsec hiding ((<|>), many, optional)
import Text.Parsec.Text
import Text.Parsec.Char
import Text.Parsec.Combinator hiding (optional)
import Prelude (
        const
    ,   Maybe
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
    )
import Data.Text.IO (readFile)
import Data.List (head)
import Control.Applicative

type Name = String

data DataType = 
        Tuple [DataType] Name
    |   Int (Maybe Name)
    deriving (Show)

p_types :: Parser [DataType]
p_types = p_type `sepBy` tab

p_type :: Parser DataType
p_type = choice [
        p_tuple
    ,   p_int
    ]
    <?> "Type"

p_tuple = Tuple 
      <$> (string "tuple" 
       *> between (char '(') (char ')') ((spaces *> p_type) `sepBy` (char ',')))
      <*> between (char '[') (char ']') (many . noneOf $ "[]")

p_int = Int 
    <$> (string "int"
     *> optional (between (char '[') (char ']') (many . noneOf $ "[]")))

p_tsv = (,) <$> (p_types <* eol) <*> (p_row `endBy` eol)
p_row = (many . noneOf $ "\n\r") `sepBy` tab
eol   = try (string "\n\r")
    <|> try (string "\r\n")
    <|> string "\n"
    <|> string "\r"
    <?> "End of line"

parseFile fileName = do 
    contents <- readFile fileName
    let res = parse p_tsv "" contents
    case res of 
        Left err -> print err 
        Right (types,cases) -> print types