solve :: Int -> [Int]
solve 1 = [1]
solve x = x : (solve $ x `div` a)
	where
		a = case dropWhile (\y -> x `mod` y /= 0) primes of [] -> x; p:_ -> p
		primes = 2 : sieve [3,5..1001]
		sieve (p:ys) = p : sieve [y | y <- ys, y `mod` p /= 0]
		sieve [] = []

main = getLine >>= putStrLn . unwords . map show . solve . read
