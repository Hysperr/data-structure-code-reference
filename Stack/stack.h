
#ifndef STACK_STACK_H
#define STACK_STACK_H


#include <cstddef>
#include <cassert>
#include <iostream>

template<typename T>
class stack {

    typedef std::size_t size_type;
    const static size_type CAPACITY = 30;

public:

    stack();

    T pop();

    void clear();

    void push(T element);

    bool isEmpty() const { return used == 0; };

    bool isFull() const { return used == CAPACITY; }

    size_type size() const { return used; }

    void print_stack() const;

private:
    T data[CAPACITY];
    size_type used;
};


template<typename T>
stack<T>::stack() {
    used = 0;
}

template<typename T>
T stack<T>::pop() {
    if (isEmpty()) std::cout << "stack is empty...\n";
    T val = data[used - 1];     /*!< last elem in array which is top of stack) */
    used--;
    return val;
}

template<typename T>
void stack<T>::push(T element) {
    if (!isFull()) {
        data[used] = element;
        used++;
    }
    else std::cout << "Nothing inserted. Stack already full...\n";
}

template<typename T>
void stack<T>::clear() {
    while (!isEmpty()) pop();
}

/**
 * Must use <code>int i</code> since this template function
 * is defined in header, it is instantiated at compile time.
 * compiler instantiates <code>used = 0</code>, which when minus 1
 * gives a negative number. \c size_type, which is typedef of
 * \c std::size_t from \c cstddef is usually
 * <code>unsigned long long int</code>
 * ULL on most systems, used to hold very large POSITIVE
 * integer values. Thus, if size_type used, you assign
 * negative value to positive-only data type at compile time
 * and the function exhibits undefined behavior.
 * @tparam T
 */
template<typename T>
void stack<T>::print_stack() const {
    if (isEmpty()) std::cout << "stack is empty...\n";
    int i = used - 1;   // see function documentation
    for (; i >= 0; i--) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}


#endif //STACK_STACK_H
