main = printer . solver . map read . words =<< getLine

solver [0, 0] = Just [0, 0]
solver [0, _] = Nothing
solver [n, 0] = Just [n, n]
solver [n, m] = Just [n + m - min n m, n + m - 1]

printer Nothing  = putStrLn "Impossible"
printer (Just x) = putStrLn . unwords . map show $ x

-- vim: set expandtab:
