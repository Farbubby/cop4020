#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    virtual void sayIt() = 0;
    void doIt() {
        cout << "Doing something..." << endl;
    }
};

class PsychologyMajor : public Person {
public:
    void sayIt() override {
        cout << "PsychologyMajor output" << endl;
    }
};

class ComputerScienceMajor : public Person {
public:
    void sayIt() override {
        cout << "ComputerScienceMajor output" << endl;
    }
};

class Barista : public Person {
public:
    void sayIt() override {
        cout << "Barista output" << endl;
    }
};

int main() {
    PsychologyMajor a;
    ComputerScienceMajor b;
    Barista c;
    Person *f;

    cout << "Output:" << endl << endl;

    f = (Person *)&a;
    f->sayIt();
    f = (Person *)&b;
    f->sayIt();
    f = (Person *)&c;
    f->sayIt();

    return 0;
}
