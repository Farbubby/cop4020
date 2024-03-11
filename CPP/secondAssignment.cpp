#include <iostream>
#include <fstream>
#include <sstream>
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

        file.close();

        cout << "[Problem 1]" << endl << "File created successfully" << endl << endl;
    } else {
        cout << "[Problem 1]" << endl << "File not found" << endl << endl;
    }
}

// Problem 2
void problemTwo(string line) {
    ofstream file;

    file.open("OUT2.txt");

    if (file.is_open()) {
        file << line;
        file << endl;

        file.close();

        cout << "[Problem 2]" << endl << "File created successfully" << endl << endl;
    } else {
        cout << "[Problem 2]" << endl << "File not found" << endl << endl;
    }
}

// Problem 3
void problemThree(string fileName) {
    // Lambda function to count letters
    auto countLetters = [](string word) {
        int count = 0;

        for (int i = 0; i < word.length(); i++) {
            if (isalpha(word[i])) {
                count++;
            }
        }

        return count;
    };

    ifstream file;
    string line;
    int totalLetters = 0;

    file.open(fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string word;

            while (iss >> word) {
                totalLetters += countLetters(word);
            }
        }

        file.close();

        cout << "[Problem 3]" << endl << "Total letters: " << totalLetters << endl << endl;
    } else {
        cout << "[Problem 3]" << endl << "File not found" << endl << endl;
    }
}

// Problem 4
void problemFour(string fileName) {
    // Lambda function to count blanks in a sentence
    auto countBlanks = [](string line) {
        int count = 0;

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                count++;
            }
        }

        return count;
    };

    ifstream file;
    string line;
    int totalBlanks = 0;

    file.open(fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            totalBlanks += countBlanks(line);
        }

        file.close();

        cout << "[Problem 4]" << endl << "Total blanks: " << totalBlanks << endl << endl;
    } else {
        cout << "[Problem 4]" << endl << "File not found" << endl << endl;
    }
}

// Problem 5
void problemFive(string fileName) {
    ifstream file;
    string line;
    int totalWords = 0;

    file.open(fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string word;

            while (iss >> word) {
                totalWords += 1;
            }
        }

        file.close();

        cout << "[Problem 5]" << endl << "Total words: " << totalWords << endl << endl;
    } else {
        cout << "[Problem 5]" << endl << "File not found" << endl << endl;
    }
}

int main() {
    // Problem 1
    problemOne(100);

    // Problem 2
    problemTwo("Time is a great teacher but unfortunately it kills all its pupils. Berlioz");

    // Problem 3
    problemThree("OUT2.txt");

    // Problem 4
    problemFour("OUT2.txt");

    // Problem 5
    problemFive("OUT2.txt");

    return 0;
}