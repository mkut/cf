import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.List

prints [] = return ()
prints (x:xs) = do print x; prints xs

elevTimes m pos = [pos - 1, 2 * m - pos - 1] ++ [ 2 * (m-1) + x | x <- elevTimes m pos ]

firstElevTime m pos under = numCycle * elevCycle + (fromJust $ find ((<=) modCycle) (elevTimes m pos))
	where
		elevCycle = 2 * (m-1)
		numCycle = under `div` elevCycle
		modCycle = under `mod` elevCycle

solve m [s,f,t]
	| s == f = t
	| otherwise = firstElevTime m f (firstElevTime m s t)

main = do
	input <- fmap (map (C.takeWhile (/='\r')) . C.lines) $ C.hGetContents stdin
	let [n,m] = map (fst . fromJust . C.readInt) . C.words $ input !! 0
	let info = map (map (fst . fromJust . C.readInt) . C.words) $ take n $ tail input
	prints $ map (solve m) info
