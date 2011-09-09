import qualified Data.Set as S
import Data.List

get :: Int -> IO [S.Set Int]
get 0 = return []
get n = do
	x <- getLine >>= return . S.fromList . map read . tail . words
	xs <- get (n-1)
	return (x:xs)

put :: [S.Set Int] -> IO ()
put [] = return ()
put (x:xs) = do putStrLn . unwords . map show $ S.size x : S.toList x; put xs

main = do
	n <- getLine >>= return .read :: IO Int
	ss <- get (n*(n-1)`div`2)
	(put . S.toList . S.fromList) $ concat [[S.intersection x y, S.difference x y] | x <- ss, let y = head $ dropWhile (\y -> x == y || (S.null $ S.intersection x y)) ss]
