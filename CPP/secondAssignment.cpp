#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Problem 1
void problemOne(int n) {
    ofstream file;

    file.open("NOTES1.txt");

    if (file.is_open()) {
        for (int i = 1; i <= n; i++) {
            file << i << endl;
        }
    }
}

int main() {
    // Problem 1
    problemOne(100);

    return 0;
}