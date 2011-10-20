main = readFile "input.txt" >>= writeFile "output.txt" . (\[d, r] -> if d == r then "L\n" else "R\n") . map ((=="1") . f) . lines
	where f "front" = "1"; f x = x
