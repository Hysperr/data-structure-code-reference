
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <cstddef>

template<typename T>
class queue {

    typedef size_t size_type;
    const static int ARRAY_SIZE = 30;

public:
    queue();

    void insert(T element);

    T remove();

    bool isFull() const;

    bool isEmpty() const;

    void print_queue() const;

    size_type size() const { return used; }

    static const int capacity() { return ARRAY_SIZE; }

    size_type current_space_left() const { return ARRAY_SIZE - used; }

private:
    T data[ARRAY_SIZE];
    int front;  // where next elem removed
    int back;   // where next elem inserted
    size_type used;
};

#include "queue.template"


#endif //QUEUE_QUEUE_H
