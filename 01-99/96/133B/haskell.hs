cnv '>' = 8
cnv '<' = 9
cnv '+' = 10
cnv '-' = 11
cnv '.' = 12
cnv ',' = 13
cnv '[' = 14
cnv ']' = 15
cnv _   = 0

f x y
   | cnv y == 0 = x
   | otherwise  = (x * 16 + cnv y) `mod` 1000003

main = interact $ (++"\n") . show . foldl f 0

-- vim: set expandtab:
