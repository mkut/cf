import Control.Monad

solve []       = 0
solve [a]      = 0
solve (a:b:cs) = solve (b:cs) + d
   where dx = fromIntegral $ (a!!0) - (b!!0)
         dy = fromIntegral $ (a!!1) - (b!!1)
         d  = sqrt . abs $ dx * dx + dy * dy

main = do
   [n, k] <- fmap (map read . words) getLine
   lst <- forM [1..n] $ \_ -> fmap (map read . words) getLine :: IO [Int]
   print $ solve lst * k / 50

-- vim: set expandtab:
