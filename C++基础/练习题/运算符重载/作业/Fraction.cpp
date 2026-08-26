#include "Fraction.h"
#include <iostream>
#include <numeric>

Fraction Fraction::AutoSimplify(Fraction temp)
{
    Fraction result;
    if(std::gcd(temp.Numerator,temp.Denominator)!=1)
    {
        result.Numerator = temp.Numerator / std::gcd(temp.Numerator,temp.Denominator);
        result.Denominator = temp.Denominator / std::gcd(temp.Numerator,temp.Denominator);
    }
    else
    {
        result.Numerator = temp.Numerator;
        result.Denominator = temp.Denominator;
    }
    return result;
}

void Fraction::show()

{
    std::cout << Numerator << '/' << Denominator << std::endl;
} 



Fraction Fraction::operator+(const Fraction a)
{
    Fraction temp;
    if(this->Denominator == a.Denominator)
    {
    temp.Numerator   = this->Numerator + a.Numerator;
    temp.Denominator = this->Denominator + a.Denominator;
    }
    else
    {
        temp.Numerator   = (this->Numerator*a.Denominator)+(this->Denominator*a.Numerator);
        temp.Denominator = this->Denominator*a.Denominator;
    }
    return temp;
}
