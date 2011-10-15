import Data.List

getList = fmap (map read . words) getLine

getLists 0 = return []
getLists n = do x <- getList; xs <- getLists (n-1); return (x:xs)

max_take n lst = take n . reverse . sort $ lst

min_take n lst = take n . sort $ lst

solve n k as qs = (minimum $ map min_score group, maximum $ map max_score group)
	where
		rem = foldr delete as (concat qs)
		group = if length qs == k then qs else (rem:qs)
		fn = fromIntegral n
		min_score = (/fn) . fromIntegral . sum . min_take n
		max_score = (/fn) . fromIntegral . sum . max_take n

p (x, y) = putStrLn $ (show x) ++ " " ++ (show y)

main = do
	[n, k] <- getList
	as <- getList
	q <- fmap read getLine
	qsi <- getLists q
	let qs = map (map (\x -> as !! (x-1))) . nub . map sort $ qsi
	p $ solve (div n k) k as qs
