/**
 * @file rational.h
 * @author Sialas Tripp
 * @brief function header file
 * @date 2023-10-03
 * 
 */
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>

class Rational
{
public:
    Rational();
    Rational(int numer, int denom);
    Rational (const char *str);
    operator double() const;
    Rational operator+(const Rational& r) const;
    Rational operator-(const Rational& r) const;
    Rational operator*(const Rational& r) const;
    Rational operator/(const Rational& r) const;
    Rational(const Rational &copy);
    ~Rational();

    friend std::ostream& operator<<(std::ostream& out, const Rational& rational)
    {
        out << rational.numer << '/' << rational.denom;
        return out;
    }

    void reduce();
private:
    int numer;
    int denom;

    int gcd(int n, int d);
};
#endif // RATIONAL_H