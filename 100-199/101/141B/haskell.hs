main = print . solve . map read . words =<< getLine

solve [a, x, y]
   | z  == 0   = -1
   | y' == 0   = solve1 a x y'
   | odd y'    = solve1 a x y'
   | otherwise = solve2 a x y'
   where y' = y `div` a
         z  = y `mod` a

solve1 a x y'
   | abs x * 2 >= a = -1
   | otherwise      = y' `div` 2 * 3 + y' `mod` 2 + 1

solve2 _ 0 _ = -1
solve2 a x y'
   | abs x >= a = -1
   | x < 0      = base
   | otherwise  = base + 1
   where base = y' `div` 2 * 3

-- vim: set expandtab:
