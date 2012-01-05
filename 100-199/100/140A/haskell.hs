import Data.Fixed

parse = map read . words . head . lines

solve' x y
   | x < y     = 0
   | x < y * 2 = 1
   | otherwise = pi `div'` (asin (fy / (fx - fy)) * eps1)
      where
         fx = fromIntegral x
         fy = fromIntegral y
         eps1 = 1 - 1e-8

solve :: [Int] -> Bool
solve [n, r1, r2] = n <= solve' r1 r2

showYN True  = "YES"
showYN False = "NO"

main = interact $ (++"\n") . showYN . solve . parse

-- vim: set expandtab:
