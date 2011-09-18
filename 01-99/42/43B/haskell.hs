import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe

count s = \x -> (C.length . C.filter ((==) x)) s

main = do
	input <- fmap C.lines $ C.hGetContents stdin
	let [s1,s2] = take 2 $ input
	let ans = length $ filter (==False) $ [ count s1 c >= count s2 c | c <- ['a'..'z'] ++ ['A'..'Z'] ]
	putStrLn (if ans == 0 then "YES" else "NO")
