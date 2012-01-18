import Data.List

main = putStrLn . showYN . solve . lines =<< getContents

solve [a, b, c] = sort (a ++ b) == sort c

showYN True  = "YES"
showYN False = "NO"

-- vim: set expandtab:
