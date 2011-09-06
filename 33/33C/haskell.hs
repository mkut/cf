plus :: [Int] -> Int -> Int
plus [] cur = cur
plus (x:xs) cur = max cur $ plus xs $ max 0 $ cur + x

main = do
	n <- getLine >>= return . read :: IO Int
	a <- getLine >>= return . (map read) . words :: IO [Int]
	putStrLn $ show $ (plus a 0 * 2) - (foldl (+) 0 a)
