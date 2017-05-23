
#include "stack_pair.h"
#include <iostream>

using namespace std;

int main() {
    stack_pair<int> sp;

    cout << "stack_pair created with front end A & back end B." << endl;
    cout << "Is A empty? " << sp.is_empty_a() << endl;
    cout << "Is B empty? " << sp.is_empty_b() << endl;
    cout << "print stack_pair: " << endl;
    sp.print_stack_pair();
    cout << '\n';


    cout << "Capacity: " << stack_pair<int>::CAPACITY << endl;
    cout << "Push 15 items into A..." << endl;
    for (int i = 1; i <= 15; i++) {
        sp.push_a(i);
    }
    cout << "A size: " << sp.size_a() << endl;
    cout << "print stack_pair: " << endl;
    sp.print_stack_pair();
    std::cout << '\n';


    cout << "Push 18 items into B to fill stack_pair..." << endl;
    for (int i = 30; i > 15; i--) {
        sp.push_b(i);
    }
    cout << "B size: " << sp.size_b() << endl;
    cout << "print stack_pair: " << endl;
    sp.print_stack_pair();
    std::cout << '\n';


    cout << "A full? " << sp.is_full_a() << endl;
    cout << "B full? " << sp.is_full_b() << endl;

    cout << "Popping from A returns " << sp.pop_a() << endl;
    cout << "A size: " << sp.size_a() << endl;

    cout << "print stack_pair: " << endl;
    sp.print_stack_pair();
    std::cout << '\n';


    return 0;
}
