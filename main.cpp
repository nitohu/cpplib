#include <iostream>
#include <vector>

#include "linkedlist.h"
#include "array.h"
#include "timer.h"

int main() {
    using namespace nitohu;
    // Linked Lists
    std::cout << "===== Linked Lists =====" << std::endl;
    LinkedList<int> *a = new LinkedList<int>{1, 2, 3, 4, 5, 6};
    LinkedList<double> b = LinkedList<double>{0.0, 1.0, 4.0, 9.0, 16.0};
    a->prepend(10);
    a->prepend(20);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a->pop();
    a->pop();

    std::cout << "1st item: " << (*a)[0] << std::endl;
    std::cout << "2nd item: " << (*a)[1] << std::endl;
    std::cout << a << std::endl;

    a->cut(0, 1);
    a->cut(a->get_length()-2, a->get_length());

    std::cout << a << std::endl;

    std::cout << "===== Arrays =====" << std::endl;
    Array<int, 5> c;
    for (size_t i = 0; i < c.get_length(); i++) {
        std::cout << c[i] << std::endl;
        c[i] = i;
    }
    std::cout << "====\n";
    for (size_t i = 0; i < c.get_length(); i++) {
        c[i] = i;
        std::cout << c[i] << std::endl;
    }
    std::cout << "==== Constant Array\n";
    Array<int, 2> *d = new Array<int, 2>{80, 50};
    // d[0] = 20;          // Will throw an error
    for (size_t i = 0; i < d->get_length(); i++) {
        std::cout << (*d)[i] << std::endl;
    }
    for (auto &it : *d) {
        std::cout << &it << ": " << it << std::endl;
    }

    // std::cout << "===== Timer =====" << std::endl;
    // Timer
    // nitohu::Timer t = nitohu::Timer(5);
    // t.startTimer();
    // int ld = 0;
    // while (!t.finished()) {
    // }
    // std::cout << "Timer has passed" << std::endl;

    return 0;
}
