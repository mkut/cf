import qualified Data.Set as S
import qualified Data.ByteString.Char8 as BS
import qualified Data.ByteString.Unsafe as U
import Data.ByteString.Internal
import Debug.Trace

t x = traceShow x x

-- range :: [a] -> Int -> Int -> (Int, [a])
range :: ByteString -> Int -> Int -> ByteString
range x i j = (U.unsafeTake (j-i) . U.unsafeDrop i) x

can_begin :: ByteString -> ByteString -> Int -> [Int]
can_begin _ e _ | e == BS.empty = []
can_begin ss t n
	| BS.isPrefixOf ss t = (n : (can_begin ss (U.unsafeTail t) (n+1)))
	| otherwise = can_begin ss (U.unsafeTail t) (n+1)

can_end :: ByteString -> ByteString -> Int -> [Int]
can_end _ e _ | e == BS.empty = []
can_end ss t n
	| BS.isPrefixOf ss t = (n : (can_end ss (U.unsafeTail t) (n+1)))
	| otherwise = can_end ss (U.unsafeTail t) (n+1)

main = do
	t <- BS.getLine
	sbegin <- BS.getLine
	send <- BS.getLine
	(print . S.size . foldl (\x y -> S.insert y x) S.empty) [ range t i j | i <- (can_begin sbegin t 0), j <- (can_end send t 0), i < j]
	-- (print . S.size . L.foldl (\x (i, j) -> S.insert (range t i (j + BS.length send)) x) S.empty) [ (i, j) | i <- (can_begin sbegin t 0), j <- (can_end send t 0), i <= j]
	-- (print . S.size . S.fromList) [ range t i j | i <- (can_begin sbegin t 0), j <- can_end send t 0, j - i >= max (BS.length sbegin) (BS.length send) - 1]
