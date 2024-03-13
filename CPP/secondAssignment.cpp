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

class Computer {
    char chiptype[10];
    int speed;

    public:
        void getDetails() {
            cout << "Enter the computer chip: ";
            cin >> ws;
            cin.getline(chiptype, 10);
            cout << "Enter the computer speed: ";
            cin >> speed;
            cout << endl;
        }
        void showDetails() {
            cout << "Computer chip: " << chiptype << endl;
            cout << "Computer speed: " << speed << endl;
            cout << endl;
        }
};

class Student {
    char admNo[10];
    char name[30];
    int percentage;

    public:
        void enterData() {
            cout << "Enter the admission number: ";
            cin >> ws;
            cin.getline(admNo, 10);
            cout << "Enter the student name: ";
            cin.getline(name, 30);
            cout << "Enter the student percentage: ";
            cin >> percentage;
            cout << endl;
        }
        void displayData() {
            cout << "Admission number: " << admNo << endl;
            cout << "Student name: " << name << endl;
            cout << "Student percentage: " << percentage << endl;
            cout << endl;
        }
        int returnPercentage() {
            return percentage;
        }
};

class Stud {
    int rNo;
    char name[10];

    public:
        void enter() {
            cout << "Enter the roll number: ";
            cin >> rNo;
            cout << "Enter the student name: ";
            cin >> ws;
            cin.getline(name, 10);
            cout << endl;
        }
        void display() {
            cout << "Roll number: " << rNo << endl;
            cout << "Student name: " << name << endl;
            cout << endl;
        }
};

// Generate computer data in a SHIP.DAT binary file
void generateComputerData(string outputFileName, int n) {
    ofstream outputFile;

    outputFile.open(outputFileName, ios::binary | ios::app);

    if (outputFile.is_open()) {
        Computer writeComp;

        for (int i = 0; i < n; i++) {
            writeComp.getDetails();
            outputFile.write((char*)&writeComp, sizeof(writeComp));
        }

        outputFile.close();
    } else {
        cout << "File not found" << endl << endl;
    }
}

// Generate student data in a STUDENT.DAT binary file
void generateStudentData(string outputFileName, int n) {
    ofstream outputFile;

    outputFile.open(outputFileName, ios::binary | ios::app);

    if (outputFile.is_open()) {
        Student writeStudent;

        for (int i = 0; i < n; i++) {
            writeStudent.enterData();
            outputFile.write((char*)&writeStudent, sizeof(writeStudent));
        }

        outputFile.close();
    } else {
        cout << "File not found" << endl << endl;
    }
}

// Read student data from a STUDENT1.DAT binary file
void readStudData(string inputFileName) {
    ifstream inputFile;

    inputFile.open(inputFileName, ios::binary);

    if (inputFile.is_open()) {
        Stud readStud;

        while (inputFile.read((char*)&readStud, sizeof(readStud))) {
            readStud.display();
        }

        inputFile.close();
    } else {
        cout << "File not found" << endl << endl;
    }
}

// Problem 1
void problemOne(int n, string fileName) {
    ofstream outputFile;

    outputFile.open(fileName);

    if (outputFile.is_open()) {
        for (int i = 1; i <= n; i++) {
            outputFile << i << endl;
        }

        outputFile.close();

        cout << "[Problem 1]" << endl << "Data added successfully" << endl << endl;
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

        cout << "[Problem 2]" << endl << "Data added successfully" << endl << endl;
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
void copyUpper(string inputFileName, string outputFileName) {
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

        cout << "[Problem 8]" << endl << "Data added successfully" << endl << endl;
    } else {
        cout << "[Problem 8]" << endl << "File(s) not found" << endl << endl;
    }
}

// Problem 9
void vowelWords(string inputFileName, string outputFileName) {

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

        cout << "[Problem 9]" << endl << "Data added successfully" << endl << endl;
    } else {
        cout << "[Problem 9]" << endl << "File(s) not found" << endl << endl;
    }
}

