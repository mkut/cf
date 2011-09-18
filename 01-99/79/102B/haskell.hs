import qualified Data.ByteString.Char8 as C
import Data.Maybe
import Data.Char

sumDigit :: C.ByteString -> Int
sumDigit x
	| x == C.empty = 0
	| otherwise = sumDigit (C.tail x) + (digitToInt (C.head x))

solve :: C.ByteString -> Int
solve x
	| C.length x == 1 = 0
	| otherwise = solve ((C.pack . show . sumDigit) x) + 1

main = getLine >>= putStrLn . show . solve . C.pack
