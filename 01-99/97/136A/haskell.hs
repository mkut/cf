import Data.List
import Data.Maybe

main = do
   n <- fmap read getLine
   p <- fmap (map read . words) getLine :: IO [Int]
   putStrLn . unwords . map show $ map ((+1) . fromJust . flip elemIndex p) [1..n]

-- vim: set expandtab:
