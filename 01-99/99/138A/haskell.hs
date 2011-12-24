import Data.List

isVowel 'a' = True
isVowel 'i' = True
isVowel 'u' = True
isVowel 'e' = True
isVowel 'o' = True
isVowel   _ = False

chop 0      _ = Just ""
chop _     [] = Nothing
chop k (x:xs)
   | isVowel x = fmap (x:) $ chop (k-1) xs
   | otherwise = fmap (x:) $ chop k xs
   

aaaa [] = Just True
aaaa ((Just a) : (Just b) : (Just c): (Just d) : es)
   | a == b && b == c && c == d = aaaa es
aaaa _ = Nothing


aabb [] = Just True
aabb ((Just a) : (Just b) : (Just c): (Just d) : es)
   | a == b && c == d = aabb es
aabb _ = Nothing

abab [] = Just True
abab ((Just a) : (Just b) : (Just c): (Just d) : es)
   | a == c && b == d = abab es
abab _ = Nothing

abba [] = Just True
abba ((Just a) : (Just b) : (Just c): (Just d) : es)
   | a == d && b == c = abba es
abba _ = Nothing

solve x
   | aaaa x == Just True = "aaaa"
   | aabb x == Just True = "aabb"
   | abab x == Just True = "abab"
   | abba x == Just True = "abba"
   | otherwise = "NO"

main = do
   [n, k] <- fmap (map read . words) getLine
   p <- mapM (fmap (chop k . reverse)) $ take (n*4) (repeat getLine)
   putStrLn $ solve p

-- vim: set expandtab:
