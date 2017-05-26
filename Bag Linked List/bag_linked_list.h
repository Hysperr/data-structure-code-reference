/**
TYPEDEFS for the bag class:
bag::value_type
is the data type of the items in the bag. It may be any
of the C++ built-in types (int, char, etc.), or a class with a default
constructor, a copy constructor, an assignment
operator, and a test for equality (x == y).

bag::size_type
is the data type of any variable that keeps track of how many items are
in a bag

CONSTRUCTOR for the bag class:
bag( )
Postcondition: The bag is empty.

MODIFICATION MEMBER FUNCTIONS for the bag class:
size_type erase(const value_type& target)
Postcondition: All copies of target have been removed from the bag.
The return value is the number of copies removed (which could be zero).

bool erase_one(const value_type& target)
Postcondition: If target was in the bag, then one copy of target has
been removed from the bag; otherwise the bag is unchanged. A true
return value indicates that one copy was removed; false indicates that
nothing was removed.

void insert(const value_type& entry)
Postcondition: A new copy of entry has been inserted into the bag.

void operator +=(const bag& addend)
Postcondition: Each item in addend has been added to this bag.

CONSTANT MEMBER FUNCTIONS for the bag class:
size_type size( ) const
Postcondition: Return value is the total number of items in the bag.

size_type count(const value_type& target) const
Postcondition: Return value is number of times target is in the bag.

value_type grab( ) const
Precondition: size( ) > 0.
Postcondition: The return value is a randomly selected item from the bag.

NONMEMBER FUNCTIONS for the bag class:
bag operator +(const bag& b1, const bag& b2)
Postcondition: The bag returned is the union of b1 and b2.

VALUE SEMANTICS for the bag class:
Assignments and the copy constructor may be used with bag objects.

DYNAMIC MEMORY USAGE by the bag:
If there is insufficient dynamic memory, then the following functions throw
bad_alloc: The constructors, insert, operator +=, operator +, and the
assignment operator.
*/

#ifndef BAG_LINKED_LIST_H
#define BAG_LINKED_LIST_H

#include <cstdlib>
#include "node.h"

class bag {

public:

    typedef std::size_t size_type;
    typedef node::value_type value_type;

    bag();

    bag(const bag &source);

    ~bag();

    size_type erase(const value_type &target);

    bool erase_one(const value_type &target);

    void insert(const value_type &entry);

    void operator+=(const bag &addend);

    void operator=(const bag &source);

    size_type size() const { return many_nodes; }

    size_type count(const value_type &target) const;

    value_type grab() const;

private:

    node *head_ptr;       // List head pointer
    size_type many_nodes; // Number of nodes on the list

};

// NONMEMBER FUNCTIONS for the bag class:
bag operator+(const bag &b1, const bag &b2);


#endif
