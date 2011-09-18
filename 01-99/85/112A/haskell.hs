import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.Char

main = do
	input <- fmap (map (C.takeWhile (/='\r')) . C.lines) $ C.hGetContents stdin
	let s1 = C.unpack . C.map toLower $ head input
	let s2 = C.unpack . C.map toLower $ head $ tail input
	print $ case compare s1 s2 of
		LT -> -1
		GT -> 1
		EQ -> 0