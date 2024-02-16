// Farhan Mahbub
// COP4020 Spring 2024
import { readFileSync } from "fs";

// Problem 1
function lexicoPerm(arg: string, n: number) {
  let str = arg;
  let strlen = str.length;
  let result = "";
  let fact = 1;

  for (let i = 1; i <= strlen; i++) {
    fact *= i;
  }

  for (let i = 0; i < strlen; i++) {
    fact /= strlen - i;
    let index = Math.floor(n / fact);
    result += str.charAt(index);
    str = str.slice(0, index) + str.slice(index + 1);
    n -= index * fact;
  }

  return result;
}

console.log("Problem 1: " + lexicoPerm("0123456789", 1000000 - 1));

// Problem 2
function coinSums(target: number, coins: number[]) {
  const dp: number[] = new Array(target + 1).fill(0);
  dp[0] = 1;

  for (let coin of coins) {
    for (let i = coin; i <= target; i++) {
      dp[i] += dp[i - coin];
    }
  }

  return dp[target];
}

console.log("Problem 2: " + coinSums(200, [1, 2, 5, 10, 20, 50, 100, 200]));

// Problem 3
function isTriangleNumber(x: number) {
  let start = 1;
  let n = x * 2;

  while (start < n) {
    if (n === start * (start + 1)) {
      return true;
    } else if (n < start * (start + 1)) {
      return false;
    }
    start++;
  }
  return false;
}

function isTriangleWord(str: string) {
  let sum = 0;
  const word = str.toLowerCase();

  for (let i = 0; i < word.length; i++) {
    sum += word.charCodeAt(i) - 96;
  }

  return isTriangleNumber(sum);
}

function countTriangleWords(filename: string) {
  const text: string = readFileSync(filename, "utf8");

  return text.split(",").filter((str: string) => isTriangleWord(str)).length;
}

console.log("Problem 3: " + countTriangleWords("./0042_words.txt"));
