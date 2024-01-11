-- Farhan Mahbub
-- COP4020 Spring 2024

--1
squared :: Float -> Float
squared x = x * x

--2
cubed :: Float -> Float
cubed x = squared x * x

--3
first_a :: Int -> [Int]
first_a n = [x | x <- [1..n], x `mod` 6 == 0 || x `mod` 11 == 0]

--4
isMult6Or11 :: Int -> Bool --Helper function
isMult6Or11 x = x `mod` 6 == 0 || x `mod` 11 == 0

first_b :: Int -> [Int]
first_b n = [x | x <- [1..n], isMult6Or11 x]

--5
second_a :: Int -> [Int]
second_a n = [x | x <- [1..n], x `mod` 10 == 3, let str = show x in str == reverse str]

--6
isPalindromeThatStartsWithDigit3 :: Int -> Bool --Helper function
isPalindromeThatStartsWithDigit3 x = x `mod` 10 == 3 && let str = show x in str == reverse str

second_b :: Int -> [Int]
second_b n = [x | x <- [1..n], isPalindromeThatStartsWithDigit3 x]
