import Data.Array

getLines :: Int -> IO [String]
getLines 0 = return []
getLines n = do x <- getLine; xs <- getLines (n-1); return (x:xs)

count :: String -> Char -> Int
count xs c = length $ filter ((==) c) xs

get_char :: [String] -> Int -> Int -> Char
get_char ss i j = d ! (i,j)
	where
		d = array ((0,0),(n-1,m-1)) [((ii, jj), ss !! ii !! jj) | ii <- [0..n-1], jj <- [0..m-1]]
		n = length ss
		m = length $ head ss

row_char :: [String] -> Int -> Char -> Int
row_char ss i = count (ss!!i)

col_char :: [String] -> Int -> Char -> Int
col_char ss j = count [get_char ss i j | i <- [0..m-1]]
	where m = length $ head ss

ok :: [String] -> Int -> Int -> Bool
ok ss i j = (row_char ss i c == 1) && (col_char ss j c == 1)
	where c = get_char ss i j

main = do
	[n,m] <- getLine >>= return . map read . words :: IO [Int]
	strs <- getLines n
	putStrLn [ get_char strs i j | i <- [0..n-1], j <- [0..m-1], ok strs i j ]
