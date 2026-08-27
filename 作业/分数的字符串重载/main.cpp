#include "Fraction.h"
#include <iostream>
#include <numeric>
int main()
{
    Fraction a(1,2);
    Fraction b(1,6);
    Fraction c;
    // c = a / b;
    // c.AutoSimplify();
    // c.show();

    // a+=b;
    // a.AutoSimplify();
    // a.show();

    std::cout<<(a<b)<<std::endl;

    return 0;
}





// Fraction Fraction::operator+(const Fraction a)
// {
//     Fraction result;
//     Fraction temp;
//     if(this->Denominator == a.Denominator)
//     {
//     temp.Numerator   = this->Numerator + a.Numerator;
//     temp.Denominator = this->Denominator + a.Denominator;
//     }
//     else
//     {
//         temp.Numerator   = (this->Numerator*a.Denominator)+(this->Denominator*a.Numerator);
//         temp.Denominator = this->Denominator*a.Denominator;
//     }
//     if(std::gcd(temp.Numerator,temp.Denominator)!=1)
//     {
//         result.Numerator = temp.Numerator / std::gcd(temp.Numerator,temp.Denominator);
//         result.Denominator = temp.Denominator / std::gcd(temp.Numerator,temp.Denominator);
//     }
//     else
//     {
//         result.Numerator = temp.Numerator;
//         result.Denominator = temp.Denominator;
//     }
//     return result;
// }