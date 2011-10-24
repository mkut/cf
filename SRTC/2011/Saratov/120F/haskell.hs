import Data.List
import Data.Graph
import Data.Tree

makeG (a:lst) = buildG (1, a) . pair $ lst
	where pair [] = []; pair (a:b:cs) = (a,b) : (b,a) : pair cs

main = do
	input <- fmap lines $ readFile "input.txt"
	let n = read . head $ input
	let trees = map (makeG . map read . words) . take n . tail $ input
	writeFile "output.txt" . (++"\n") . show . sum . (map (\g -> maximum [ length . head . map levels $ dfs g [i] | i <- vertices g ] - 1)) $ trees
