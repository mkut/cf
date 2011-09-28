solve "" = ""
solve x
	| length x <= 3 = x
	| otherwise = (take 2 x) ++ "-" ++ (solve $ drop 2 x)

main = do
	_ <- getLine
	s <- getLine
	putStrLn $ solve s
