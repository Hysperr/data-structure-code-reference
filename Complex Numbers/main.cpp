#include <iostream>
#include "complex_number.h"

using namespace std;

int main() {

    complex_number c1 = complex_number(10, -5);
    complex_number c2 = complex_number(1, 1);

    cout << "First complex number...\n";
    cout << c1 << endl << endl;

    cout << "Second complex number...\n";
    cout << c2 << endl << endl;

    cout << "Adding complex numbers...\n";
    cout << c1.add(c2) << endl << endl;

    cout << "Subtracting complex numbers...\n";
    cout << c1.subtract(c2) << endl << endl;

    cout << "Multiplying complex numbers...\n";
    cout << c1.multiply(c2) << endl << endl;

    cout << "Dividing complex numbers...\n";
    cout << c1.divide(c2) << endl << endl;

    return 0;
}
