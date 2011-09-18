import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe

profit i = snd . foldl (\(x, y) [l,r,t,c] -> if l <= i && i <= r && t < x then (t, c) else (x, y)) (10000, 0)

main = do
	input <- fmap C.lines $ C.hGetContents stdin
	let [n, m] = map (fst . fromJust . C.readInt) . C.words $ head input
	let lrtcs = map (map (fst . fromJust . C.readInt) . C.words) . take m $ tail input
	print $ sum [ profit i lrtcs | i <- [1..n] ]
