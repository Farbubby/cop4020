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
            cout << "[Student info]" << endl;
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
            cout << "[Batsman info]" << endl;
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
        void schedule(int testCode, string description, float noCandidate) {
            this->testCode = testCode;
            this->description = description;
            this->noCandidate = noCandidate;
            centerReqd = calcNtr();
        }

        void dispTest() {
            cout << "[Test info]" << endl;
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
        else {
            return 0;
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
            cout << "[Flight info]" << endl;
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
        void input(int bookNo, string bookTitle, float price) {
            this->bookNo = bookNo;
            this->bookTitle = bookTitle;
            this->price = price;
        }

        void purchase(int n) {
            cout << "[Book info]" << endl;
            cout << "Book no.: " << bookNo << endl;
            cout << "Book title: " << bookTitle << endl;
            cout << "Price: " << price << endl;
            cout << "No. of copies: " << n << endl;
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
        int size = 5;
        for (int i = 0; i < size; i++) {
            sum += marks[i];
        }
        return (sum / size);
    }
    void printMarks() {
        int size = 5;
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
            cout << "[Report info]" << endl;
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
    // Problem 1
    Student student1;
    student1.takeData(1, "John", 90, 80, 70);
    student1.showData();

    cout << "-------------------------------------------------------" << endl;

    // Problem 2
    Batsman batsman1;
    batsman1.readData(1, "John", 10, 2, 500);
    batsman1.displayData();

    cout << "-------------------------------------------------------" << endl;

    // Problem 3
    Test test1;
    test1.schedule(1, "Math", 100);
    test1.dispTest();

    cout << "-------------------------------------------------------" << endl;

    // Problem 4
    Flight flight1;
    flight1.feedInfo(1, "New York", 1500);
    flight1.showInfo();

    cout << "-------------------------------------------------------" << endl;

    // Problem 5
    Book book1;
    book1.input(16, "Cooking", 5.99);
    book1.purchase(5);

    cout << "-------------------------------------------------------" << endl;

    // Problem 6
    Report report1;
    float marks[] = {90, 80, 70, 60, 50};
    report1.readInfo(1, "John", marks);
    report1.displayInfo();

    cout << "-------------------------------------------------------" << endl;

    // Problem 7b
    Rectangle rectangle1, rectangle2;
    rectangle1.setLength(5);
    rectangle1.setWidth(2.5);
    rectangle2.setLength(5);
    rectangle2.setWidth(18.9);

    cout << "[Rectangle 1 info]" << endl;
    rectangle1.show();
    cout << "Perimeter: " << rectangle1.perimeter() << endl;
    cout << "Area: " << rectangle1.area() << endl;

    cout << endl;

    cout << "[Rectangle 2 info]" << endl;
    rectangle2.show();
    cout << "Perimeter: " << rectangle2.perimeter() << endl;
    cout << "Area: " << rectangle2.area() << endl;

    cout << endl;

    // Problem 7c
    cout << "Are the areas of the rectangles the same? " << (rectangle1.sameArea(rectangle2) == 1 ? "Yes" : "No") << endl;

    cout << endl;

    rectangle1.setLength(15);
    rectangle1.setWidth(6.3);

    cout << "[Rectangle 1 info]" << endl;
    rectangle1.show();
    cout << "Perimeter: " << rectangle1.perimeter() << endl;
    cout << "Area: " << rectangle1.area() << endl;

    cout << endl;

    cout << "[Rectangle 2 info]" << endl;
    rectangle2.show();
    cout << "Perimeter: " << rectangle2.perimeter() << endl;
    cout << "Area: " << rectangle2.area() << endl;

    cout << endl;

    cout << "Are the areas of the rectangles the same? " << (rectangle1.sameArea(rectangle2) == 1 ? "Yes" : "No") << endl;

    cout << "-------------------------------------------------------" << endl;

    // Problem 8b
    Complex complex1, complex2, complex3;
    complex1.set(5, 3);
    complex2.set(2, 4);
    complex3 = complex1.sum(complex2);

    cout << "[Complex 1 info]" << endl;
    complex1.disp();

    cout << endl;

    cout << "[Complex 2 info]" << endl;
    complex2.disp();

    cout << endl;

    cout << "[Complex 3 info]" << endl;
    complex3.disp();

    cout << "-------------------------------------------------------" << endl;

    // Problem 9b
    Distance distance1, distance2, distance3;
    distance1.set(5, 3.5);
    distance2.set(2, 4.5);
    distance3 = distance1.add(distance2);

    cout << "[Distance 1 info]" << endl;
    distance1.disp();

    cout << endl;

    cout << "[Distance 2 info]" << endl;
    distance2.disp();

    cout << endl;

    cout << "[Distance 3 info]" << endl;
    distance3.disp();

    cout << "-------------------------------------------------------" << endl;

    // Problem 10b
    Time time1, time2, time3;
    time1.setTime(5, 30);
    time2.setTime(2, 45);
    time3 = time1.sum(time2);

    cout << "[Time 1 info]" << endl;
    time1.showTime();

    cout << endl;

    cout << "[Time 2 info]" << endl;
    time2.showTime();

    cout << endl;

    cout << "[Time 3 info]" << endl;
    time3.showTime();

    return 0;
}