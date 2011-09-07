import qualified Data.ByteString.Lazy.Char8 as C
import Data.Maybe
import IO

getLines :: IO [[Integer]]
getLines = do
	fmap C.lines (C.hGetContents stdin) >>= return . map (map (fst . fromJust . C.readInteger) . C.words)

sxx = sum . map ((^2) . head)
syy = sum . map ((^2) . last)
sx = sum . map head
sy = sum . map last

main = do
	n <- getLine >>= return . read :: IO Integer
	xys <- getLines
	putStrLn . show $ n * ((sxx xys) + (syy xys)) - (sx xys) ^ 2 - (sy xys) ^ 2
