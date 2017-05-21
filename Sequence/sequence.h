

#ifndef SEQUENCE_SEQUENCE_H
#define SEQUENCE_SEQUENCE_H

#include <cstdlib>

class sequence {

    typedef double value_type;
    typedef std::size_t size_type;

public:
    static const size_type CAPACITY = 30;
    sequence();
    void start() { current_index = 0; }
    void advance() { current_index++; }
    void remove_current();
    void insert(const value_type& entry);
    void attach(const value_type& entry);

    value_type current() const { return data[current_index]; }

    //CONSTANT MEMBER FUNCTIONS
    bool is_item() const { return current_index < used; }
    size_type get_current_index() const { return current_index; };
    void print_sequence() const;
    size_type size() const { return used; }

private:
    value_type data[CAPACITY];
    size_type used;
    size_type current_index;
};


#endif //SEQUENCE_SEQUENCE_H
