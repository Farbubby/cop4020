"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
// Farhan Mahbub
// COP4020 Spring 2024
var fs_1 = require("fs");
// Problem 1
// Problem 2
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
console.log(countTriangleWords("./0042_words.txt"));
