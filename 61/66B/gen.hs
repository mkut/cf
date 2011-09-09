main = do
	n <- getLine >>= return . read :: IO Int
	_ <- (putStrLn . show) n
	(putStrLn . unwords . map show) [1..n]
