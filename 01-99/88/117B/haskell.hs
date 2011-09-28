import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.List
import Text.Printf
import Data.Int

readInt = fst . fromJust . C.readInteger
readIntList = map readInt . C.words

divisible m b s1 = rem <= b
	where
		rem' = m - s1 * 10^9 `mod` m
		rem = if rem' == m then 0 else rem'

solve a b m = find (not . divisible m b) [1..a']
	where a' = min a m

showAns Nothing = "2"
showAns (Just x) = "1 " ++ printf "%09d" x

main = do
	input <- fmap (map (C.takeWhile (/='\r')) . C.lines) $ C.hGetContents stdin
	let [a, b, m] = map fromInteger $ readIntList $ input !! 0 :: [Int64]
	putStrLn . showAns $ solve a b m
