
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

template<typename T>
class queue {

    const static int ARRAY_SIZE = 5;

public:
    queue();

    ~queue();

    void insert(T element);

    T remove();

    bool isFull() const;

    bool isEmpty() const;

    void print_queue() const;

private:
    T data[ARRAY_SIZE];
    int front;  // where next elem removed
    int back;   // where next elem inserted

};

#include "queue.template"


#endif //QUEUE_QUEUE_H
