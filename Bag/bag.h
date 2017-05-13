#ifndef BAG_H
#define BAG_H

#include <cstdlib>

class bag {
public:
    typedef int value_type;  // type of elements allowed in the bag
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30000;

    /**
     * initializes an empty bag.
     */
    bag();

    /**
     * Remove every copy of target from the bag.
     * Return how many were removed.
     */
    size_type erase(const value_type &target);

    /**
     * Remove one copy of target from the bag.
     * Return true if an object was removed.
     * Return false if an object was not removed
     */
    bool erase_one(const value_type &target);

    /**
     * Insert one more object 'entry' into the bag
     */
    void insert(const value_type &entry);

    /**
     * Add all the objects from addend to this bag.
     */
    void operator+=(const bag &addend);

    /**
     * Return the total number of all objects in this bag.
     */
    size_type size() const;

    /**
     * Return the number of object 'target' in this bag.
     */
    size_type count(const value_type &target) const;

    /**
     * Prints contents of bag
     */
    void printBag() const;

private:
    value_type data[CAPACITY];
    // store the objects in the bag at the beginning of the data array
    size_type used;
    // tells how many of the elements in data are actually active


};

bag operator+(const bag &b1, const bag &b2);

#endif // BAG_H
