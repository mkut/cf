import Data.List
import IO

solve :: [Int] -> Int
solve = (`div`2) . sum . map ((`div`2) . length) . group . sort

main = print . solve . map read . words . head . tail . lines =<< hGetContents stdin

-- vim: set expandtab:
