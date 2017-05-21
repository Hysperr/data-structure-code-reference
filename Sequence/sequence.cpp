

#include "sequence.h"
#include <cassert>
#include <iostream>

sequence::sequence() {
    used = 0;
    current_index = 0;
}

void sequence::remove_current() {
    size_type i = current_index;
    while (i < used) {
        data[i] = data[i + 1];
        i++;
    }
    used--;
}

void sequence::insert(const value_type &entry) {
    assert(used < CAPACITY);
    if (!is_item()) {
        for (size_type i = used; i > 0; i--) {
            data[i] = data[i - 1];
        }
        current_index = 0;
        data[current_index] = entry;
        used++;
        return;
    }
    else if (used == 0) {
        current_index = 0;
        data[current_index] = entry;
        used++;
        return;
    }
    else if (current_index == 0 || !is_item()) {
        for (size_type i = used; i > current_index; i--) {
            data[i] = data[i - 1];
        }
        data[0] = entry;
        used++;
        return;
    }
    else {
        for (size_type i = used; i > current_index; i--) {
            data[i] = data[i - 1];
            // creates empty spot to place entry in current index
            // since values have been shifted to the right
        }
        data[current_index] = entry;
        used++;
    }
}

void sequence::attach(const value_type &entry) {
    assert(used < CAPACITY);
    if (!is_item()) {
        data[current_index] = entry;
        used++;
        return;
    }
    else if (used == 0) {
        current_index = 0;
        data[current_index] = entry;
        used++;
        return;
    }
    for (size_type i = used; i > current_index + 1; i--) {
        data[i] = data[i - 1];
    }
    data[current_index + 1] = entry;
    current_index += 1;
    used++;
}

void sequence::print_sequence() const {
    for (size_type i = 0; i < used; i++) {
        std::cout << data[i]  << ' ';
    }
    std::cout << '\n';
}
