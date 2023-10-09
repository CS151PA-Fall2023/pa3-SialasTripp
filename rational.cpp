/**
 * @file rational.cpp
 * @author Sialas Tripp
 * @brief function definition class
 * @date 2023-10-03
 * 
 */
#include "rational.h"

/**
 * @brief defualt constructor
 * 
 */
Rational::Rational()
{
    numer = 1;
    denom = 1;
}

/**
 * @brief Construct a new Rational:: Rational object
 * 
 * @param n numerator
 * @param d denominator
 */
Rational::Rational(int n, int d)
{
    numer = n;
    if(d == 0)
    {
        std::cout << "Error: denominator cannot be zero.\n";
        exit(1);
    }
    else
    {
        denom = d;
    }
}

/**
 * @brief Construct a new Rational:: Rational object
 * 
 * @param str char array that contain fractions
 */
Rational::Rational (const char *str)
{
    std::istringstream istr(str);
    char delim;
    istr>>numer>>delim>>denom;
    reduce();
}

/**
 * @brief Copy Constructor
 * 
 * @param copy copy of rational
 */
Rational::Rational(const Rational &copy)
{
    this->numer=copy.numer;
    this->denom=copy.denom;
}

/**
 * @brief Destroy the Rational:: Rational object
 * 
 */
Rational::~Rational()
{

}

/**
 * @brief converts to double
 * 
 * @return double the converted number
 */
Rational::operator double() const
{

    return static_cast<double>(numer) / denom;

}

/**
 * @brief function that is able to add two rationals
 * 
 * @param r instance of a rational
 * @return Rational new post addition rational
 */
Rational Rational::operator+(const Rational& r) const
{
    int denominator = denom * r.denom;
    int numerator = (numer * r.denom) + (r.numer * denom);
    Rational add(numerator, denominator);
    add.reduce();
    return add;
}

/**
 * @brief function that is able to subtract two rationals
 * 
 * @param r instance of a rational
 * @return Rational new post subtraction rational
 */
Rational Rational::operator-(const Rational& r) const
{
    int denominator = denom * r.denom;
    int numerator = (numer * r.denom) - (r.numer * denom);
    Rational sub(numerator, denominator);
    sub.reduce();
    return sub;
}

/**
 * @brief function that is able to multiply two rationals
 * 
 * @param r instance of a rational
 * @return Rational new post multiplication rational
 */
Rational Rational::operator*(const Rational& r) const
{
    Rational multiply(numer * r.numer, denom * r.denom);
    multiply.reduce();
    return multiply;
}

/**
 * @brief function that is able to divide two rationals
 * 
 * @param r instance of a rational 
 * @return Rational new post division rational
 */
Rational Rational::operator/(const Rational& r) const
{
    Rational divide(numer * r.denom, denom * r.numer);
    divide.reduce();
    return divide;
}

/**
 * @brief function that is able to reduce a fraction
 * 
 */
void Rational::reduce()
{
    int num = gcd(numer, denom);
    numer /= num;
    denom /= num;
}

/**
 * @brief finds the greatest common denominator
 * 
 * @param n numerator
 * @param d denominator
 * @return int greatest common denominator
 */
int Rational::gcd(int n, int d)
{
    if(d == 0)
    {
        return n;
    }
    return gcd(d, n % d);
}