import Data.List
import Data.Array
import Data.Maybe

powSet :: [a] -> [[a]]
powSet [] = [[]]
powSet (x:xs) = concat [[x:y, y] | y <- powSet xs]

ok :: [(Int, Int)] -> Int -> Int -> Bool
ok x y z = d!(y,z)
	where
		ok' (i,j) = (elemIndex (i,j) x == Nothing) && (elemIndex (j,i) x == Nothing)
		d = array ((1,1),(16,16)) [((i,j), ok' (i,j)) | i <- [1..16], j <- [1..16]]

nameToId :: [String] -> String -> Int
nameToId a s = (fromJust . elemIndex s) a + 1

idToName :: [String] -> Int -> String
idToName a i = a !! (i - 1)

ord :: [a] -> [a] -> Ordering
ord x y
	| length x < length y = LT
	| length x > length y = GT
	| otherwise = EQ

getLines 0 = return []
getLines n = do
	x <- getLine
	xs <- getLines (n-1)
	return (x:xs)

getLines2 0 = return []
getLines2 n = do
	x <- getLine >>= return . words
	xs <- getLines2 (n-1)
	return (x:xs)

main = do
	[n, m] <- getLine >>= return . map read . words :: IO [Int]
	names <- getLines n
	bad_pairs <- getLines2 m >>= return . map ((\x -> (head x, last x)) . map (nameToId names))
	let ans = (last . sortBy ord) [ c | c <- powSet [1..n], all (\(a, b) -> ok bad_pairs a b) [(a, b) | a <- c, b <- c]]	
	putStr $ (show . length) ans ++ "\n" ++ (unlines . sort . map (idToName names)) ans
