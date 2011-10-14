solve ys [] = ys
solve [] (x:xs) = solve [x] xs
solve (y:ys) (x:xs)
	| x == y = solve ys xs
	| otherwise = solve (x:y:ys) xs

main = getLine >>= putStrLn . reverse . solve []
	
