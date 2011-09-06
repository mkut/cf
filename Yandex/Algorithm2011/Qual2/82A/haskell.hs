getNextInt :: IO Int
getNextInt = getLine >>= return . read

name :: Int -> String
name 0 = "Sheldon"
name 1 = "Leonard"
name 2 = "Penny"
name 3 = "Rajesh"
name 4 = "Howard"

solve :: Int -> Int -> Int
solve n loop
	| n < loop * 5 = n `div` loop
	| otherwise = solve (n - loop * 5) (loop * 2)

main = do
	n <- getNextInt
	putStrLn $ name $ solve (n-1) 1
