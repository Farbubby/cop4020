// Farhan Mahbub
// COP4020 Spring 2024

// Problem 1
function collatzSequenceLength(start) {
  sequence = [];

  while (start != 1) {
    sequence.push(start);
    if (start % 2 == 0) {
      start = start / 2;
    } else {
      start = 3 * start + 1;
    }
  }

  sequence.push(1);

  return sequence.length;
}

function longestChain(limit) {
  let longest = 0;
  let number = 0;

  for (let i = 1; i < limit; i++) {
    let length = collatzSequenceLength(i);
    if (length > longest) {
      longest = length;
      number = i;
    }
  }

  return number;
}

console.log("Problem 1: " + longestChain(1000000)); // 837799

// Problem 2
function factorialDigitSum(n) {
  let factorial = BigInt(1);
  for (let i = 1; i <= n; i++) {
    factorial *= BigInt(i);
  }

  let sum = 0;
  let str = factorial.toString();
  for (let i = 0; i < str.length; i++) {
    sum += parseInt(str[i]);
  }

  return sum;
}

console.log("Problem 2: " + factorialDigitSum(100)); // 648
