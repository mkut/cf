prob :: [Int] -> Int -> Maybe (Int, Int)
prob [] _ = Nothing
prob (x:xs) n
	| x == n = prob xs $ n+1
	| x < n = Nothing
	| otherwise = Just (n, x)

maybe_reverse :: [Int] -> Maybe (Int, Int) -> [Int]
maybe_reverse xs Nothing = []
maybe_reverse xs (Just (x, y)) =
	take (x-1) xs ++ (reverse $ take (y-x+1) $ drop (x-1) xs) ++ (drop y xs)

maybe_puts :: Maybe String -> IO ()
maybe_puts Nothing = return ()
maybe_puts (Just str) = putStrLn str

main = do
	n <- getLine >>= return . read :: IO Int
	lst <- getLine >>= return . (map read) . words :: IO [Int]
	if maybe_reverse lst (prob lst 1) == [1..n]
		then maybe_puts $ prob lst 1 >>= \(x, y) -> Just $ (show x) ++ " " ++ (show y)
		else putStrLn "0 0"
