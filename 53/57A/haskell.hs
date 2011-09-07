dist :: Int -> (Int, Int) -> Int
dist _ (0, y) = y
dist n (x, 0) = 4 * n - x
dist n (x, y)
	| y == n = n + x
	| otherwise = 3 * n - y

min_dist :: Int -> Int -> Int
min_dist n d = min d (4 * n - d)

main = do
	n:x1:y1:x2:y2:_ <- getLine >>= return . map read . words :: IO [Int]
	putStrLn . show $ min_dist n $ abs $ (dist n (x1, y1)) - (dist n (x2, y2))
