#ifndef __FRACTION_H_
#define __FRACTION_H_
#include <iostream>
#include <numeric>
class Fraction
{    
private:
    int Denominator;//分母
    int Numerator ;//分子
public:
    Fraction():Denominator(0),Numerator(0){};
    Fraction(int Numerator,int Denominator):Numerator(Numerator),Denominator(Denominator){};
    Fraction AutoSimplify(Fraction temp);
    void show();
    Fraction operator+(const Fraction a);
    Fraction operator-(const Fraction a);
    // Fraction operator*(const Fraction a);
    // Fraction operator/(const Fraction a);
    // Fraction operator+=(const Fraction a);
    // Fraction operator-=(const Fraction a);
    // Fraction operator*=(const Fraction a);
    // Fraction operator/=(const Fraction a);
    // bool Fraction operator<(const Fraction a);
    // bool Fraction operator>(const Fraction a);
    // bool Fraction operator==(const Fraction a);


};

#endif

