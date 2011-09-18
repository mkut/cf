import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe

solve a b v = solve' 0 v
	where
		solve' x y
			| y - x < 1e-6 = x
			| ok ((x+y)/2) = solve' ((x+y)/2) y
			| otherwise = solve' x ((x+y)/2)
		ok x = all (\i -> x * (a !! i) / s <= b !! i) [0..n-1]
		s = sum a
		n = length a

main = do
	input <- fmap C.lines $ C.hGetContents stdin
	let [n, v] = map (fromIntegral . fst . fromJust . C.readInt) . C.words $ head input
	let a = map (fromIntegral . fst . fromJust . C.readInt) . C.words $ head $ tail input
	let b = map (fromIntegral . fst . fromJust . C.readInt) . C.words $ head $ tail $ tail input
	print $ solve a b v
