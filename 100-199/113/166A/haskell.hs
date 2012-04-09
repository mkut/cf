import IO
import Data.List

main = print . solve =<< parse stdin

solve (n, k, pts) = length $ filter (==score) pts
   where
      score = sort pts !! (k-1)

parse h = do
   [n, k] <- readIntList h
   pts <- mapM (fmap f . readIntList) $ replicate n h
   return (n, k, pts)
   where
      f [a,b] = (-a, b)

-- lib
readIntList = fmap (map read . words) . hGetLine

-- vim: set expandtab:
