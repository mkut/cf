join _ [] = []
join c [x] = x
join c (x:xs) = x ++ [c] ++ join c xs

solve n = map tostr a
	where
		tostr lst = (take (n * 2 + 1 - length lst) $ repeat ' ') ++ (join ' ' $ map show lst)
		a = [ [0..i-1] ++ [i,i-1..0] | i <- [0..n-1] ++ [n,n-1..0] ]

main = getLine >>= putStrLn . join '\n' . solve . read
