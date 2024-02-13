-- Farhan Mahbub
-- COP4020 Spring 2024

-- 1
newSqrt :: Float -> Int -- Helper function
newSqrt n = floor (sqrt n)

isPrime :: Int -> Bool -- Helper function
isPrime n = length [x | x <- [2..newSqrt (fromIntegral n)], n `mod` x == 0] == 0

primesList :: Int -> [Int] -- Helper function
primesList n = take n [x | x <- [2..], isPrime x]

problem1 :: Int -> [Int]
problem1 n = [let list = primesList (n*2) in list !! x | x <- [0..(n*2 - 1)], x `mod` 2 == 0]

-- 2
fib :: Int -> Int -- Helper function
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

fiboThree :: Int -> Int -> [Int] -- Helper function
fiboThree x n = let num = fib x in 
    if (num > n) 
        then [] 
    else
        if (num `mod` 10 == 3) 
            then [num] ++ fiboThree (x+1) n 
        else fiboThree (x+1) n

problem2 :: Int -> [Int]
problem2 n = fiboThree 2 n

-- 3
isPerfectSquare :: Int -> Bool -- Helper function
isPerfectSquare n = let num = floor (sqrt (fromIntegral n)) in 
    if (num * num == n) 
        then True 
    else False

hasThreeFactors :: Int -> Bool -- Helper function
hasThreeFactors n = 
    if (isPerfectSquare n) 
        then isPrime (floor (sqrt (fromIntegral n))) 
    else False

problem3 :: Int -> [Int]
problem3 n = [x | x <- [2..n], x `mod` 5 == 0 || hasThreeFactors x]