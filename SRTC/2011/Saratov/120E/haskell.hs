main = readFile "input.txt" >>= writeFile "output.txt" . concat . map ((++"\n") . show . (`mod`2) . (+1) . read) . tail . lines
