import Control.Monad
import Data.Digits
import Data.Monoid
import qualified Data.Set as S

main :: IO ()
main = do
    input <- liftM (tail . lines) getContents
    let solution = map (solve . read) input
    putStr (format solution)

format :: [String] -> String
format solution = unlines $ map formatLine indexed
    where
        formatLine (index, answer) =
            "Case #" <> show index <> ": " <> answer
        indexed = zip [1..] solution

solve :: Int -> String
solve x = maybe "INSOMNIA" show (sleepyNumber x)

sleepyNumber :: Int -> Maybe Int
sleepyNumber 0 = Nothing
sleepyNumber x = Just (fst $ last a)
    where
        a = takeWhile (not . S.isSubsetOf allDigits . snd) digitCover
        digitCover = zip (multiples x) (unionCover x)
        allDigits = S.fromList [0..9]

unionCover :: Int -> [S.Set Int]
unionCover x = scanl S.union S.empty cover
    where cover = map (S.fromList . digits 10) (multiples x)

multiples :: Int -> [Int]
multiples x = [x*c | c <- [1..]]
