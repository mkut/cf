import qualified Data.ByteString.Char8 as C
import IO
import Data.Maybe

main = print . solve =<< parse stdin
-- main = print . solve $ (215001, C.replicate (1000000) '1')

parse h = do
   input <- glines $ C.hGetContents h
   let k = readInt $ input !! 0
       s = input !! 1
   return (k, s)

solve (k, s)
   | k == 0 = sum $ map g z
   | k /= 0 = sum $ zipWith f z (drop k z)
   where
      z     = map C.length . C.split '1' $ s
      f x y = (x + 1) * (y + 1)
      g x   = x * (x + 1) `div` 2

-- lib

glines = fmap (map (C.takeWhile (/='\r')) . C.lines)
readInt = fst . fromJust . C.readInt
readIntList = map readInt . C.words

-- vim: set expandtab:
