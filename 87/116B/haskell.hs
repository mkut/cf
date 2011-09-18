import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe

solve v = sum [solve' v i j | i <- [0..n-1], j <- [0..m-1]]
	where
		n = length v
		m = C.length $ head v
		at i j
			| i < 0  = '.'
			| j < 0  = '.'
			| i >= n = '.'
			| j >= m = '.'
			| otherwise = C.index (v!!i) j
		can_eat i j
			| at (i+1) j == 'P' = True
			| at (i-1) j == 'P' = True
			| at i (j+1) == 'P' = True
			| at i (j-1) == 'P' = True
			| otherwise = False
		solve' v i j
			| at i j == 'W' && can_eat i j = 1
			| otherwise = 0

main = do
	input <- fmap C.lines $ C.hGetContents stdin
	let [n,m] = map (fst . fromJust . C.readInt) . C.words $ head input
	let view = take n $ tail input
	(putStrLn . show . solve) view
