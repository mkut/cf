main = getLine >>= putStrLn . (\x -> take x ("BIVROYG" ++ cycle "ROYG")) . read
