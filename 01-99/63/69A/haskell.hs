getLines :: Int -> IO [String]
getLines 0 = return []
getLines n = do
	x <- getLine
	xs <- getLines $ n-1
	return (x:xs)

main = do
	n <- getLine >>= return.read :: IO Int
	xyzs <- getLines n >>= return . (map $ map read . words) :: IO [[Int]]
	putStrLn $ if foldl (\[x,y,z] [xx,yy,zz] -> [x+xx, y+yy, z+zz]) [0,0,0] xyzs == [0,0,0] then "YES" else "NO"
