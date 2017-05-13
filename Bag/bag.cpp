#include <assert.h>
#include "bag.h"
#include <algorithm>
#include <iostream>

bag::bag() {
    used = 0;
}

/**
 * Remove every copy of target from the bag.
 * Return how many were removed.
 */
bag::size_type bag::erase(const bag::value_type &target) {
    size_type count = 0;
    while (erase_one(target)) {
        count++;
    }
    return count;
}

/**
 * Remove one copy of target from the bag.
 * Return true if an object was removed.
 * Return false if an object was not removed
 *
 * Time is a constant times the size of the bag
 *   Time it takes is O(N)
 *   N is the current size of the bag
 */
bool bag::erase_one(const bag::value_type &target) {
    int i = 0;  // examine data[i]

    // on the average we have to look through half the array  N/2 steps
    while (i < used && data[i] != target) {
        // while i is in range and data[i] is not what we are looking for
        i++;
        // go to the next
    }
    if (i < used) {
        // found it: data[i] == target
        data[i] = data[used - 1];  // replace data[i] with the last thing in the array
        used--;
        return true;
    }
    else {
        // did not find it
        return false;
    }
}

/**
 * Insert one more object 'entry' into the bag
 *
 * running time:  O(1), constant running time
 */
void bag::insert(const bag::value_type &entry) {
    if (used < CAPACITY) {
        data[used] = entry;
        used++;
    }
    else {
        throw "Out of capacity in bag";
    }
}

/**
 * Add all the objects from addend to this bag.
 * Time taken is O(M) where M is the size of addend
 */
void bag::operator+=(const bag &addend) {
    // copy elements from addend to this bag
    // copy elements from addend.data to data

    // check that there is enough space
    assert(size() + addend.size() <= CAPACITY);
    // copy the data from addend into this data array
    std::copy(addend.data, addend.data + addend.used, data + used);
    // update the size of this bag
    used += addend.used;
}

/**
 * Return the total number of all objects in this bag.
 */
bag::size_type bag::size() const {
    return used;
}

/**
 * Return the number of object 'target' in this bag.
 * time is  O(N)
 */
bag::size_type bag::count(const bag::value_type &target) const {
    size_type counter = 0;
    for (size_type i = 0; i < used; i++) {
        if (data[i] == target)
            counter++;
    }
    return counter;
}

void bag::printBag() const {
    for (int i = 0; i < used; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}


bag operator+(const bag &b1, const bag &b2) {
    bag result;
    result += b1;
    result += b2;
    return result;
}
