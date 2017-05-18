/**
 CLASS PROVIDED: bag (a container class for a collection of items)

 TYPEDEFS and MEMBER CONSTANTS for the bag class:
   typedef _____ value_type
     bag::value_type is the data type of the items in the bag. It may be any of
     the C++ built-in types (int, char, etc.), or a class with a default
     constructor, an assignment operator, and operators to
     test for equality (x == y) and non-equality (x != y).

   typedef _____ size_type
     bag::size_type is the data type of any variable that keeps track of how
     many items are in a bag.

   static const size_type DEFAULT_CAPACITY = _____
     bag::DEFAULT_CAPACITY is the initial capacity of a bag that is created
     by the default constructor.

 CONSTRUCTOR for the bag class:
   bag(size_type initial_capacity = DEFAULT_CAPACITY)
     Postcondition: The bag is empty with an initial capacity given by the
     parameter. The insert function will work efficiently (without
     allocating new memory) until this capacity is reached.

 MODIFICATION MEMBER FUNCTIONS for the bag class:
   void reserve(size_type new_capacity)
     Postcondition: The bag's current capacity is changed to the
     new_capacity (but not less than the number of items already in the
     bag). The insert function will work efficiently (without allocating
     new memory) until the new capacity is reached.

   size_type erase(const value_type& target);
     Postcondition: All copies of target have been removed from the bag.
     The return value is the number of copies removed (which could be zero).

   void erase_one(const value_type& target)
     Postcondition: If target was in the bag, then one copy has been removed;
     otherwise the bag is unchanged. A true return value indicates that one
     copy was removed; false indicates that nothing was removed.

   void insert(const value_type& entry)
     Postcondition: A new copy of entry has been inserted into the bag.

   void operator +=(const bag& addend)
     Postcondition: Each item in addend has been added to this bag.

 CONSTANT MEMBER FUNCTIONS for the bag class:
   size_type size( ) const
     Postcondition: Return value is the total number of items in the bag.

   size_type count(const value_type& target) const
     Postcondition: Return value is number of times target is in the bag

 NONMEMBER FUNCTIONS for the bag class:
   bag operator +(const bag& b1, const bag& b2)
   Postcondition: The bag returned is the union of b1 and b2.

 VALUE SEMANTICS for the bag class:
   Assignments and the copy constructor may be used with bag objects.

 DYNAMIC MEMORY USAGE by the bag:
   If there is insufficient dynamic memory, then the following functions throw
   bad_alloc: The constructors, reserve, insert, operator += ,
   operator +, and the assignment operator.
*/

#ifndef DYNAMIC_ARRAY_BAG_H
#define DYNAMIC_ARRAY_BAG_H


#include <cstdlib>

class bag {
public:
    // TYPEDEFS and MEMBER CONSTANTS
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 30;

    // CONSTRUCTORS and DESTRUCTOR
    bag(size_type initial_capacity = DEFAULT_CAPACITY);

    bag(const bag &source);

    ~bag();

    // MODIFICATION MEMBER FUNCTIONS
    void reserve(size_type new_capacity);

    bool erase_one(const value_type &target);

    size_type erase(const value_type &target);

    void insert(const value_type &entry);

    void operator+=(const bag &addend);

    void operator-=(const bag &addend);

    void operator=(const bag &source);

    bool contains(const value_type &target) const;

    // CONSTANT MEMBER FUNCTIONS
    size_type size() const { return used; }

    size_type count(const value_type &target) const;

private:
    value_type *data;
    size_type used;
    size_type capacity;
};

// NONMEMBER FUNCTIONS for the bag class
bag operator+(const bag &b1, const bag &b2);

bag operator-(const bag &b1, const bag &b2);


#endif //DYNAMIC_ARRAY_BAG_H
