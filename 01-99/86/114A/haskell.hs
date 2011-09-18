solve k l n
	| k == l = "YES\n" ++ (show n)
	| l `mod` k == 0 = solve k (l `div` k) (n+1)
	| otherwise = "NO"

main = do
	k <- getLine >>= return . read :: IO Int
	l <- getLine >>= return . read :: IO Int
	putStrLn $ solve k l 0
