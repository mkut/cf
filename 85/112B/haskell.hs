main = do
	[nn,x,y] <- getLine >>= return . map read . words :: IO [Int]
	let n = nn `div` 2
	putStrLn $ if elem (x,y) [(i,j) | i <- [n, n+1], j <- [n, n+1]] then "NO" else "YES"
