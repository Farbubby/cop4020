-- Farhan Mahbub
-- COP4020 Spring 2024

-- 1
isCondition x = x `mod` 2 == 0 && x `mod` 5 == 0 && show x !! 0 == '6' -- Helper function

solveProblem1 n = [x | x <- [1..n], isCondition x]