{-# LANGUAGE NoImplicitPrelude #-}

module EPIPrelude 
    (
        module Prelude
    ,   module Text.Show 
    ,   module Text.Read
    ,   module Data.List 
    ,   module Data.Bool 
    ,   module Data.Maybe 
    ,   module Data.Either 
    ,   module Data.Text
    ,   module Data.Text.IO
    ,   module Data.Int
    ,   module Data.Char
    ,   module Control.Applicative
    ,   module Control.Monad
    ,   module System.IO
    ,   module Data.String
    ,   module Data.Function
    ,   module Data.Ord
    ,   module Data.Eq
    ,   module Text.Printf
    ,   dropRight
    ) where

import Prelude ((-), (+), div, (^), fromIntegral, (==))
import Text.Show (Show, show)
import Text.Read (read)
import Data.List
import Data.Bool (Bool(..))
import Data.Maybe (Maybe)
import Data.String (String)
import Data.Char (Char)
import Data.Either (Either(Left,Right))
import Data.Text (Text, pack, append)
import Data.Text.IO (readFile, putStrLn)
import Text.Printf (printf)
import Data.Int (Int)
import Data.Ord (Ord)
import Data.Eq (Eq)
import Data.Function (($), (.))
import Control.Applicative 
    (
        (<|>)
    ,   (<*)
    ,   (*>)
    ,   (<$>)
    ,   (<*>)
    ,   pure
    ,   optional
    ,   many
    )
import Control.Monad (return, (>>), forM_, forM, mapM_, mapM)
import System.IO (IO, print)

dropRight :: Int -> [a] -> [a] 
dropRight k xs = take (length xs - k) xs 