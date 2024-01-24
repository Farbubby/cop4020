-- Farhan Mahbub
-- COP4020 Spring 2024

-- 1
doubleList :: [Int] -> [Int]
doubleList xs = map (\x -> x * 2) xs

-- 2
evenList :: [Int] -> [Int]
evenList xs = filter (\x -> x `mod` 2 == 0) xs

-- 3
tripleList :: [Int] -> [Int]
tripleList xs = map (\x -> x * 3) xs

-- 4
squaredList :: [Int] -> [Int] -- Helper function
squaredList xs = map (\x -> x * x) xs

oddList :: [Int] -> [Int] -- Helper function
oddList xs = filter (\x -> x `mod` 2 /= 0) xs

sumOddSquares :: [Int] -> Int
sumOddSquares xs = sum (squaredList (oddList xs))
