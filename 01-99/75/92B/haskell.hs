import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.Char

main = do
	input <- fmap (C.takeWhile (/='\r') . head . C.lines) $ C.hGetContents stdin
	let n = C.length input
	let z = C.count '0' input
	let o = C.count '1' input
	putStrLn . show $ n + z + 1 - (fromJust . C.elemIndex '1' . C.reverse) input - if o == 1 then 2 else 0
