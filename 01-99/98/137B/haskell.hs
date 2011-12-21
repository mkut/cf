import Data.List
import Data.Array


main = do
   n <- fmap read getLine :: IO Int
   a <- fmap (map read . words) getLine :: IO [Int]
   print . length . filter id . elems $ accumArray (&&) True (1, n) [(i, False) | i <- a, i >= 1 && i <= n]

-- vim: set expandtab:
