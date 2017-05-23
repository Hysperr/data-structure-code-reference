
#include "stack.h"
#include <iostream>

using namespace std;

int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);  // top of stack
    s.print_stack();
    cout << "stack size: " << s.size() << endl;

    cout << "pop item off stack: " << s.pop() << endl;
    s.print_stack();
    cout << "updated stack size: " << s.size() << endl;

    cout << "clearing stack...\n";
    s.clear();
    cout << "print stack: \n";
    s.print_stack();

    stack<int> another_stack;
    for (int i = 0; i < 30; i++) {
        another_stack.push(i);
    }
    cout << "another_stack's size: " << another_stack.size() << endl;
    another_stack.print_stack();

    return 0;
}
