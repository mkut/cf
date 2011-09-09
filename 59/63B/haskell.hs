main = do
	[n,k] <- getLine >>= return . map read . words :: IO [Int]
	lst <- getLine >>= return . map read . words :: IO [Int]
	let low x = length $ filter ((>=) x) lst
	(putStrLn . show . foldl max 0) [ (k - i) + (low i - 1) | i <- [1..k-1], low i > 0 ]
