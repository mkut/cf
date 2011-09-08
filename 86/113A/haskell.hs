import Data.List

grm :: String -> Maybe (Char, Char)
grm x
	| (reverse . take 4 . reverse) x == "lios" = Just ('m', 'a')
	| (reverse . take 5 . reverse) x == "liala" = Just ('f', 'a')
	| (reverse . take 3 . reverse) x == "etr" = Just ('m', 'n')
	| (reverse . take 4 . reverse) x == "etra" = Just ('f', 'n')
	| (reverse . take 6 . reverse) x == "initis" = Just ('m', 'v')
	| (reverse . take 6 . reverse) x == "inites" = Just ('f', 'v')
	| otherwise = Nothing


rex :: Int -> String -> Bool
rex 0 [] = False
rex _ [] = True
rex 0 ('v':xs) = rex 0 xs
rex 0 ('n':xs) = rex 1 xs
rex 0 ('a':xs) = False
rex 1 ('v':xs) = False
rex 1 ('n':xs) = False
rex 1 ('a':xs) = rex 2 xs
rex 2 ('v':xs) = False
rex 2 ('n':xs) = False
rex 2 ('a':xs) = rex 2 xs

solve :: [String] -> String
solve strs
	| grms == Nothing = "NO"
	| (grms >>= Just . length) == Just 1 = "YES"
	| (grms >>= Just . (/=1) . length . group . map fst) == Just True = "NO"
	| (grms >>= Just . rex 0 . map snd) == Just True = "YES"
	| otherwise = "NO"
	where
		grms = foldl (\x y -> do xx <- x; yy <- y; Just (yy:xx)) (Just []) (map grm strs)

main = do
	getLine >>= putStrLn . solve . words
