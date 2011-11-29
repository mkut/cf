import Data.Graph
import Data.Array
import Control.Monad

solve n e
   | length kicked == 0 = 0
   | otherwise = solve n e' + 1
   where g      = buildG (1, n) e
         kicked = [ i | i <- [1..n], indegree g ! i == 1 ]
         e'     = (\(x, y) -> not (elem x kicked || elem y kicked)) `filter` e

main = do
   [n, m] <- fmap (map read . words) getLine
   e <- fmap concat . forM [1..m] $ \_ -> fmap ((\[x,y] -> [(x,y),(y,x)]) . map read . words) getLine
   print $ solve n e


-- vim: set expandtab:
