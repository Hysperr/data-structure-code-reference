#include <iostream>
#include <iomanip>
#include "bag.h"

using namespace std;

int main() {

    bag b;
    cout << "Bag B created..." << endl;

    // fill bag to capacity, count how many times numbers 0 - 20 appear
    srand((unsigned int) time(NULL));
    for (int i = 0; i < 30000; i++) {
        b.insert(rand() % 21);              // numbers 0 - 21 (exclusive)
    }
    cout << "Many elements [0-20] inserted into Bag B..." << endl;

    cout << "Quantity of each element in Bag B..." << endl;
    for (int k = 0; k < 21; k++) {
        cout << k << setw(10) << b.count(k) << endl;    // setw sets output width, std::endl flushes output buffer, can be expensive
    }
    cout << b.size() << " elements in Bag B" << endl << endl;


    bag x;
    cout << "Bag X created..." << endl;
    x.insert(20);
    x.insert(14.3);         // make sure typedef of double, else truncated values (14 in this case) if typedef of int
    cout << "Two elements inserted into Bag X" << endl;
    cout << "Bag X:" << endl;
    x.printBag();
    cout << "Bag X size: " << x.size() << endl << endl;


    bag bag1;
    bag bag2;
    cout << "Bag 1 and Bag 2 created..." << endl;

    int tmp1[] = {0, 1, 2, 3, 4};
    int tmp2[] = {5, 6, 7, 8, 9};

    // The sizeof operator returns num of bytes in object, divide it by pointer size - gives num elements in object in C/C++ array (array cannot be passed as param because treated as pointer)
    for (int i = 0; i < sizeof(tmp1) / sizeof(tmp1[0]); i++) {
        bag1.insert(tmp1[i]);
    }
    for (auto m : tmp2) bag2.insert(m);

    // In C++ 11 std::array is preferred over raw arrays.
    // Alternatively, to loop through an array, in C++ 11 you can use a range-based for loop for (auto m : tmp1)


    cout << "Bag 1: " << endl;
    bag1.printBag();
    cout << "Bag 2: " << endl;
    bag2.printBag();


    bag1 += bag2;
    cout << "Contents of Bag 2 added to Bag 1" << endl;

    cout << "Bag 1 is now: " << endl;
    bag1.printBag();

    cout << "Bag 2 is still: " << endl;
    bag2.printBag();

    cout << "Erase a single 2 from Bag 1..." << endl;
    bag1.erase_one(2);
    bag1.printBag();

    cout << "Insert a few '5's into Bag 2..." << endl;
    bag2.insert(5);
    bag2.insert(5);
    bag2.insert(5);

    bag2.printBag();

    cout << "Now erase all 5's from Bag 2..." << endl;
    bag2.erase(5);
    bag2.printBag();


    return 0;
}
