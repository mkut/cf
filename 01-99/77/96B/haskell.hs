import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.List

digits x 0 = 0
digits x y = digits x (y `div` 10) + if y `mod` 10 == x then 1 else 0

luckys' = [4, 7] ++ concat [ [x*10+4, x*10+7] | x <- luckys' ]
luckys = filter (\x -> digits 4 x == digits 7 x) luckys'

main = do
	input <- fmap C.lines $ C.hGetContents stdin
	let n = fst . fromJust . C.readInteger $ head input
	(print . fromJust . find ((<=) n)) luckys
