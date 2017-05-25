#include <iostream>
#include "binary_tree.h"
#include "build_tree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    binary_tree<double> *r = sample_bal1();
    print(r, 0);
    return 0;
}
