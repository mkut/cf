import Data.List
import Data.Char

main = interact $ (++"\n") . show . sum . map ((`div`5) . (+4) . length) . group . takeWhile isUpper

-- vim: set expandtab:
