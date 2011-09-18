import qualified Data.ByteString.Lazy.Char8 as C
import Data.Maybe
import IO

main = do
	let lns = fmap C.lines $ C.hGetContents stdin
	input <- fmap (map (map (fst . fromJust . C.readInt)) . map C.words) $ lns
	let n = (head . head) input
	let ls = (take n . tail) input
	(putStrLn . show . fst . foldl (\(m,c) y -> (max m (c+y), c+y)) (0,0)) $ map (\[x,y] -> y - x) ls
