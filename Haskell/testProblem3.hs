-- Farhan Mahbub
-- COP4020 Spring 2024

-- 3
newSqrt n = floor (sqrt n) -- Helper function

isPrime n = length [x | x <- [2..newSqrt (fromIntegral n)], n `mod` x == 0] == 0 -- Helper function

isPrimeFactor n x = n `mod` x == 0 && isPrime x && x /= 1 && x /= n -- Helper function

primeFactorList n = [x | x <- [2..n], isPrimeFactor n x] -- Helper function

primeFactorSums n = [sum (primeFactorList x) | x <- [2..n]] -- Helper function

solveProblem3 n = sum (primeFactorSums n)