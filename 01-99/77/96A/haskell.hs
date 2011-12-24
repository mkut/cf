import Data.List

showYN True  = "YES"
showYN False = "NO"

main = interact $ showYN . any (>=7) . map length . group

-- vim: set expandtab:
