// Farhan Mahbub
// COP4020 Spring 2024

// Problem 1

// Problem 2

// Problem 3
function isTriangleNumber(x) {
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

function isTriangleWord(str) {
  let sum = 0;
  const word = str.toLowerCase();

  for (let i = 0; i < word.length; i++) {
    sum += word.charCodeAt(i) - 96;
  }

  return isTriangleNumber(sum);
}

function countTriangleWords(filename) {
  const fs = require("fs");
  const data = fs.readFileSync(filename, "utf8");

  return data.split(",").filter((str) => isTriangleWord(str)).length;
}

console.log(countTriangleWords("0042_words.txt"));
