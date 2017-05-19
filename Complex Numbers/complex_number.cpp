
#include "complex_number.h"
#include <cmath>
#include <sstream>

complex_number::complex_number(double a1, double b1) {
    this->a = a1;
    this->b = b1;
}

std::string complex_number::add(complex_number &c) {
    double p1 = a + c.a;
    double p2 = b + c.b;
    std::stringstream s3;
    if (p2 < 0)
        s3 << p1 << p2 << "i";
    else
        s3 << p1 << "+" << p2 << "i";
    std::string s4 = s3.str();
    return s4;
}

std::string complex_number::subtract(complex_number &c) {
    double p1 = a - c.a;
    double p2 = b - c.b;
    std::stringstream s3;
    if (p2 < 0)
        s3 << p1 << p2 << "i";
    else
        s3 << p1 << "+" << p2 << "i";
    std::string s4 = s3.str();
    return s4;
}

std::string complex_number::multiply(complex_number &c) {
    // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    // c = c.a and d = c.b
    double p1 = (a * c.a) - (b * c.b);
    double p2 = (a * c.b) + (b * c.a);
    std::stringstream s3;
    if (p2 < 0)
        s3 << p1 << p2 << "i";
    else
        s3 << p1 << "+" << p2 << "i";
    std::string s4 = s3.str();
    return s4;
}

std::string complex_number::divide(complex_number &c) {
    // (a + bi) / (c + di) = ((ac + bd)/(c^2 + d^2)) + ((bc - ad)/(c^2 + d^2)i)
    // c = c.a and d = c.b
    double p1 = (a * c.a + b * c.b) / (pow(c.a, 2) + pow(c.b, 2));
    double p2 = (b * c.a - a * c.b) / (pow(c.a, 2) + pow(c.b, 2));
    std::stringstream s3;
    if (p2 < 0)
        s3 << p1 << p2 << "i";
    else
        s3 << p1 << "+" << p2 << "i";
    std::string s4 = s3.str();
    return s4;
}

std::ostream &operator<<(std::ostream &os, const complex_number &c) {
    if (c.b < 0)
        os << c.a << c.b << "i";
    else
        os << c.a << "+" << c.b << "i";
    return os;
}
