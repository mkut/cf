getLines :: Int -> IO [String]
getLines 0 = return []
getLines n = do
	x <- getLine
	xs <- getLines (n-1)
	return (x:xs)

putStrLns :: [String] -> IO ()
putStrLns [] = return ()
putStrLns (x:xs) = do
	putStrLn x
	putStrLns xs

cnv :: String -> String
cnv str
	| length str > 10 = [(str !! 0)] ++ (show $ length str - 2) ++ [(reverse str !! 0)]
	| otherwise = str

main = do
	n <- getLine >>= return.read::IO Int
	strs <- getLines n
	putStrLns $ map cnv strs
