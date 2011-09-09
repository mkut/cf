nth :: Int -> [(Int, Int)] -> Int -> Int -> Int
nth m block i j
	| elem (i, j) block = 3
	| otherwise = (m * (i-1) + (j-1) - (length . filter (\(x,y) -> x < i || x == i && y < j)) block) `mod` 3

getLines :: Int -> IO [(Int, Int)]
getLines 0 = return []
getLines n = do x <- getLine >>= return . (\x -> (head x, last x)) . map read . words; xs <- getLines (n-1); return (x:xs)

main = do
	[n,m,k,t] <- getLine >>= return . map read . words :: IO [Int]
	block <- getLines k
	query <- getLines t
	(putStr . unlines . map (\i -> ["Carrots", "Kiwis", "Grapes", "Waste"] !! i)) [ nth m block x y | (x,y) <- query ]
