import Control.Monad
import Data.Digits
import Data.Maybe
import Data.Monoid

data Coinjam =
    Coinjam
    { binary :: String
    , divisors :: [Integer]
    } deriving (Show)

main :: IO ()
main = putStr . format . take 500 . mapMaybe coinjam $ series 32

format :: [Coinjam] -> String
format xs =
    "Case #1:\n" <> (unlines $ map showCoinjam xs)

showCoinjam c = binary c <> " " <> unwords (map show (divisors c))

series n = iterate (+2) (2^(n-1) + 1)

coinjam :: Integer -> Maybe Coinjam
coinjam int =
    liftM (Coinjam (show . last $ xs)) divisors
    where
        a = unwords $ map show (digits 2 int)
        xs = map (readInt (digits 2 int)) [2..10]
        divisors = mapM divisor xs
        divisor x = headMaybe $ filter (\y -> x `mod` y == 0) [2..32768]

readInt :: [Integer] -> Integer -> Integer
readInt digits base = snd $ foldl f (1, 0) (reverse digits)
    where
        f (b, n) x = (b*base, n+x*b)

headMaybe :: [a] -> Maybe a
headMaybe [] = Nothing
headMaybe (x:_) = Just x
