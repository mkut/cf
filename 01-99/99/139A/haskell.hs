solve n ((a,b):as)
   | n <= a    = b
   | otherwise = solve (n - a) as

main = do
   n <- fmap read getLine
   a <- fmap (map read . words) getLine
   let a' = cycle $ zip a [1..]
   print $ solve n a'

-- vim: set expandtab:
