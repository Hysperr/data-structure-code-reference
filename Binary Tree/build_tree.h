#ifndef BUILD_TREE_H
#define BUILD_TREE_H

#include "binary_tree.h"
#include <cassert>

/**
 *  This is a helper function
 */
template<typename T>
binary_tree<T> *build_from_node_lists(
        const T preorder[],
        const T inorder[],
        size_t pre_start,
        size_t pre_end,
        size_t in_start,
        size_t in_end)
{

    if (pre_start >= pre_end) return nullptr;
    const T rootval = preorder[pre_start];
    size_t r = in_start;
    while (r < in_end && inorder[r] != rootval) r++;

    assert(r < in_end);
    size_t lsize = r - in_start;

    binary_tree<T> *left = build_from_node_lists(
            preorder,
            inorder,
            pre_start + 1,
            pre_start + lsize + 1,
            in_start, r);

    binary_tree<T> *right = build_from_node_lists(
            preorder,
            inorder,
            pre_start + lsize + 1,
            pre_end, r + 1,
            in_end);

    return new binary_tree<T>(left, right, rootval);
}

/**
 * Given the preorder and inorder list of binary tree nodes,
 * recreate the binary tree.
 * precondition: preorder and inorder are both of size 'size'.
 */
template<typename T>
binary_tree<T> *build_from_node_lists(const T preorder[], const T inorder[], size_t size) {
    return build_from_node_lists(preorder, inorder, 0, size, 0, size);
}

/*
 * The following functions each return a sample binary tree that you can
 * use to try out various functions you have created.
*/

binary_tree<int> *sample1();

binary_tree<int> *sample2();

binary_tree<double> *sample3();

binary_tree<double> *sample4();

binary_tree<std::string> *sample5();

binary_tree<double> *sample_bal1();

binary_tree<double> *sample_bal2();

#endif // BUILD_TREE_H
