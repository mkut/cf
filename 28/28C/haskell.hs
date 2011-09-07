import Data.Array

choose :: Int -> Int -> Double
choose _ 0 = 1
choose n k = choose (n-1) (k-1) * (fromIntegral n) / (fromIntegral k)

pow :: Int -> Int -> Double
pow x y = (fromIntegral x) ** (fromIntegral y)

divup :: Int -> Int -> Int
divup x y = (x + y - 1) `div` y

solve :: [Int] -> Int -> Double
solve as n = d ! (m, n, 0)
	where
		m = length as
		d = array ((1, 0, 0), (m, n, 50)) [((mm, nn, gg), solve' mm nn gg) | mm <- [1..m], nn <- [0..n], gg <- [0..50]]
		solve' :: Int -> Int -> Int -> Double
		solve' 1 nn gg = fromIntegral $ max gg $ divup nn (last as)
		solve' mm nn gg = sum [(p i) * (d ! (mm-1, nn-i, max gg (divup i (as!!(m-mm))))) | i <- [0..nn]]
			where
				p i = (choose nn i) * (pow (mm-1) (nn-i)) / (pow mm nn)

main = do
	-- n:m:a <- C.hGetContents stdin >>= return . map (fst . fromJust . C.readInt) . C.words
	n:m:_ <- getLine >>= return . map read . words :: IO [Int]
	a <- getLine >>= return . map read . words :: IO [Int]
	putStrLn $ show $ solve a n
