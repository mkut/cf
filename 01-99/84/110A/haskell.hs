isLuckyChar '4' = True
isLuckyChar '7' = True
isLuckyChar _   = False

isLucky 4 = True
isLucky 7 = True
isLucky x
   | x < 10    = False
   | isLucky y = isLucky z
   | otherwise = False
   where y = x `mod` 10
         z = x `div` 10

showYN True  = "YES"
showYN False = "NO"

main = interact $ (++"\n") . showYN . isLucky . length . filter isLuckyChar

-- vim: set expandtab:
