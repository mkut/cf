import Data.List

main = do
	input <- fmap lines $ readFile "input.txt"
	let [n, m] = map read . words . head $ input
	let v = map (map read . words) . take n . tail $ input
	let d = sort . map read . words $ input !! (n+1) :: [Int]
	let sumc = map sum v
	let sumr = [ sum $ map (!!i) v | i <- [0..m-1] ]
	let divc i j = sort . map sum $ [take i sumc, take (j-i) . drop i $ sumc, drop j sumc]
	let divr i j = sort . map sum $ [take i sumr, take (j-i) . drop i $ sumr, drop j sumr]
	writeFile "output.txt" . show . length $ [ 1 | i <- [1..n-1], j <- [i+1..n-1], d == divc i j ] ++ [ 1 | i <- [1..m-1], j <- [i+1..m-1], d == divr i j]
