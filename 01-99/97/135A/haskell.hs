import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.List

readInt = fst . fromJust . C.readInt
readIntList = map readInt . C.words

solve a
   | corner    = take (n-1) (repeat 1) ++ [2]
   | otherwise = (1:) . take (n-1) $ sort a
   where n      = length a
         corner = all (==1) a

main = do
   input <- fmap (map (C.takeWhile (/='\r')) . C.lines) $ C.hGetContents stdin
   putStrLn . unwords . map show . solve . readIntList $ input !! 1

-- vim: set expandtab:
