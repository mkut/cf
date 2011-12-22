import Data.List
import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe

readInt = fst . fromJust . C.readInt
readIntList = map readInt . C.words

listToTuple [a, b] = (a, b)

f (m, r) (_, b)
   | m > b     = (m, r+1)
   | otherwise = (b, r)

main = do
   input <- fmap (map (C.takeWhile (/='\r')) . C.lines) $ C.hGetContents stdin
   let n  = readInt $ head input
       ab = map (listToTuple . readIntList) (take n $ tail input)
   print . snd $ foldl' f (0, 0) (sort ab)


-- vim: set expandtab:
