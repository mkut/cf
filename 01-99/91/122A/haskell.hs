luckyList = [4, 7] ++ concat [ [x*10+4, x*10+7] | x <- luckyList ]

solve x = any (\y -> x `mod` y == 0) $ takeWhile (<=x) luckyList

showYN True  = "YES"
showYN False = "NO"

main = interact $ (++"\n") . showYN . solve . read

-- vim: set expandtab:
