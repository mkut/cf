import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe

last' l = case (C.elemIndex 'W' . C.reverse) l of
	Nothing -> 0
	Just x -> C.length l - 1 - x
fst' l = case C.elemIndex 'W' l of
	Nothing -> 0
	Just x -> C.length l - 1 - x

solve [] _ = 0
solve [ln] i = max 0 (last' ln - i)
	where n = C.length ln
solve (ln1:ln2:lns) i = let j = max 0 (max (last' ln1) (fst' ln2) - i) in let next = solve (ln2:lns) (n - j - i - 1) in j + next + 1
	where n = C.length ln1

halfrev lns = [if i `mod` 2 == 1 then C.reverse (lns !! i) else (lns !! i) | i <- [0..n-1]]
	where n = length lns

tailcut [] = []
tailcut (x:xs)
	| tailcut xs == [] && C.elemIndex 'W' x == Nothing = []
	| otherwise = (x:tailcut xs)

main = do
	input <- fmap C.lines $ C.hGetContents stdin
	let [n, m] = map (fst . fromJust . C.readInt) . C.words $ head input
	let view = take n $ tail input
	putStrLn . show $ solve (tailcut $ halfrev view) 0
