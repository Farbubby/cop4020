-- Farhan Mahbub
-- COP4020 Spring 2024

-- 2
newSqrt n = floor (sqrt n) -- Helper function

isPrime n = length [x | x <- [2..newSqrt (fromIntegral n)], n `mod` x == 0] == 0 -- Helper function

isPrimePalindrome x = isPrime x && let str = show x in str == reverse str -- Helper function

sumEvenDigits 0 = 0
sumEvenDigits n = if (n `mod` 2 == 0) then (n `mod` 10) + sumEvenDigits (n `div` 10) else sumEvenDigits (n `div` 10) -- Helper function

sumsList n = [sumEvenDigits x | x <- [1..n], isPrimePalindrome x] -- Helper function

solveProblem2 n = sum (sumsList n)