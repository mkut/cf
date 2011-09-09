import qualified Data.ByteString.Lazy.Char8 as C
import Data.Maybe
import Data.Array
import IO

foldl' :: (a -> b -> a) -> a -> [b] -> a
foldl' _ a [] = a
foldl' f a (x:xs) = a' `seq` foldl' f a' xs
	where a' = f a x

left hs x = d ! x
	where
		d = array (0,n-1) [(i, left' i) | i <- [0..n-1]]
		n = length hs
		left' 0 = 0
		left' i
			| (hs !! (i-1)) <= (hs !! i) = d ! (i-1)
			| otherwise = i

right hs x = d ! x
	where
		d = array (0,n-1) [(i, right' i) | i <- reverse [0..n-1]]
		n = length hs
		right' i
			| i == n-1 = n-1
			| (hs !! (i+1)) <= (hs !! i) = d ! (i+1)
			| otherwise = i

main = do
	hs <- C.hGetContents stdin >>= return . (map (fst . fromJust . C.readInt)) . tail . C.words
	let n = length hs
	putStrLn . show $ foldl' max 0 [right hs i - left hs i + 1 | i <- [0..n-1]]
	-- print [lowest hs i 1 - lowest hs i (-1) + 1 | i <- [0..n-1]]
