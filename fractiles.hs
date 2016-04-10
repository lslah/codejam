import Control.Monad
import Data.Foldable
import Data.Monoid

main :: IO ()
main = do
    content <- liftM (tail . lines) getContents
    let solution = map solve content
    putStr (format solution)

solve :: String -> String
solve line = unwords . map show $ [1..k]
    where
        k = read . head . words $ line

format :: [String] -> String
format solution = unlines $ map formatLine indexed
    where
        formatLine (index, answer) =
            "Case #" <> show index <> ": " <> answer
        indexed = zip [1..] solution

