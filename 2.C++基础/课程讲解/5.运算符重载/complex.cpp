#include <iostream>

class Complex
{
public:
Complex():real(0),vir(0){}
Complex(int real,int vir):real(real),vir(vir){}
void show()
{
    std::cout<<real<<"+"<<vir<<"i"<<std::endl;
} 

    Complex operator+(const Complex& c)
    {
        Complex result;
        result.real = this->real + c.real;
        result.vir = this->vir +c.vir;
        return result;
    }
    Complex operator-(const Complex& c)
    {
        Complex result;
        result.real = this->real - c.real;
        result.vir = this->vir -c.vir;
        return result;
    }
    //前置++
    Complex& operator++()
    {
        real++;
        vir++;
        return *this;
    }
    //后置++
    Complex operator++(int)
    {
        Complex result = *this;
        real++;
        vir++;
        return result;
    }
    friend std::ostream& operator<<(std::ostream& os,const Complex& c);
    friend std::istream& operator>>(std::istream& is,Complex& c);
private:
    int real;
    int vir;
};

std::ostream& operator<<(std::ostream& os,const Complex& c)
{
    os<<c.real<<"+"<<c.vir<<"i"<<std::endl;
    return os;
}

std::istream& operator>>(std::istream& is,Complex& c)
{
    is>>c.real>>c.vir;
    return is;
}
int main()

{
    // Complex c1(1,2);
    // Complex c2(2,3);
    // c1.show();
    // c2.show();

    // Complex c = c1+c2;
    // Complex c = c1-c2;
    // Complex c = c1++;
    Complex c;
    std::cin>>c;
    std::cout<<c; 
    // c1<<std::cout;

    
    return 0;
}