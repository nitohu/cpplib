#include <iostream>
#include <vector>

#include "linkedlist.h"
#include "timer.h"

int main() {
    using namespace nitohu;
    // Datatype
    LinkedList<int> *a = new LinkedList<int>{1, 2, 3, 4, 5, 6};
    LinkedList<double> b = LinkedList<double>{0.0, 1.0, 4.0, 9.0, 16.0};
    a->prepend(10);
    a->prepend(20);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a->pop();
    a->pop();

    std::cout << a << std::endl;
    std::cout << "2nd item: " << (*a)[1] << std::endl;

    a->cut(0, 1);
    a->cut(a->get_length()-2, a->get_length());

    std::cout << a << std::endl;

    // Timer
    // nitohu::Timer t = nitohu::Timer(5);
    // t.startTimer();
    // int ld = 0;
    // while (!t.finished()) {
    // }
    // std::cout << "Timer has passed" << std::endl;

    return 0;
}
