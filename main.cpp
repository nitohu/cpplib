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
    a->prepend(10);
    a->prepend(20);
    std::cout << a << std::endl;
    a->pop();
    a->pop();
    std::cout << "2nd item: " << (*a)[1] << std::endl;
    std::cout << a << std::endl;
    a->cut(0, 1);
    a->cut(a->get_length()-2, a->get_length());

    std::cout << a << std::endl;

    std::cout << "===== Arrays =====" << std::endl;
    Array<int, 5> c;
    for (size_t i = 0; i < c.get_length(); i++) {
        c[i] = i*i;
        std::cout << c[i] << std::endl;
    }

    Array<std::string, 3> e = Array<std::string, 3>{"Hello", "world", "datatypes"};
    if (e.contains("world")) {
        std::cout << "e contains world!" << std::endl;
    } else {
        std::cout << "e doesn't contain world!" << std::endl;
    }
    std::cout << e[4] << std::endl;
    
    std::cout << "==== Constant Array\n";
    const Array<int, 2> d = Array<int, 2>{80, 50};
    // d[0] = 20;          // Will throw an error
    for (auto &it : d) {
        std::cout << &it << ": " << it << std::endl;
    }

    // std::cout << "===== Timer =====" << std::endl;
    // Timer
    Timer t = Timer(3);
    t.startTimer();
    int ld = 0;
    while (!t.finished()) {
    }
    std::cout << "Timer (3s) has passed" << std::endl;

    return 0;
}
