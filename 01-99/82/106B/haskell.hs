import Data.List

getLines :: Int -> IO [[Int]]
getLines 0 = return []
getLines n = do x <- getLine >>= return . map read . words; xs <- getLines (n-1); return (x:xs)

ok :: [[Int]] -> [Int] -> Bool
ok x (ya:yb:yc:_) = find (\(za:zb:zc:_) -> ya < za && yb < zb && yc < zc) x == Nothing

main = do
	n <- getLine >>= return . read :: IO Int
	spec <- getLines n
	putStrLn . show . fst $ foldl (\(a, b) (c, d) -> if b < d then (a, b) else (c, d)) (-1, 9999) [( i + 1, spec !! i !! 3) | i <- [0..n-1], ok spec (spec !! i)]
