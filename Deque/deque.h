#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#include <cstddef>

template<typename T>
class deque {

    static const std::size_t CAPACITY = 10;
    typedef std::size_t size_type;

public:

    // postcondition: empty deque has been created
    deque();

    // precondition: deque is not empty
    // postcondition: reference to element at front of deque has been returned
    T &front();

    // precondition: deque is not empty
    // postcondition: copy of element at front of deque has been returned
    T front() const;

    // precondition: deque is not empty
    // postcondition: reference to element at front of deque has been returned
    T &back();

    // precondition: deque is not empty
    // postcondition: copy of element at back of deque has been returned
    T back() const;

    // precondition: deque is not full
    // postcondition: entry has been inserted at the front of the deque
    void push_front(const T &entry);

    // precondition: deque is not full
    // postcondition: entry has been inserted at the back of the deque
    void push_back(const T &entry);

    // precondition: deque is not empty
    // postcondition: element at front of deque has been removed
    void pop_front();

    // precondition: deque is not empty
    // postcondition: element at back of deque has been removed
    void pop_back();

    size_type size() const { return count; }

    bool empty() const { return count == 0; }

    bool full() const { return count == CAPACITY; }

private:

    T data[CAPACITY];
    size_type first;
    size_type last;
    size_type count;

};


#include "deque.template"


#endif //DEQUE_DEQUE_H
