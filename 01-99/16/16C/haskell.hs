solve :: [Int] -> [Int]
solve [a,b,x,y] = [x' * m, y' * m]
   where x' = x `div` gcd x y
         y' = y `div` gcd x y
         m  = min (a `div` x') (b `div` y')

main = interact $ (++"\n") . unwords . map show . solve . map read . words

-- vim: set expandtab:
