main = do
	input <- fmap lines $ readFile "input.txt" 
	let [n, k] = map read . words . head $ input
	let js = map read . words $ input !! 1
	let f x
		| x >= k * 3 = x - k * 3
		| otherwise = x `mod` k
	writeFile "output.txt" . show . sum . map f $ js
