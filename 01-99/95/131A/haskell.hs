import Data.Char

cnv c
   | isUpper c = toLower c
   | otherwise = toUpper c

solve x
   | all isUpper $ tail x = map cnv x
   | otherwise = x

main = getLine >>= putStrLn . solve

-- vim: set expandtab:
