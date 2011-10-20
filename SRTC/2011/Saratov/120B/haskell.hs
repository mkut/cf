solve (1:_) = 0
solve (_:xs) = solve xs + 1

main = do
	input <- fmap lines $ readFile "input.txt"
	let [n, k] = map read . words . head $ input
	let k' = k - 1
	let as = map read . words $ input !! 1
	writeFile "output.txt" . (++"\n") . show . (+1) . (`mod`n) . (+k') . solve $ drop k' as ++ take k' as
