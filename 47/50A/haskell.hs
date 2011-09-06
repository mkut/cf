main = do
	m:n:_ <- getLine >>= return . (map read) . words :: IO [Int]
	putStrLn $ show $ m * n `div` 2
