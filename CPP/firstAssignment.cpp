#include <iostream>
#include <string>
using namespace std;

// Problem 1
class Student {
    int admNo;
    string sName;
    float eng, math, science;
    float total;
    float cTotal() {
        return (eng + math + science);
    }

    public:
        void takeData(int admNo, string sName, float eng, float math, float science) {
            this->admNo = admNo;
            this->sName = sName;
            this->eng = eng;
            this->math = math;
            this->science = science;
            total = cTotal();
        }

        void showData() {
            cout << "Admission no.: " << admNo << endl;
            cout << "Student name: " << sName << endl;
            cout << "English: " << eng << endl;
            cout << "Math: " << math << endl;
            cout << "Science: " << science << endl;
            cout << "Total: " << total << endl;
        }
};

// Problem 2
class Batsman {
    int bCode;
    string bName;
    int innings, notOut, runs;
    float batAvg;
    float calcAvg() {
        return (runs / (innings - notOut));
    }

    public:
        void readData(int bCode, string bName, int innings, int notOut, int runs) {
            this->bCode = bCode;
            this->bName = bName;
            this->innings = innings;
            this->notOut = notOut;
            this->runs = runs;
            batAvg = calcAvg();
        }

        void displayData() {
            cout << "Batsman code: " << bCode << endl;
            cout << "Batsman name: " << bName << endl;
            cout << "Innings: " << innings << endl;
            cout << "Not out: " << notOut << endl;
            cout << "Runs: " << runs << endl;
            cout << "Bat average: " << batAvg << endl;
        }
};

// Problem 3
class Test {
    int testCode;
    string description;
    float noCandidate;
    int centerReqd;
    float calcNtr() {
        return (noCandidate / 100 + 1);
    }

    public:
        void schedule() {
            cout << "Enter test code: ";
            cin >> testCode;
            cout << "Enter description: ";
            cin >> description;
            cout << "Enter number of candidates: ";
            cin >> noCandidate;

            centerReqd = calcNtr();
        }

        void dispTest() {
            cout << "Test Code: " << testCode << endl;
            cout << "Description: " << description << endl;
            cout << "No. candidates: " << noCandidate << endl;
            cout << "Centers required: " << centerReqd << endl;
        }
};

// Problem 4
class Flight {
    int flightNo;
    string destination;
    float distance;
    float fuel;
    float calFuel() {
        if (distance <= 1000) {
            return 500;
        } else if (distance > 1000 && distance <= 2000) {
            return 1100;
        } else if (distance > 2000) {
            return 2200;
        }
    }

    public:
        void feedInfo(int flightNo, string destination, float distance) {
            this->flightNo = flightNo;
            this->destination = destination;
            this->distance = distance;
            fuel = calFuel();
        }

        void showInfo() {
            cout << "Flight no.: " << flightNo << endl;
            cout << "Destination: " << destination << endl;
            cout << "Distance: " << distance << endl;
            cout << "Fuel: " << fuel << endl;
        }
};

// Problem 5
class Book {
    int bookNo;
    string bookTitle;
    float price;
    float totalCost(int n) {
        return (price * n);
    }

    public:
        void input() {
            cout << "Enter book no.: ";
            cin >> bookNo;
            cout << "Enter book title: ";
            cin >> bookTitle;
            cout << "Enter price: ";
            cin >> price;
        }

        void purchase() {
            int n;
            cout << "Enter number of copies: ";
            cin >> n;
            cout << "Book no.: " << bookNo << endl;
            cout << "Book title: " << bookTitle << endl;
            cout << "Total cost: " << totalCost(n) << endl;
        }
};

// Problem 6
class Report {
    int adno;
    string name;
    float *marks;
    float average;
    float getAvg() {
        float sum = 0;
        float size = sizeof(marks) / sizeof(marks[0]);
        for (int i = 0; i < size; i++) {
            sum += marks[i];
        }
        return (sum / 5);
    }
    void printMarks() {
        float size = sizeof(marks) / sizeof(marks[0]);
        for (int i = 0; i < size; i++) {
            cout << marks[i] << " ";
        }
    }

    public:
        void readInfo(int adno, string name, float *marks) {
            this->adno = adno;
            this->name = name;
            this->marks = marks;
            average = getAvg();
        }

        void displayInfo() {
            cout << "Admission no.: " << adno << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: ";
            printMarks();
            cout << endl;
            cout << "Average: " << average << endl;
        }
};

// Problem 7a
class Rectangle {
    float length, width;

    public:
        void setLength(float length) {
            this->length = length;
        }
        void setWidth(float width) {
            this->width = width;
        }
        float perimeter() {
            return (2 * (length + width));
        }
        float area() {
            return (length * width);
        }
        void show() {
            cout << "Length: " << length << endl;
            cout << "Width: " << width << endl;
        }
        int sameArea(Rectangle r) {
            return (area() == r.area());
        }
};

// Problem 8a
class Complex {
    float real, imag;

    public:
        void set(float real, float imag) {
            this->real = real;
            this->imag = imag;
        }
        void disp() {
            cout << "Real: " << real << endl;
            cout << "Imaginary: " << imag << endl;
        }
        Complex sum(Complex c) {
            Complex temp;
            temp.real = real + c.real;
            temp.imag = imag + c.imag;
            return temp;
        }
};

// Problem 9a
class Distance {
    int feet;
    float inches;

    public:
        void set(int feet, float inches) {
            this->feet = feet;
            this->inches = inches;
        }
        void disp() {
            cout << "Feet: " << feet << endl;
            cout << "Inches: " << inches << endl;
        }
        Distance add(Distance d) {
            Distance temp;
            temp.feet = feet + d.feet;
            temp.inches = inches + d.inches;
            return temp;
        }
};

// Problem 10a
class Time {
    int hours, minutes;

    public:
        void setTime(int hours, int minutes) {
            this->hours = hours;
            this->minutes = minutes;
        }
        void showTime() {
            cout << "Hours: " << hours << endl;
            cout << "Minutes: " << minutes << endl;
        }
        Time sum(Time t) {
            Time temp;
            temp.hours = hours + t.hours;
            temp.minutes = minutes + t.minutes;
            return temp;
        }
};

int main() {
    return 0;
}