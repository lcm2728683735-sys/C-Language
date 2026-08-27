#include "Fraction.h"
#include <iostream>
#include <numeric>

Fraction& Fraction::AutoSimplify()
{
    Fraction temp;
    temp.Denominator = this->Denominator;
    temp.Numerator = this->Numerator;
    Numerator = Numerator / std::gcd(temp.Numerator, temp.Denominator);
    Denominator = Denominator / std::gcd(temp.Numerator, temp.Denominator);
    return *this;
}

void Fraction::show()
{
    std::cout << Numerator << '/' << Denominator << std::endl;
}

Fraction Fraction::operator+(const Fraction a)
{
    Fraction result;
    if (this->Denominator == a.Denominator)
    {
        result.Numerator = this->Numerator + a.Numerator;
        result.Denominator = this->Denominator;
    }
    else
    {
        result.Numerator = (this->Numerator * a.Denominator) + (this->Denominator * a.Numerator);
        result.Denominator = this->Denominator * a.Denominator;
    }
    return result;
}

Fraction Fraction::operator-(const Fraction a)
{
    Fraction result;
    if (this->Denominator == a.Denominator)
    {
        result.Numerator = this->Numerator - a.Numerator;
        result.Denominator = this->Denominator;
    }
    else
    {
        result.Numerator = (this->Numerator * a.Denominator) - (this->Denominator * a.Numerator);
        result.Denominator = this->Denominator * a.Denominator;
    }
    return result;
}

Fraction Fraction::operator*(const Fraction a)
{
    Fraction result;
    result.Numerator = this->Numerator * a.Numerator;
    result.Denominator = this->Denominator * a.Denominator;
    return result;
}

Fraction Fraction::operator/(const Fraction a)
{
    Fraction result;
    result.Numerator = this->Numerator * a.Denominator;
    result.Denominator = this->Denominator * a.Numerator;
    return result;
}

Fraction& Fraction::operator+=(const Fraction a)
{
    *this = *this + a;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction a)
{
    *this = *this - a;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction a)
{
    *this = *this * a;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction a)
{
    *this = *this / a;
    return *this;
}

bool Fraction::operator<(const Fraction a)
{
    int temp1;
    int temp2;
    temp1 = this->Numerator * a.Denominator;
    temp2 = a.Numerator * this->Denominator;
    return temp1 < temp2;
}

bool Fraction::operator>(const Fraction a)
{
    int temp1;
    int temp2;
    temp1 = this->Numerator * a.Denominator;
    temp2 = a.Numerator * this->Denominator;
    return temp1 > temp2;
}

bool Fraction::operator==(const Fraction a)
{
    int temp1;
    int temp2;
    temp1 = this->Numerator * a.Denominator;
    temp2 = a.Numerator * this->Denominator;
    return temp1 == temp2;
}

Fraction::~Fraction() = default;

