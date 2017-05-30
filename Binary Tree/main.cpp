#include <iostream>
#include "binary_tree.h"
#include "build_tree.h"

int main() {

    /*
     * 7 binary tree samples are provided in main.
     * Run all or select which ones you wish to see.
     */

    binary_tree<int> *a = sample1();
    print(a, 0);
    std::cout << "\nSample 1\n---------------------------------------------------------------------------------\n";


    binary_tree<int> *b = sample2();
    print(b, 0);
    std::cout << "\nSample 2\n---------------------------------------------------------------------------------\n";


    binary_tree<double> *c = sample3();
    print(c, 0);
    std::cout << "\nSample 3\n---------------------------------------------------------------------------------\n";


    binary_tree<double> *d = sample4();
    print(d, 0);
    std::cout << "\nSample 4\n---------------------------------------------------------------------------------\n";


    binary_tree<std::string> *e = sample5();
    print(e, 0);
    std::cout << "\nSample 5\n---------------------------------------------------------------------------------\n";


    binary_tree<double> *f = sample_bal1();
    print(f, 0);
    std::cout << "\nSample Ball 1\n---------------------------------------------------------------------------------\n";


    binary_tree<double> *g = sample_bal2();
    print(g, 0);
    std::cout << "\nSample Ball 2\n---------------------------------------------------------------------------------\n";


    return 0;
}
