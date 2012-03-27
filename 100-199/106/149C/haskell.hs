import qualified Data.ByteString.Lazy.Char8 as C
import IO
import Data.Maybe
import Data.List

readInt = fst . fromJust . C.readInt
readIntList = map readInt . C.words

solve :: [(Int, Int)] -> (([Int],Int),([Int],Int)) -> ([Int],[Int])
solve [] ((a,_),(b,_)) = (a,b)
solve [(xp,xn)] ((a,as),(b,bs))
   | as < bs   = (xn:a, b)
   | otherwise = (a, xn:b)
solve ((xp,xn):(yp,yn):zz) ((a,as),(b,bs))
   | as < bs   = solve zz ((xn:a, as + xp), (yn:b, bs + yp))
   | otherwise = solve zz ((yn:a, as + yp), (xn:b, bs + xp))

p xs = do
   print $ length xs
   putStrLn . concat . intersperse " " $ map show xs

main = do
   input <- fmap (map (C.takeWhile (/='\r')) . C.lines) $ C.hGetContents stdin
   let n = readInt $ head input
       xs = reverse . sort . flip zip [1..] . readIntList $ input !! 1
   let (ansx, ansy) = solve xs (([], 0), ([], 0))
   p ansx
   p ansy

-- vim: set expandtab:
