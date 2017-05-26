
#include "set.h"
#include <algorithm>
#include <iostream>

set::set(set::size_type initial_capacity) {
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

void set::reserve(set::size_type new_capacity) {
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
    while (index < used && data[index] != target) index++;
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

void set::insert(const set::value_type &entry, bool message) {
    if (contains(entry)) {
        if (message) std::cout << "contains duplicate, item not inserted.\n";
        return;
    }
    if (used == capacity) reserve(used + 1);
    data[used] = entry;
    used++;
}

bool set::contains(const set::value_type &target) const {
    size_type index = 0;
    while (index < used && data[index] != target) index++;
    return index != used;   // we must be on target if true
}

void set::operator+=(const set &addend) {
    if (used + addend.used > capacity) reserve(used + addend.used);
    size_type index = 0;
    while (++index < addend.used) {     // prefix: use then increment
        insert(addend.data[index], false);
    }
}

void set::operator=(const set &source) {
    if (this == &source) return;
    if (capacity != source.capacity) {  // allocate an new array with source's capacity
        value_type *new_array = new value_type[source.capacity];
        capacity = source.capacity;
        delete[] data;
        data = new_array;
    }
    used = source.used;
    std::copy(source.data, source.data + source.used, data);
}

typename set::value_type set::operator[](const set::size_type x) {
    return data[x];
}

void set::make_union(const set &other_set) {
    if (used + other_set.used > capacity) reserve(used + other_set.used);
    size_type index = 0;
    while (index < other_set.used) {
        insert(other_set.data[index], false);
        index++;
    }
}

void set::make_intersection(const set &other_set) {
    value_type *array = new value_type[capacity + other_set.capacity];
    capacity = capacity += other_set.capacity;
    size_type tmp_used = 0;

    // loop through largest set, prevents out of bounds
    if (other_set.used > used) {
        size_type index = 0;
        size_type i = 0;
        while (index < other_set.used) {
            if (this->contains(other_set.data[index])) {
                array[i] = other_set.data[index];
                tmp_used++;
                i++;
            }
            index++;
        }
    }
    else {
        size_type index = 0;
        size_type i = 0;
        while (index < used) {
            if (other_set.contains(data[index])) {
                array[i] = data[index];
                tmp_used++;
                i++;
            }
            index++;
        }
    }
    delete[] data;      // return old memory pointed to by data to heap
    data = array;       // point data to newly allocated array memory
    used = tmp_used;    // update used
}

void set::print_set() const {
    for (size_type i = 0; i < used; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}
