import Data.List

separate      a 0 = [([],a)]
separate     [] _ = []
separate (a:as) n =  [ (a : fst cs, snd cs) | cs <- separate as (n-1) ]
                  ++ [ (fst cs, a : snd cs) | cs <- separate as n ]

isRectangle ps is = x && y
   where ps' = map (ps!!) is
         [a,b,c,d] = sort ps'
         x = (b `sub` a) `dotPro` (c `sub` a) == 0 
         y = a `add` d == b `add` c

isRhombus ps is = x == y
   where ps' = map (ps!!) is
         [a,b,c,d] = sort ps'
         x = size2 (b `sub` a)
         y = size2 (c `sub` a)

solve ps (x, y)  = isRectangle ps x
                && isRhombus ps x
                && isRectangle ps y

add (a,b) (c,d) = (a+c, b+d)
sub (a,b) (c,d) = (a-c, b-d)
dotPro (a,b) (c,d) = a*c + b*d
size2 (a,b) = a*a + b*b

printAns (Just x) = do
   putStrLn "YES"
   putStrLn (unwords . map (show . (+1)) $ fst x)
   putStrLn (unwords . map (show . (+1)) $ snd x)
printAns Nothing = putStrLn "NO"


main = do
   ps <- mapM (fmap ((\[x,y] -> (x,y)) . map read . words)) $ map (\_ -> getLine) [1..8] :: IO [(Int, Int)]
   printAns $ find (solve ps) (separate [0..7] 4)

-- vim: set expandtab:
