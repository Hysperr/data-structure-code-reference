
#include "set.h"
#include <algorithm>
#include <cassert>
#include <iostream>

set::set(size_type initial_capacity) {
    data = new value_type[DEFAULT_CAPACITY];
    capacity = initial_capacity;
    used = 0;
}

set::set(const set &source) {
    data = new value_type[source.capacity];
    std::copy(source.data, source.data + source.used, data);
    capacity = source.capacity;
    used = source.used;
}

set::~set() {
    delete[] data;
}

void set::reserve(size_type new_capacity) {
    if (new_capacity == capacity) return;           // the allocated memory is already the right size
    if (new_capacity < used) new_capacity = used;   // can't allocate less than we are using
    value_type *larger_array = new value_type[new_capacity];
    std::copy(data, data + used, larger_array);
    delete[] data;
    data = larger_array;
    capacity = new_capacity;
    // used remains unchanged
}

bool set::erase_one(const set::value_type &target) {
    size_type index = 0;
    while (index < used && index != target) index++;
    if (index == used) return false;    // target not in bag

    // if reach here, target in set at data[index]
    // copy last item into data[index], reduce used by 1

    data[index] = data[used - 1];
    used--;
    return true;
}

typename set::size_type set::erase(const set::value_type &target) {
    size_type index = 0;
    size_type num_removed = 0;

    while (index < used) {
        if (data[index] == target) {
            data[index] = data[used - 1];   // last elem in set
            used--;
            num_removed++;
        }
        else index++;
    }
    return num_removed;
}

void set::insert(const set::value_type &entry) {
    assert(!contains(entry));
    if (used == capacity) {
        reserve(used + 1);
        data[used] = entry;
        used++;
        return;
    }
    std::cout << "contains duplicate, item not inserted.\n";
}

bool set::contains(const set::value_type &target) const {
    size_type index = 0;
    while (index < used && index != target) index++;
    return index != used;   // we must be on target if true
}

void set::operator+=(const set &addend) {

}

void set::operator-=(const set &addend) {

}













