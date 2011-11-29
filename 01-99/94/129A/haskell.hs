main = do
   _ <- getLine
   ls <- fmap (map read . words) getLine
   let m2 = sum ls `mod` 2
   print . length $ filter ((==m2) . (`mod`2)) ls

-- vim: set expandtab:
