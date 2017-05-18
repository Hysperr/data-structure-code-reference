/**
 CLASS implemented: bag
 INVARIANT for the bag class:
   1. The number of items in the bag is in the member variable used;
   2. The actual items of the bag are stored in a partially filled array.
      The array is a dynamic array, pointed to by the member variable data;
   3. The size of the dynamic array is in the member variable capacity.
*/

#include "bag.h"
#include <algorithm>

bag::bag(bag::size_type initial_capacity) {
    data = new value_type[DEFAULT_CAPACITY];
    capacity = initial_capacity;
    used = 0;
}

bag::bag(const bag &source) {
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
}

bag::~bag() {
    delete[] data;
}

void bag::reserve(bag::size_type new_capacity) {
    value_type *larger_array;
    if (new_capacity == capacity) return;           // the allocated memory is already the right size
    if (new_capacity < used) new_capacity = used;   // can't allocate less than we are using
    larger_array = new value_type[new_capacity];
    std::copy(data, data + used, larger_array);
    delete[] data;
    data = larger_array;
    capacity = new_capacity;
    // used remains unchanged
}

bool bag::erase_one(const bag::value_type &target) {
    size_type index = 0;
    while (index < used && data[index] != target) index++;
    if (index == used) return false;   // target not in bag

    // if reach here, target in bag at data[index]
    // copy last item into data[index], reduce used by 1

    data[index] = data[used - 1];
    used--;
    return true;
}

typename bag::size_type bag::erase(const bag::value_type &target) {
    size_type index = 0;
    size_type num_removed = 0;

    while (index < used) {
        if (data[index] == target) {
            data[index] = data[used - 1];   // last elem in bag
            used--;
            num_removed++;
        }
        else index++;

    }
    return num_removed;
}

void bag::insert(const bag::value_type &entry) {
    if (used == capacity) reserve(used + 1);
    data[used] = entry;
    used++;
}
























