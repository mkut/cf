xor :: String -> String -> String
xor [] [] = []
xor (a:as) (b:bs) = c:(xor as bs)
	where c = if a == b then '0' else '1'

main = do
	a <- getLine
	b <- getLine
	putStrLn $ xor a b
