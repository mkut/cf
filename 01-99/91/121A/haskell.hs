import Data.List

luckyList = [4, 7] ++ concat [ [x*10+4, x*10+7] | x <- luckyList ]

solve :: [Integer] -> Integer
solve [l,r] = sum [ y * z | [x, y] <- luckyLinked, let z = max 0 $ min y r - max x (l-1) ]
   where luckyLinked = ([0,4]:) . map (take 2) . takeWhile ((<r) . head) $ tails luckyList

main = interact $(++"\n") .  show . solve . map read . words

-- vim: set expandtab:
