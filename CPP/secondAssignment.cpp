#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

// Problem 1
void problemOne(int n, string fileName) {
    ofstream file;

    file.open(fileName);

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
void problemTwo(string line, string fileName) {
    ofstream file;

    file.open(fileName);

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

        cout << "[Problem 3]" << endl << "Total number of letters: " << totalLetters << endl << endl;
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

        cout << "[Problem 4]" << endl << "Total number of blanks: " << totalBlanks << endl << endl;
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

        cout << "[Problem 5]" << endl << "Total number of words: " << totalWords << endl << endl;
    } else {
        cout << "[Problem 5]" << endl << "File not found" << endl << endl;
    }
}

// Problem 6
void problemSix(string target, string fileName) {
    // Lambda function to remove non-alphabetic characters from a word
    auto filterWord = [](string word) {
        string newWord = "";

        for (int i = 0; i < word.length(); i++) {
            if (isalpha(word[i])) {
                newWord += word[i];
            }
        }

        return newWord;
    };

    ifstream file;
    string line;
    int wordCount = 0;

    file.open(fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            transform(target.begin(), target.end(), target.begin(), ::tolower);

            istringstream iss(line);
            string word;

            while (iss >> word) {
                string newWord = filterWord(word);
                if (newWord == target){
                    wordCount++;
                }
            }
        }

        file.close();

        cout << "[Problem 6]" << endl << "Total number of \"" << target << "\": " << wordCount << endl << endl;
    } else {
        cout << "[Problem 6]" << endl << "File not found" << endl << endl;
    }
}

// Problem 7
void problemSeven(char target, string fileName) {
    ifstream file;
    string line;
    int lineCount = 0;

    file.open(fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line[0] != target){
                lineCount++;
            }
        }

        file.close();

        cout << "[Problem 7]" << endl << "Total number of lines not starting with \'" << target << "\': " << lineCount << endl << endl;
    } else {
        cout << "[Problem 7]" << endl << "File not found" << endl << endl;
    }
}

int main() {
    // Problem 1
    problemOne(100, "./text-files/NOTES.txt");

    // Problem 2
    problemTwo("Time is a great teacher but unfortunately it kills all its pupils. Berlioz", "./text-files/OUT.txt");

    // Problem 3
    problemThree("./text-files/OUT.txt");

    // Problem 4
    problemFour("./text-files/OUT.txt");

    // Problem 5
    problemFive("./text-files/OUT.txt");

    // Problem 6
    problemSix("the", "./text-files/STORY.txt");

    // Problem 7
    problemSeven('A', "./text-files/STORY.txt");

    return 0;
}