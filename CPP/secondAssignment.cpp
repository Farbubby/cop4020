#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Employee {
    int ENO;
    char ENAME[10];

    public:
        void getIt() {
            cout << "Enter the employee number: ";
            cin >> ENO;
            cout << "Enter the employee name: ";
            cin >> ws;
            cin.getline(ENAME, 10);
            cout << endl;
        }
        void showIt() {
            cout << "Employee number: " << ENO << endl;
            cout << "Employee name: " << ENAME << endl;
            cout << endl;
        }
};

// Problem 1
void problemOne(int n, string fileName) {
    ofstream outputFile;

    outputFile.open(fileName);

    if (outputFile.is_open()) {
        for (int i = 1; i <= n; i++) {
            outputFile << i << endl;
        }

        outputFile.close();

        cout << "[Problem 1]" << endl << "File created successfully" << endl << endl;
    } else {
        cout << "[Problem 1]" << endl << "File not found" << endl << endl;
    }
}

// Problem 2
void problemTwo(string line, string fileName) {
    ofstream outputFile;

    outputFile.open(fileName);

    if (outputFile.is_open()) {
        outputFile << line;
        outputFile << endl;

        outputFile.close();

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

    ifstream inputFile;
    string line;
    int totalLetters = 0;

    inputFile.open(fileName);

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string word;

            while (iss >> word) {
                totalLetters += countLetters(word);
            }
        }

        inputFile.close();

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

    ifstream inputFile;
    string line;
    int totalBlanks = 0;

    inputFile.open(fileName);

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            totalBlanks += countBlanks(line);
        }

        inputFile.close();

        cout << "[Problem 4]" << endl << "Total number of blanks: " << totalBlanks << endl << endl;
    } else {
        cout << "[Problem 4]" << endl << "File not found" << endl << endl;
    }
}

// Problem 5
void problemFive(string fileName) {
    ifstream inputFile;
    string line;
    int totalWords = 0;

    inputFile.open(fileName);

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string word;

            while (iss >> word) {
                totalWords += 1;
            }
        }

        inputFile.close();

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

    ifstream inputFile;
    string line;
    int wordCount = 0;

    inputFile.open(fileName);

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
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

        inputFile.close();

        cout << "[Problem 6]" << endl << "Total number of \"" << target << "\": " << wordCount << endl << endl;
    } else {
        cout << "[Problem 6]" << endl << "File not found" << endl << endl;
    }
}

// Problem 7
void problemSeven(char target, string fileName) {
    ifstream inputFile;
    string line;
    int lineCount = 0;

    inputFile.open(fileName);

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            if (line[0] != target){
                lineCount++;
            }
        }

        inputFile.close();

        cout << "[Problem 7]" << endl << "Total number of lines not starting with \'" << target << "\': " << lineCount << endl << endl;
    } else {
        cout << "[Problem 7]" << endl << "File not found" << endl << endl;
    }
}

// Problem 8
void copyUpper(string outputFileName, string inputFileName) {
    ifstream inputFile;
    ofstream outputFile;
    string line;

    outputFile.open(outputFileName);
    inputFile.open(inputFileName);

    if (inputFile.is_open() && outputFile.is_open()) {
        while (getline(inputFile, line)) {
            transform(line.begin(), line.end(), line.begin(), ::toupper);
            outputFile << line << endl;
        }

        inputFile.close();
        outputFile.close();

        cout << "[Problem 8]" << endl << "File created successfully" << endl << endl;
    } else {
        cout << "[Problem 8]" << endl << "File(s) not found" << endl << endl;
    }
}

// Problem 9
void vowelWords(string outputFileName, string inputFileName) {

    // Lambda function to check if a word starts with a vowel
    auto startsWithVowel = [](string word) {
        char firstChar = tolower(word[0]);
        return firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u';
    };

    ifstream inputFile;
    ofstream outputFile;
    string line;

    outputFile.open(outputFileName);
    inputFile.open(inputFileName);

    if (inputFile.is_open() && outputFile.is_open()) {
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string word;
            
            while (iss >> word) {
                if (startsWithVowel(word)) {
                    outputFile << word << " ";
                }
            }

            outputFile << endl;
        }

        inputFile.close();
        outputFile.close();

        cout << "[Problem 9]" << endl << "File created successfully" << endl << endl;
    } else {
        cout << "[Problem 9]" << endl << "File(s) not found" << endl << endl;
    }
}

// Problem 10
void problemTen(string outputFileName, string inputFileName) {
    ifstream inputFile;
    ofstream outputFile;

    outputFile.open(outputFileName, ios::binary);
    inputFile.open(inputFileName, ios::binary);

    if (inputFile.is_open() && outputFile.is_open()) {
        Employee writeEmp;
        Employee readEmp;

        cout << "[Problem 10a]" << endl;
        writeEmp.getIt();
        outputFile.write((char*)&writeEmp, sizeof(writeEmp));
        outputFile.close();

        cout << "[Problem 10b]" << endl;
        inputFile.read((char*)&readEmp, sizeof(readEmp));
        readEmp.showIt();
        inputFile.close();

        cout << "[Problem 10]" << endl << "Successfully completed" << endl << endl;
    } else {
        cout << "[Problem 10]" << endl << "File(s) not found" << endl << endl;
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

    // Problem 8
    copyUpper("./text-files/SECOND1.txt", "./text-files/FIRST.txt");

    // Problem 9
    vowelWords("./text-files/SECOND2.txt", "./text-files/FIRST.txt");

    // Problem 10
    problemTen("./text-files/EMPLOYEE.bin", "./text-files/EMPLOYEE.bin");

    return 0;
}
