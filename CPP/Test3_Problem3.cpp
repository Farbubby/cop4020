#include <iostream>
#include <string>

using namespace std;

class MyPrinter {
protected:
    static MyPrinter* printer;
    MyPrinter() {}

public:
    static MyPrinter* getInstance();

    void print(const string& str) {
        cout << "Printing some string: " << str << endl;
    }
};

MyPrinter* MyPrinter::printer = nullptr;

MyPrinter* MyPrinter::getInstance()
{
    if (printer == nullptr) {
        printer = new MyPrinter();
    }
    return printer;
}

int main() {
    MyPrinter* p1 = MyPrinter::getInstance();
    MyPrinter* p2 = MyPrinter::getInstance();
    MyPrinter* p3 = MyPrinter::getInstance();

    p1->print("Hi 1");
    p2->print("Hi 2");
    p3->print("Hi 3");

    return 0;
}
