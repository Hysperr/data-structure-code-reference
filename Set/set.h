
#ifndef SET_SET_H
#define SET_SET_H


#include <cstdlib>

class set {

    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 50;

public:


    // CONSTRUCTORS, DESTRUCTOR
    set(size_type initial_capacity = DEFAULT_CAPACITY);
    set(const set &source);
    ~set();

    void reserve(size_type new_capacity);
    bool erase_one(const value_type &target);
    size_type erase(const value_type &target);
    void insert(const value_type &entry);
    void operator +=(const set &addend);
    void operator -=(const set &addend);

    // CONSTANT MEMBER FUNCTIONS
    size_type size() const { return used; }
    bool contains(const value_type &target) const;

private:

    size_type used;     // number of items in set
    size_type capacity; // current capacity of the set
    value_type *data;   // pointer to partially filled dynamic array

};

// non member functions for set class
set operator +(const set &s1, const set &s2);

#endif //SET_SET_H
