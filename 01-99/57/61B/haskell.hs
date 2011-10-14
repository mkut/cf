import Data.Char
import Data.List

easy [] = []
easy (x:xs)
	| elem x "-_;" = easy xs
	| otherwise = toLower x : easy xs

permutation [] = [[]]
permutation xs = concat [map (x:) $ permutation (delete x xs) | x <- xs]

solve [] _ = "ACC"
solve as b = if elem b ass then "ACC" else "WA"
	where
		ass = map concat $ permutation as

getLines 0 = return []
getLines n = do x <- getLine; xs <- getLines (n-1); return (x:xs)

putStrLns [] = return ()
putStrLns (x:xs) = do putStrLn x; putStrLns xs

main = do
	s <- getLines 3 >>= return . map easy
	n <- getLine >>= return . read
	vals <- getLines n >>= return . map easy
	let ans = map (solve s) vals
	putStrLns ans
