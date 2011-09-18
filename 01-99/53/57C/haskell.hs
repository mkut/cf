import Data.Int
import Data.Bits

times :: (Num a) => a -> (b -> b) -> (b -> b)
times 0 f = \x -> x
times n f = f . times (n-1) f

product_mod :: [Int64] -> Int64 -> Int64
product_mod [] _ = 1
product_mod (x:xs) p = mul_mod (product_mod xs p) x p

pow_mod :: Int64 -> Int64 -> Int64 -> Int64
pow_mod x y p = product_mod [times i (\x -> mul_mod x x p) x | i <- [0..32], shift y (-i) .&. 1 == 1] p

mul_mod :: Int64 -> Int64 -> Int64 -> Int64
mul_mod x y p = x * y `mod` p

inv :: Int64 -> Int64 -> Int64
inv x p = pow_mod x (p-2) p

binomial_mod :: Int64 -> Int64 -> Int64 -> Int64
binomial_mod x y p = mul_mod (product_mod [x,x-1..x-y+1] p) (inv (product_mod [y,y-1..1] p) p) p

solve n = (2 * binomial_mod (2 * n - 1) n p - n + p) `mod` p
	where p = 1000000007

main = do
	getLine >>= putStrLn . show . solve . read
