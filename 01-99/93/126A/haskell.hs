import Data.List
import Data.Int

cmp (_, _, x) (_, _, y) = compare x y

solve :: [Int64] -> [Int64]
solve [t1, t2, x1, x2, t0] = (\(x, y, _) -> [x, y]) $ minimumBy cmp [ solve' y (0, x1+1) tz t1 t2 | y <- [x2,x2-1..0] ]
   where tz = fromIntegral t0

solve' y (a, b) t0 t1 t2
   | b - a <= 1 = (a, y, t)
   | t >= t0 = solve' y (mid, b) t0 t1 t2
   | otherwise = solve' y (a, mid) t0 t1 t2
   where mid = (a + b) `div` 2
         ue  = fromIntegral (t1 * mid + t2 * y) :: Rational
         nue = fromIntegral (mid + y) :: Rational
         t   = if nue == 0 then 100000000 else ue / nue

main = interact $ (++"\n") . unwords . map show . solve . map read . words

-- vim: set expandtab:
