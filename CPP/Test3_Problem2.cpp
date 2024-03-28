#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void mt1() {
    for (int i = 1; i <= 10000; ++i) {
        cout << "1:" << i << endl;
    }
}

void mt2() {
    for (int i = 2; i <= 20000; i += 2) {
        cout << "2:" << i << endl;
    }
}

void mt3() {
    for (int i = 7; i <= 70000; i += 7) {
        cout << "3:" << i << endl;
    }
}

int main() {
    thread thread1(mt1);
    thread thread2(mt2);
    thread thread3(mt3);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