// Problem 10
void problemTen(string inputFileName, string outputFileName, int n) {
    ifstream inputFile;
    ofstream outputFile;

    outputFile.open(outputFileName, ios::binary | ios::app);
    inputFile.open(inputFileName, ios::binary);

    if (inputFile.is_open() && outputFile.is_open()) {
        Employee writeEmp;
        Employee readEmp;

        // Problem 10a
        cout << "[Problem 10a]" << endl;
        for (int i = 0; i < n; i++) {
            writeEmp.getIt();
            outputFile.write((char*)&writeEmp, sizeof(writeEmp));
        }

        outputFile.close();

        // Problem 10b
        cout << "[Problem 10b]" << endl;
        while (inputFile.read((char*)&readEmp, sizeof(readEmp))) {
            readEmp.showIt();
        }

        inputFile.close();
    } else {
        cout << "[Problem 10]" << endl << "File(s) not found" << endl << endl;
    }
}

// Problem 12
void readFile(string inputFileName) {
    ifstream inputFile;
    int recordCount = 0;

    inputFile.open(inputFileName, ios::binary);

    if (inputFile.is_open()) {
        Computer readComp;

        cout << "[Problem 12]" << endl;
        while (inputFile.read((char*)&readComp, sizeof(readComp))) {
            cout << "---- Record " << recordCount + 1 << " ----" << endl;
            readComp.showDetails();
            recordCount++;
        }

        inputFile.close();

        cout << "Total number of records: " << recordCount << endl << endl;
    } else {
        cout << "[Problem 12]" << endl << "File not found" << endl << endl;
    }
}

// Problem 13
void problemThirteen(string inputFileName) {
    ifstream inputFile;

    inputFile.open(inputFileName, ios::binary);

    if (inputFile.is_open()) {
        Student readStudent;

        cout << "[Problem 13]" << endl;
        while (inputFile.read((char*)&readStudent, sizeof(readStudent))) {
            if (readStudent.returnPercentage() > 75) {
                readStudent.displayData();
            }
        }

        inputFile.close();
    } else {
        cout << "[Problem 13]" << endl << "File not found" << endl << endl;
    }
}

// Problem 15
void problemFifteen(string outputFileName, int n) {
    ofstream outputFile;

    outputFile.open(outputFileName, ios::binary | ios::app);

    if (outputFile.is_open()) {
        Stud writeStud;
        Stud readStud;

        cout << "[Problem 15]" << endl;
        for (int i = 0; i < n; i++) {
            writeStud.enter();
            outputFile.write((char*)&writeStud, sizeof(writeStud));
        }

        outputFile.close();
        cout << "Object(s) added successfully" << endl << endl;
    } else {
        cout << "[Problem 15]" << endl << "File not found" << endl << endl;
    }

}

int main() {

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 1
    problemOne(100, "./text-files/NOTES.TXT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 2
    problemTwo("Time is a great teacher but unfortunately it kills all its pupils. Berlioz", "./text-files/OUT.TXT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 3
    problemThree("./text-files/OUT.TXT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 4
    problemFour("./text-files/OUT.TXT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 5
    problemFive("./text-files/OUT.TXT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 6
    problemSix("the", "./text-files/STORY.TXT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 7
    problemSeven('A', "./text-files/STORY.TXT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 8
    copyUpper("./text-files/FIRST.TXT", "./text-files/SECOND1.TXT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 9
    vowelWords("./text-files/FIRST.TXT", "./text-files/SECOND2.TXT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 10
    problemTen("./text-files/EMPLOYEE.DAT", "./text-files/EMPLOYEE.DAT", 1);

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 12
    // generateComputerData("./text-files/SHIP.DAT", 3);
    readFile("./text-files/SHIP.DAT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 13
    // generateStudentData("./text-files/STUDENT.DAT", 3);
    problemThirteen("./text-files/STUDENT.DAT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 14
    cout << "[Problem 14]" << endl;
    cout << "Statement 1: File.seekg(0, ios::end)" << endl;
    cout << "Statement 2: File.tellg()" << endl;

    cout << endl << "-------------------------------------------------------" << endl << endl;

    // Problem 15
    problemFifteen("./text-files/STUDENT1.DAT", 1);
    readStudData("./text-files/STUDENT1.DAT");

    cout << "-------------------------------------------------------" << endl << endl;

    // Problem 16
    cout << "[Problem 16]" << endl;
    cout << "Statement 1: File.seekg((RecNo - 1) * sizeof(Item), ios::beg);" << endl;
    cout << "Statement 2: File.seekp((RecNo - 1) * sizeof(Item), ios::beg);" << endl;

    cout << endl << "-------------------------------------------------------" << endl << endl;

    return 0;
}
