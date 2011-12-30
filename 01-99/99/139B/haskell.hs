solve ws wps = sum $ map (solve' wps) ws

solve' wps [h,l] = minimum $ map cost wps
   where
      cost [h',w',c']
         | h > h'    = inf
         | otherwise = l `divup` ((h' `div` h) * w') * c'
      inf = 99999999
      divup x y = div (x+y-1) y

main = do
   n <- fmap read getLine
   ws <- mapM (fmap $ map read . words) (replicate n getLine)
   m <- fmap read getLine
   wps <- mapM (fmap $ map read . words) (replicate m getLine)
   print $ solve (map (\[x,y,z] -> [z,(x+y)*2]) ws) wps


-- vim: set expandtab:
