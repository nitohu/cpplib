#include <iostream>
#include <vector>

#include "datatype.h"
#include "timer.h"

void printIntArr(IntArray *x) {
    std::cout << "length: " << x->get_length() << std::endl;
    for (int i = 0; i < x->get_length(); i++) {
        std::cout << i << " " << x->at(i) << std::endl;
    }
}

int main() {
    // Datatype
    IntArray *a = new IntArray{1, 2, 3, 4, 5, 6};
    a->prepend(10);
    a->prepend(20);
    printIntArr(a);
    std::cout << a << std::endl;
    a->pop();
    a->pop();
    printIntArr(a);
    std::cout << "2nd item: " << (*a)[1] << std::endl;
    std::cout << a << std::endl;
    a->cut(0, 1);
    a->cut(a->get_length()-2, a->get_length());
    std::cout << a << std::endl;

    // Timer
    Timer t = Timer(5);
    t.startTimer();
    int ld = 0;
    while (!t.finished()) {
    }
    std::cout << "Timer has passed" << std::endl;
}
