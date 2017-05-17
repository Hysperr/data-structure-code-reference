//
// Created by garyk_000 on 1/24/2016.
//
/**
 * PROJECT 19: Page 95
 *
 * Write a class for complex numbers. A complex number has the
 * form (a+bi). Implement appropriate functions for the class.
 * (Addition, subtraction, multiplication, and division)
 *
 */

#ifndef COMPLEX_NUMBERS_COMPLEX_NUMBER_H
#define COMPLEX_NUMBERS_COMPLEX_NUMBER_H

#include <string>

class complex_number {
public:
    complex_number(double a, double b);

    std::string add(complex_number c);

    std::string subtract(complex_number c);

    std::string multiply(complex_number c);

    std::string divide(complex_number c);

    friend std::ostream &operator<<(std::ostream &os, const complex_number &c);

private:
    double a;
    double b;
};


#endif //COMPLEX_NUMBERS_COMPLEX_NUMBER_H
