
#ifndef NODE_H
#define NODE_H


/**
FILE: node.h (part of the namespace main_savitch_6B)
PROVIDES: A template class for a node in a linked list, and list manipulation
functions. The template parameter is the type of the data in each node.
This file also defines a template class: node_iterator<Item>.
The node_iterator is a forward iterators with two constructors:
(1) A constructor (with a node<Item>* parameter) that attaches the iterator
to the specified node in a linked list, and (2) a default constructor that
creates a special iterator that marks the position that is beyond the end of a
linked list. There is also a const_node_iterator for use with
const node<Item>* .

TYPEDEF for the node<Item> template class:
Each node of the list contains a piece of data and a pointer to the
next node. The type of the data (node<Item>::value_type) is the Item type
from the template parameter. The type may be any of the built-in C++ classes
(int, char, ...) or a class with a default constructor, an assignment
operator, and a test for equality (x == y).
NOTE:
Many compilers require the use of the new keyword typename before using
the expression node<Item>::value_type. Otherwise
the compiler doesn't have enough information to realize that it is the
name of a data type.

CONSTRUCTOR for the node<Item> class:
node(
const Item& init_data = Item(),
node* init_link = NULL
)
Postcondition: The node contains the specified data and link.
NOTE: The default value for the init_data is obtained from the default
constructor of the Item. In the ANSI/ISO standard, this notation
is also allowed for the built-in types, providing a default value of
zero. The init_link has a default value of NULL.

NOTE about two versions of some functions:
The data function returns a reference to the data field of a node and
the link function returns a copy of the link field of a node.
Each of these functions comes in two versions: a const version and a
non-const version. If the function is activated by a const node, then the
compiler chooses the const version (and the return value is const).
If the function is activated by a non-const node, then the compiler chooses
the non-const version (and the return value will be non-const).
EXAMPLES:
const node<int> *c;
c->link( ) activates the const version of link returning const node*
c->data( ) activates the const version of data returning const Item&
c->data( ) = 42; ... is forbidden
node<int> *p;
p->link( ) activates the non-const version of link returning node*
p->data( ) activates the non-const version of data returning Item&
p->data( ) = 42; ... actually changes the data in p's node

MEMBER FUNCTIONS for the node<Item> class:
const Item& data( ) const <----- const version
and
Item& data( ) <----------------- non-const version
See the note (above) about the const version and non-const versions:
Postcondition: The return value is a reference to the  data from this node.

const node* link( ) const <----- const version
and
node* link( ) <----------------- non-const version
See the note (above) about the const version and non-const versions:
Postcondition: The return value is the link from this node.

void set_data(const Item& new_data)
Postcondition: The node now contains the specified new data.

void set_link(node* new_link)
Postcondition: The node now contains the specified new link.

FUNCTIONS in the linked list toolkit:
template <class Item>
void list_clear(node<Item>*& head_ptr)
Precondition: head_ptr is the head pointer of a linked list.
Postcondition: All nodes of the list have been returned to the heap,
and the head_ptr is now NULL.

template <class Item>
void list_copy
(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr)
Precondition: source_ptr is the head pointer of a linked list.
Postcondition: head_ptr and tail_ptr are the head and tail pointers for
a new list that contains the same items as the list pointed to by
source_ptr. The original list is unaltered.

template <class Item>
void list_head_insert(node<Item>*& head_ptr, const Item& entry)
Precondition: head_ptr is the head pointer of a linked list.
Postcondition: A new node containing the given entry has been added at
the head of the linked list; head_ptr now points to the head of the new,
longer linked list.

template <class Item>
void list_head_remove(node<Item>*& head_ptr)
Precondition: head_ptr is the head pointer of a linked list, with at
least one node.
Postcondition: The head node has been removed and returned to the heap;
head_ptr is now the head pointer of the new, shorter linked list.

template <class Item>
void list_insert(node<Item>* previous_ptr, const Item& entry)
Precondition: previous_ptr points to a node in a linked list.
Postcondition: A new node containing the given entry has been added
after the node that previous_ptr points to.

template <class Item>
size_t list_length(const node<Item>* head_ptr)
Precondition: head_ptr is the head pointer of a linked list.
Postcondition: The value returned is the number of nodes in the linked
list.

template <class NodePtr, class SizeType>
NodePtr list_locate(NodePtr head_ptr, SizeType position)
The NodePtr may be either node<Item>* or const node<Item>*
Precondition: head_ptr is the head pointer of a linked list, and
position > 0.
Postcondition: The return value is a pointer that points to the node at
the specified position in the list. (The head node is position 1, the
next node is position 2, and so on). If there is no such position, then
the null pointer is returned.

template <class Item>
void list_remove(node<Item>* previous_ptr)
Precondition: previous_ptr points to a node in a linked list, and this
is not the tail node of the list.
Postcondition: The node after previous_ptr has been removed from the
linked list.

template <class NodePtr, class Item>
NodePtr list_search
(NodePtr head_ptr, const Item& target)
The NodePtr may be either node<Item>* or const node<Item>*
Precondition: head_ptr is the head pointer of a linked list.
Postcondition: The return value is a pointer that points to the first
node containing the specified target in its data member. If there is no
such node, the null pointer is returned.

DYNAMIC MEMORY usage by the toolkit:
If there is insufficient dynamic memory, then the following functions throw
bad_alloc: the constructor, list_head_insert, list_insert, list_copy.
*/


#include <iterator>  // Provides iterator and forward_iterator_tag


template<typename Item>
class node {
public:
    // TYPEDEF
    typedef Item value_type;

    // CONSTRUCTOR
    node(const Item &init_data = Item(), node *init_link = nullptr) {
        data_field = init_data;
        link_field = init_link;
    }

    // MODIFICATION MEMBER FUNCTIONS
    Item &data() { return data_field; }

    node *link() { return link_field; }

    void set_data(const Item &new_data) { data_field = new_data; }

    void set_link(node *new_link) { link_field = new_link; }

    // CONST MEMBER FUNCTIONS
    const Item &data() const { return data_field; }

    const node *link() const { return link_field; }

private:
    Item data_field;
    node *link_field;
};

// FUNCTIONS to manipulate a linked list:
template<typename Item>
void list_clear(node<Item> *&head_ptr);

template<typename Item>
void list_copy(const node<Item> *source_ptr, node<Item> *&head_ptr, node<Item> *&tail_ptr);

template<typename Item>
void list_head_insert(node<Item> *&head_ptr, const Item &entry);

template<typename Item>
void list_head_remove(node<Item> *&head_ptr);

template<typename Item>
void list_insert(node<Item> *previous_ptr, const Item &entry);

template<typename Item>
std::size_t list_length(const node<Item> *head_ptr);

template<class NodePtr, class SizeType>
NodePtr list_locate(NodePtr head_ptr, SizeType position);

template<typename Item>
void list_remove(node<Item> *previous_ptr);

template<class NodePtr, class Item>
NodePtr list_search(NodePtr head_ptr, const Item &target);

/**
FORWARD ITERATORS to step through the nodes of a linked list
A node_iterator can change the underlying linked list through
the*operator, so it may not be used with a const node. The
node_const_iterator cannot change the underlying linked list
through the * operator, so it may be used with a const node.
WARNING:
This classes use std::iterator as its base class;
Older compilers that do not support the std::iterator class can
delete everything after the word iterator in the second line:
*/

template<typename Item>
class node_iterator : public std::iterator<std::forward_iterator_tag, Item> {
public:
    // CONSTRUCTOR
    node_iterator(node<Item> *initial = nullptr) { current = initial; }

    Item &operator*() const { return current->data(); }

    // Prefix ++
    node_iterator &operator++() {
        current = current->link();
        return *this;
    }

    // Postfix ++
    node_iterator operator++(int) {
        node_iterator original(current);
        current = current->link();
        return original;
    }

    bool operator==(const node_iterator other) const { return current == other.current; }

    bool operator!=(const node_iterator other) const { return current != other.current; }

private:
    node<Item> *current;
};

template<typename Item>
class const_node_iterator : public std::iterator<std::forward_iterator_tag, const Item> {
public:
    // CONSTRUCTOR
    const_node_iterator(const node<Item> *initial = nullptr) { current = initial; }

    const Item &operator*() const { return current->data(); }

    // Prefix ++
    const_node_iterator &operator++() {
        current = current->link();
        return *this;
    }

    // Postfix ++
    const_node_iterator operator++(int) {
        const_node_iterator original(current);
        current = current->link();
        return original;
    }

    bool operator==(const const_node_iterator other) const { return current == other.current; }

    bool operator!=(const const_node_iterator other) const { return current != other.current; }

private:
    const node<Item> *current;
};


#include "node.template"


#endif // NODE_H
