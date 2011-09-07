lucky' :: [Int]
lucky' = [4, 7] ++ concat [[x*10+4,x*10+7] | x <- lucky]
lucky :: Int -> Int
lucky 0 = 0
lucky n = lucky' !! (n-1)

putStrLns :: [String] -> IO ()
putStrLns [] = return ()
putStrLns (x:xs) = do
	putStrLn x
	putStrLns xs

cnt_inter :: (Int, Int) -> (Int, Int) -> Int
cnt_inter (x1, y1) (x2, y2) = (min y1 y2) - (max x1 x2) + 1

pattern p v k n = cnt_inter p (lucky n, lucky (0n))

main = do
	pl:pr:vl:vr:k <- getLine >>= return . (map read) . words :: IO [Int]
