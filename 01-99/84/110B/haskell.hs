main = getLine >>= (\n -> (putStrLn . take n . concat . repeat) "abcd") . read
