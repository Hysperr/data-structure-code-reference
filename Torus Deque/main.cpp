#include <iostream>
#include "deque.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    deque<int> d;
    d.push_front(1);
    std::cout << d.get_first() << std::endl;    // 9
    d.push_front(2);
    d.push_front(3);
    std::cout << d.front() << std::endl;        // 3
    std::cout << d.get_first() << std::endl;    // 7

    d.push_back(88);
    d.push_back(99);
    std::cout << d.back() << std::endl;         // 99
    std::cout << d.get_last() << std::endl;     // 3


    return 0;
}