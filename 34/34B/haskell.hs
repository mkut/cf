import Data.List

main = do
	[n, m] <- getLine >>= return . map read . words :: IO [Int]
	tvs <- getLine >>= return . map read . words :: IO [Int]
	(putStrLn . show . sum . take m . reverse . sort . filter (>0) . map (*(-1))) tvs
