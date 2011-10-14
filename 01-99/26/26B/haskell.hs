solve ans _ [] = ans
solve ans n ('(':xs) = solve ans (n+1) xs
solve ans 0 (')':xs) = solve ans 0 xs
solve ans n (')':xs) = solve (ans+2) (n-1) xs

main = getLine >>= print . solve 0 0
