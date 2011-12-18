m3 = (`mod`3)
d3 = (`div`3)

solve 0 0 = 0
solve a c = m3 (3 + m3 c - m3 a) + 3 * solve (d3 a) (d3 c)

main = do
   [a, c] <- fmap (map read . words) getLine
   print $ solve a c

-- vim: set expandtab:
