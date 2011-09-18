main = do
	(h,m) <- getLine >>= return . (\(x,y) -> (read x, read $ tail y)) . break (==':') :: IO (Int, Int)
	(putStrLn . unwords . map show) [fromIntegral (h `mod` 12) * 360 / 12 + fromIntegral m / 2, fromIntegral m * 6]
