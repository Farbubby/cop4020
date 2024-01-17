-- Farhan Mahbub
-- COP4020 Spring 2024

--1
newSqrt :: Float -> Int
newSqrt n = floor (sqrt (n))

isPrime :: Int -> Bool
isPrime n = length [x | x <- [2..newSqrt (fromIntegral n)], n `mod` x == 0] == 0

primesList :: Int -> [Int]
primesList n = take n [x | x <- [2..], isPrime x]

problem1 :: Int -> [Int]
problem1 n = [let list = primesList (n*2) in list !! x | x <- [0..(n*2 - 1)], x `mod` 2 == 0]
