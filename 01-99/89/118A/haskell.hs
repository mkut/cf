import Data.Char

solve "" = ""
solve (x:xs)
	| elem x "aiueoy" = solve xs
	| otherwise = "." ++ [x] ++ solve xs

main = getLine >>= putStrLn . solve . map toLower
