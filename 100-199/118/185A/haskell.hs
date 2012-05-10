import Data.Bits

main = print . solver . read =<< getLine

solver :: Integer -> Integer
solver n = p
   where
      md = 10^9 + 7
      one = [1,0,0,1]
      a' = [3,1,1,3] : map (\x -> x `mmul` x) a'
      b' = [ if testBit n i then a' !! i else one | i <- [0..63] ]
      (p:_) = foldl mmul one b'
      mmul [x,y,z,w] [a,b,c,d] = map (`mod`md) [x*a + y*c, x*b + y*d, z*a + w*c, z*b + w*d]

-- vim: set expandtab:
