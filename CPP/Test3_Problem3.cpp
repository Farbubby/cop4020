#include <iostream>
#include <string>

using namespace std;

class MyPrinter {
public:
    static MyPrinter* getInstance() {
        static MyPrinter instance;
        return &instance;
    }

    void print(string str) {
        cout << "Printing: " << str << endl;
    }
};

int main() {
    MyPrinter* p1 = MyPrinter::getInstance();
    MyPrinter* p2 = MyPrinter::getInstance();
    MyPrinter* p3 = MyPrinter::getInstance();

    p1->print("Document 1");
    p2->print("Document 2");
    p3->print("Document 3");

    return 0;
}
