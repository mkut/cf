import Data.List

solve x = any id [ elem c x | c <- "HQ9" ]

showYN True  = "YES"
showYN False = "NO"

main = interact $ (++"\n") . showYN . solve

-- vim: set expandtab:
