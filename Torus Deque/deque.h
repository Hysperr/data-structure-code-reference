/**
 * @author Gary K.
 * @date 2017-04-06 YYYY-MM-DD
 * @brief A variant template implementation of an STL Deque container.
 * This is a special deque, one that is both circular AND inverted
 * to provide slightly better run-time performance and easier
 * iterator support. It behaves as a normal deque should, but the
 * internal implementation is unique. Picture a torus-shaped array.
 * In the function \c push_front() the private data field \c first
 * is at index 0 and moves left after each insert at \c data[first].
 * In the function \c push_back() private data field \c last begins
 * at index 1 and moves right after each insert at \c data[last].
 * For users of the container, these implementation details need not be known.
 */


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

    bool empty() const { return count == 0; }       // or first + 1 % cap == last

    bool full() const { return count == CAPACITY; } // or last == first

    size_type get_first() const { return first; }

    size_type get_last() const { return last; }

private:

    T data[CAPACITY];
    size_type first;    // front of deque, moves left due to reverse torus
    size_type last;     // back of deque, moves right due to reverse torus
    size_type count;

};


#include "deque.template"


#endif //DEQUE_DEQUE_H
