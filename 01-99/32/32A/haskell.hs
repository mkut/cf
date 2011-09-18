import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.Array

main = do
	input <- fmap C.lines $ C.hGetContents stdin
	let [n, d] = map (fst . fromJust . C.readInt) . C.words $ head input
	let as = map (fst . fromJust . C.readInt) . C.words $ head $ tail input
	let ass = array (0, n-1) [ (i, as !! i) | i <- [0..n-1] ]
	print $ 2 * (length $ filter (\(x,y) -> abs (x-y) <= d) [ (ass ! i, ass ! j) | i <- [0..n-1], j <- [i+1..n-1] ])
