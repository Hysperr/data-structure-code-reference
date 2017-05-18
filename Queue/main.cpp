#include <iostream>
#include "queue.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "default capacity: " << queue<int>::capacity() << std::endl;

    queue<int> q;
    for (int i = 0; i < 10; i++) q.insert(i);
    std::cout << "10 customers in line..." << std::endl;
    q.print_queue();

    std::cout << "customer has finished purchase..." << std::endl;
    q.remove();
    q.print_queue();
    std::cout << "current space left: " << q.current_space_left() << std::endl;


    std::cout << "another customer has finished purchase..." << std::endl;
    q.remove();
    q.print_queue();
    std::cout << "current space left: " << q.current_space_left() << std::endl;
    std::cout << "queue size is now: " << q.size() << std::endl;

    std::cout << "removing elements from queue...\n";
    int qsize = (int) q.size();
    for (int i = 0; i < qsize; i++) {
        std::cout << q.remove() << std::endl;
    }
    assert(q.size() == 0);

    std::cout << "queue size: " << q.size() << std::endl;
    q.print_queue();

    return 0;
}
