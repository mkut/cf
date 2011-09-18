solve :: Int -> [Int] -> Int
solve _ [] = 0
solve _ [_] = 0
solve d (x:y:zs) = cnt + solve d ((y+cnt*d):zs)
	where cnt = max 0 $ (x - y + d) `div` d

main = do
	n:d:_ <- getLine >>= return . (map read) . words :: IO [Int]
	b <- getLine >>= return . (map read) . words :: IO [Int]
	putStrLn $ show $ solve d b
