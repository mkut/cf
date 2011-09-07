typ :: Integer -> String
typ x
	| x < 128 && x >= -128 = "byte"
	| x < 32768 && x >= -32768 = "short"
	| x < 2147483648 && x >= -2147483648 = "int"
	| x < 9223372036854775808 && x >= -9223372036854775808 = "long"
	| otherwise = "BigInteger"

main = do
	getLine >>= putStrLn . typ . read
