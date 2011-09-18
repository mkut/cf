solve :: Int -> Int -> Int -> [Int]
solve n k t
	| t <= k = t:(take (n-1) (repeat 0))
	| otherwise = k:(solve (n-1) k (t-k))

main = do
	[n,k,t] <- getLine >>= return . map read . words
	putStrLn . unwords . map show $ solve n k ((n*k)*t`div`100)
