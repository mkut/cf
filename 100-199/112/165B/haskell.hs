import System.IO

main = print . solve =<< parse stdin

parse h = fmap (f . map read . words) getLine
   where f [x,y] = (x,y)

solve :: (Int, Int) -> Int
solve (n,k) = solve' init
   where
      init = (0, 10^9)
      solve' (a, b)
         | a + 1 >= b = b
         | cnt >= n   = solve' (a, c)
         | otherwise  = solve' (c, b)
         where
            c   = (a + b) `div` 2
            cnt = count c
      count 0 = 0
      count v = v + count (v `div` k)

-- vim: set expandtab:
