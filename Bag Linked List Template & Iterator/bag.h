
#ifndef BAG_H
#define BAG_H


/**
TEMPLATE CLASS PROVIDED:
bag<Item> (a collection of items; each item may appear multiple times)

TYPEDEFS for the bag<Item> template class:
bag<Item>::value_type
This is the Item type from the template parameter.
It is the data type of the items in the bag. It may be any
of the C++ built-in types (int, char, etc.), or a class with a default
constructor, a copy constructor, an assignment
operator, and a test for equality (x == y).

bag<Item>::size_type
This is the data type of any variable that keeps track of how many items
are in a bag

bag<Item>::iterator and bag<Item>::const_iterator
Forward iterators for a bag or a const bag.

CONSTRUCTOR for the bag<Item> class:
bag( )
Postcondition: The bag is empty.

MODIFICATION MEMBER FUNCTIONS for the bag<Item> class:
size_type erase(const Item& target)
Postcondition: All copies of target have been removed from the bag.
The return value is the number of copies removed (which could be zero).

bool erase_one(const Item& target)
Postcondition: If target was in the bag, then one copy of target has
been removed from the bag; otherwise the bag is unchanged. A true
return value indicates that one copy was removed; false indicates that
nothing was removed.

void insert(const Item& entry)
Postcondition: A new copy of entry has been inserted into the bag.

void operator +=(const bag& addend)
Postcondition: Each item in addend has been added to this bag.

CONSTANT MEMBER FUNCTIONS for the bag<Item> class:
size_type count(const Item& target) const
Postcondition: Return value is number of times target is in the bag.

Item grab( ) const
Precondition: size( ) > 0.
Postcondition: The return value is a randomly selected item from the bag.

size_type size( ) const
Postcondition: Return value is the total number of items in the bag.

STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
iterator begin( )
const_iterator begin( ) const
iterator end( )
const iterator end( ) const

NONMEMBER FUNCTIONS for the bag<Item> class:
template <class Item>
bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
Postcondition: The bag returned is the union of b1 and b2.

VALUE SEMANTICS for the bag<Item> class:
Assignments and the copy constructor may be used with bag objects.

DYNAMIC MEMORY USAGE by the bag<Item>:
If there is insufficient dynamic memory, then the following functions throw
bad_alloc: The constructors, insert, operator +=, operator +, and the
assignment operator.
*/


#include <cstdlib>   // Provides size_t
#include "node.h"


template<typename Item>
class bag {
public:
    // TYPEDEFS
    typedef std::size_t size_type;
    typedef Item value_type;
    typedef node_iterator<Item> iterator;
    typedef const_node_iterator<Item> const_iterator;

    // CONSTRUCTORS and DESTRUCTOR
    bag();

    bag(const bag &source);

    ~bag();

    // MODIFICATION MEMBER FUNCTIONS
    size_type erase(const Item &target);

    bool erase_one(const Item &target);

    void insert(const Item &entry);

    void operator+=(const bag &addend);

    void operator=(const bag &source);

    void print_value_range(const Item &x, const Item &y);

    void remove_repetitions();

    // CONST MEMBER FUNCTIONS
    size_type count(const Item &target) const;

    Item grab() const;

    size_type size() const { return many_nodes; }

    // FUNCTIONS TO PROVIDE ITERATORS
    iterator begin() { return iterator(head_ptr); }

    const_iterator begin() const { return const_iterator(head_ptr); }

    iterator end() { return iterator(); } // nullptr, see constructor

    const_iterator end() const { return const_iterator(); }

private:
    node<Item> *head_ptr;
    size_type many_nodes;
};

// NONMEMBER functions for the bag
template<typename Item>
bag<Item> operator+(const bag<Item> &b1, const bag<Item> &b2);


// The implementation of a template class must be included in its header file:
#include "bag.template"


#endif // BAG_H
