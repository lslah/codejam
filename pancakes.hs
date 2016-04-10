import Control.Monad
import Data.Foldable
import Data.Monoid

main :: IO ()
main = do
    content <- liftM (tail . lines) getContents
    let solution = map (show . swaps) content
    putStr (format solution)

format :: [String] -> String
format solution = unlines $ map formatLine indexed
    where
        formatLine (index, answer) =
            "Case #" <> show index <> ": " <> answer
        indexed = zip [1..] solution

swaps :: String -> Int
swaps xs = fst $ foldr' f (0, '+') xs
    where
        f new (count, old)
            | old == new = (count, new)
            | otherwise = (count+1, new)
