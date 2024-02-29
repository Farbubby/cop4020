function isPrime(n) {
  if (n <= 1) return false;

  const sqrtNum = Math.sqrt(n);
  for (let i = 2; i <= sqrtNum; i++) {
    if (n % i === 0) {
      return false;
    }
  }

  return true;
}

function sumOfPrimes(n) {
  let sum = 0;
  for (let i = 1; i < n; i++) {
    if (isPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

console.log(sumOfPrimes(2000000)); // 142913828922
