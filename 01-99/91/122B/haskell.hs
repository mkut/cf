import Data.List

countInfix :: Eq a => [a] -> [a] -> Int
countInfix x = length . filter (isPrefixOf x) . tails 

solve s = snd . minimum $ map (\x -> (- countInfix x s, x)) ["-1", "4","7","47","77"]

main = interact solve

-- vim: set expandtab:
