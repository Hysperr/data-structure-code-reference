
/**
PROVIDES: A template class for a node in a binary tree and functions for
manipulating binary trees. The template parameter is the type of data in
each node.

TYPEDEF for the binary_tree<T> template class:
Each node of the tree contains a piece of data and pointers to its
children. The type of the data (binary_tree<T>::value_type) is
the T type from the template parameter. The type may be any of the C++
built-in types (int, char, etc.), or a class with a default constructor,
and an assignment operator.

CONSTRUCTOR for the binary_tree<T> class:
binary_tree(
const T& init_data = T( ),
binary_tree<T> *init_left = NULL,
binary_tree<T> *init_right = NULL
)
Postcondition: The new node has its data equal to init_data,
and it's child pointers equal to init_left and init_right.

MEMBER FUNCTIONS for the binary_tree<T> class:
const T& data( ) const      <----- const version
and
T& data( )                  <----- non-const version
Postcondition: The return value is a reference to the data from
this binary_tree.

const binary_tree *left( ) const  <----- const version
and
binary_tree *left( )              <----- non-const version
and
const binary_tree *right( ) const <----- const version
and
binary_tree *right( )             <----- non-const version
Postcondition: The return value is a pointer to the left or right child
(which will be NULL if there is no child).

void set_data(const T& new_data)
Postcondition: The binary_tree now contains the specified new data.

void set_left(binary_tree *new_link)
and
void set_right(binary_tree *new_link)
Postcondition: The binary_tree now contains the specified new link
to a child.

bool is_leaf( )
Postcondition: The return value is true if the node is a leaf;
otherwise the return value is false.

NON-MEMBER FUNCTIONS to manipulate binary tree nodes:
template <typename Process, typename BinTree>
void inorder(Process f, BinTree *node_ptr)
Precondition: node_ptr is a pointer to a node in a binary tree (or
node_ptr may be NULL to indicate the empty tree).
Postcondition: If node_ptr is non-NULL, then the function f has been
applied to the contents of *node_ptr and all of its descendants, using
an in-order traversal.
Note: BinTree may be a binary_tree or a const binary tree node.
Process is the type of a function f that may be called with a single
T argument (using the T type from the node).

template <typename Process, typename BinTree>
void postorder(Process f, BinTree *node_ptr)
Same as the in-order function, except with a post-order traversal.

template <typename Process, typename BinTree>
void preorder(Process f, BinTree *node_ptr)
Same as the in-order function, except with a pre-order traversal.

template <typename T, typename SizeType>
void print(const binary_tree<T> *node_ptr, SizeType depth)
Precondition: node_ptr is a pointer to a node in a binary tree (or
node_ptr may be NULL to indicate the empty tree). If the pointer is
not NULL, then depth is the depth of the node pointed to by node_ptr.
Postcondition: If node_ptr is non-NULL, then the contents of *node_ptr
and all its descendants have been written to cout with the << operator,
using a backward in-order traversal. Each node is indented four times
its depth.

template <typename T>
void tree_clear(binary_tree<T> *&root_ptr)
Precondition: root_ptr is the root pointer of a binary tree (which may
be NULL for the empty tree).
Postcondition: All nodes at the root or below have been returned to the
heap, and root_ptr has been set to NULL.

template <typename T>
binary_tree<T> *tree_copy(const binary_tree<T> *root_ptr)
Precondition: root_ptr is the root pointer of a binary tree (which may
be NULL for the empty tree).
Postcondition: A copy of the binary tree has been made, and the return
value is a pointer to the root of this copy.

template <typename T>
size_t tree_size(const binary_tree<T> *node_ptr)
Precondition: node_ptr is a pointer to a node in a binary tree (or
node_ptr may be NULL to indicate the empty tree).
Postcondition: The return value is the number of nodes in the tree.
*/

#ifndef BINARY_TREE_BINARY_TREE_H
#define BINARY_TREE_BINARY_TREE_H

#include <cstddef>
#include <cstring>

template<typename T>
class binary_tree {

public:

    // CONSTRUCTOR
    binary_tree(binary_tree *init_left = nullptr, binary_tree *init_right = nullptr, const T &entry = T());

    // MEMBER FUNCTIONS
    const T &data() const { return data_field; }

    binary_tree *left() const { return left_field; }

    binary_tree *right() const { return right_field; }

    void set_data(const T &entry) { data_field = entry; }

    void set_left(binary_tree *new_left) { left_field = new_left; }

    void set_right(binary_tree *new_right) { right_field = new_right; }

    bool is_leaf() const { return (left_field == nullptr) && (right_field == nullptr); }


private:

    T data_field;
    binary_tree *left_field;
    binary_tree *right_field;

};


// NON-MEMBER FUNCTIONS to manipulate binary_tree<T>
template<typename Process, typename BinTree>
void inorder(Process f, BinTree *node_ptr);

template<typename Process, typename BinTree>
void preorder(Process f, BinTree *node_ptr);

template<typename Process, typename BinTree>
void postorder(Process f, BinTree *node_ptr);

template<typename T, typename SizeType>
void print(binary_tree<T> *node_ptr, SizeType depth);

template<typename T>
void tree_clear(binary_tree<T> *&root_ptr);

template<typename T>
std::size_t tree_size(const binary_tree<T> *node_ptr);

template<typename T>
binary_tree<T> *tree_copy(const binary_tree<T> *root_ptr);


#include "binary_tree.template"


#endif //BINARY_TREE_BINARY_TREE_H
