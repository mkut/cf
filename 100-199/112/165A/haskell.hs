import System.IO
import Data.Array

parse h = do
   n <- fmap read (hGetLine h)
   ps <- mapM f [1..n]
   return (n, ps)
   where
      f _ = fmap (g . map read . words) (hGetLine h)
      g [x,y] = (x,y)

solve (n, ps) = length $ filter f ps
   where
      f (x,y) =  left ! y /= x
              && right ! y /= x
              && bottom ! x /= y
              && top ! x /= y
      left    = accumArray min inf b ps'
      right   = accumArray max (-inf) b ps'
      bottom  = accumArray min inf b ps
      top     = accumArray max (-inf) b ps
      ps'     = map (\(x, y) -> (y, x)) ps
      b       = (-1000, 1000)
      inf     = 10^4

main = print . solve =<< parse stdin

-- vim: set expandtab:
