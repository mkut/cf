import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe

readInt = fst . fromJust . C.readInt
readIntList = map readInt . C.words

main = do
	input <- fmap (map (C.takeWhile (/='\r')) . C.lines) $ C.hGetContents stdin
	let [n, m, k] = readIntList $ head input
	let ps = map readIntList . take k $ tail input
	putStrLn $ if elem True [ foldl min (x-1) [n-x, y-1, m-y] < 5 | [x, y] <- ps ] then "YES" else "NO"
