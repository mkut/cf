import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.List

readInt = fst . fromJust . C.readInt
readIntList = map readInt . C.words

solve a
	| sum a `mod` 2 == 1 = sum a
	| otherwise = case firstOdd of
		Nothing -> 0
		Just x -> sum a - x
	where firstOdd = find (\x -> x `mod` 2 == 1) a

main = do
	input <- fmap (map (C.takeWhile (/='\r')) . C.lines) $ C.hGetContents stdin
	let n = readInt $ input !! 0
	let a = readIntList $ input !! 1
	print $ solve $ sort a
