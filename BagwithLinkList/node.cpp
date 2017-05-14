/** FILE: node.cpp
 IMPLEMENTS: The functions of the node class and the
 linked list toolkit (see node.h for documentation).
 INVARIANT for the node class:
   The data of a node is stored in data_field, and the link in link_field.*/

#include "node.h"
#include <cassert>    // Provides assert

using namespace std;

namespace main_savitch_5 {
    size_t list_length(const node *head_ptr) {
        const node *cursor;
        size_t answer = 0;

        for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
            ++answer;

        return answer;
    }

    void list_head_insert(node *&old_head_ptr, const node::value_type &entry) {
        old_head_ptr = new node(entry, old_head_ptr);
    }

    void list_insert(node *previous_ptr, const node::value_type &entry) {
        node *insert_ptr;
        insert_ptr = new node(entry, previous_ptr->link());
        previous_ptr->set_link(insert_ptr);
    }

    node *list_search(node *head_ptr, const node::value_type &target) {
        node *cursor;
        for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
            if (target == cursor->data())
                return cursor;
        return nullptr;
    }

    const node *list_search(const node *head_ptr, const node::value_type &target) {
        const node *cursor;
        for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
            if (target == cursor->data())
                return cursor;
        return nullptr;
    }

    node *list_locate(node *head_ptr, size_t position) {
        assert (position > 0);
        node *cursor = head_ptr;
        for (size_t i= 1; (i < position) && (cursor != nullptr); i++)
            cursor = cursor->link();
        return cursor;
    }

    const node *list_locate(const node *head_ptr, size_t position) {
        assert (0 < position);
        const node *cursor = head_ptr;
        for (size_t  i = 1; (i < position) && (cursor != nullptr); i++)
            cursor = cursor->link();
        return cursor;
    }

    void list_head_remove(node *&head_ptr) {
        node *remove_ptr = head_ptr;
        head_ptr = head_ptr->link();
        delete remove_ptr;
    }

    void list_remove(node *previous_ptr) {
        node *remove_ptr;
        remove_ptr = previous_ptr->link();
        previous_ptr->set_link(remove_ptr->link());
        delete remove_ptr;
    }

    void list_clear(node *&head_ptr) {
        while (head_ptr != nullptr)
            list_head_remove(head_ptr);
    }

    void list_copy(const node *source_ptr, node *&head_ptr, node *&tail_ptr) {
        head_ptr = nullptr;
        tail_ptr = nullptr;

        // Handle the case of the empty list.
        if (source_ptr == nullptr)
            return;

        // Make the head node for the newly created list, and put data in it.
        list_head_insert(head_ptr, source_ptr->data());
        tail_ptr = head_ptr;

        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        source_ptr = source_ptr->link();
        while (source_ptr != nullptr) {
            list_insert(tail_ptr, source_ptr->data());
            tail_ptr = tail_ptr->link();
            source_ptr = source_ptr->link();
        }
    }

}
