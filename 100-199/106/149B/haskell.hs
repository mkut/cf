import Data.Maybe
import Data.List

parse :: String -> [[Integer]]
parse x = [map f a, map f $ tail b]
   where
      (a, b) = break (==':') x
      str = zip (['0'..'9'] ++ ['A'..'Z']) [0..]
      f = fromJust . flip lookup str

toInt b xs = foldl (\x y -> x * b + y) 0 xs

ok n [xs,ys] = all (<n) xs && all (<n) ys && toInt n ys < 60 && toInt n xs < 24

ff xs = filter (flip ok  xs) [2..10000]

gg [] = [0]
gg xs
   | length xs > 5000 = [-1]
   | otherwise = xs

main = putStrLn . concat .  intersperse " " . map show . gg . ff . parse =<< getLine
   
-- vim: set expandtab:
