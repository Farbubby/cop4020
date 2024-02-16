"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
// Farhan Mahbub
// COP4020 Spring 2024
var fs_1 = require("fs");
// Problem 1
function lexicoPerm(arg, n) {
    var str = arg;
    var strlen = str.length;
    var result = "";
    var fact = 1;
    for (var i = 1; i <= strlen; i++) {
        fact *= i;
    }
    for (var i = 0; i < strlen; i++) {
        fact /= strlen - i;
        var index = Math.floor(n / fact);
        result += str.charAt(index);
        str = str.slice(0, index) + str.slice(index + 1);
        n -= index * fact;
    }
    return result;
}
console.log("Problem 1: " + lexicoPerm("0123456789", 1000000 - 1));
// Problem 2
function coinSums(target, coins) {
    var dp = new Array(target + 1).fill(0);
    dp[0] = 1;
    for (var _i = 0, coins_1 = coins; _i < coins_1.length; _i++) {
        var coin = coins_1[_i];
        for (var i = coin; i <= target; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[target];
}
console.log("Problem 2: " + coinSums(200, [1, 2, 5, 10, 20, 50, 100, 200]));
// Problem 3
function isTriangleNumber(x) {
    var start = 1;
    var n = x * 2;
    while (start < n) {
        if (n === start * (start + 1)) {
            return true;
        }
        else if (n < start * (start + 1)) {
            return false;
        }
        start++;
    }
    return false;
}
function isTriangleWord(str) {
    var sum = 0;
    var word = str.toLowerCase();
    for (var i = 0; i < word.length; i++) {
        sum += word.charCodeAt(i) - 96;
    }
    return isTriangleNumber(sum);
}
function countTriangleWords(filename) {
    var text = (0, fs_1.readFileSync)(filename, "utf8");
    return text.split(",").filter(function (str) { return isTriangleWord(str); }).length;
}
console.log("Problem 3: " + countTriangleWords("./0042_words.txt"));
