import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.Array

import Debug.Trace

depth lst i = d ! i
	where
		n = length lst - 1
		init = array (1, n) [(i, -1) | i <- [1..n]]
		d = foldl (\memo i -> depth' memo i) init [1..n]
		depth' memo i
			| memo ! i /= -1 = memo
			| lst !! i == -1 = memo // [(i, 1)]
			| otherwise = let j = lst !! i in let newmemo = depth' memo j in newmemo // [(i, newmemo ! j + 1)]

main = do
	input <- fmap C.lines $ C.hGetContents stdin
	let n = (fst . fromJust . C.readInt . head) input
	let lst = (map (fst . fromJust . C.readInt) . tail) input
	(putStrLn . show . foldl max 0) $ map (depth (0:lst)) [1..n]
