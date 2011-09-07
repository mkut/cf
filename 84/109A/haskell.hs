solve :: Int -> Maybe String
solve 0 = Just ""
solve n
	| n < 0 = Nothing
	| n `mod` 7 == 0 = Just $ take (n `div` 7) $ repeat '7'
	| otherwise = solve (n-4) >>= Just . (++) "4"

putLn :: Maybe String -> IO ()
putLn Nothing = putStrLn "-1"
putLn (Just x) = putStrLn x

main = do
	getLine >>= putLn . solve . read
