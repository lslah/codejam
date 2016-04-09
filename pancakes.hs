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
swaps xs =
    if last xs == '-' then count+1 else count
    where
        count = fst $ foldl' f (0, head xs) xs

f (count, old) new =
    if old == new then (count, new) else (count+1, new)
