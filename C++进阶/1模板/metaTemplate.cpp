#include <iostream>
#include <string>

template<int N>
struct Case { };

template<>
struct Case<1>
{
    static std::string value()
    {
        return "1";
    }
};

template<>
struct Case<2>
{
    static std::string value()
    {
        return "2";
    }
};

template <int start, int end>
struct For
{
    static void value()
    {
        std::cout << start << std::endl;
        For<start + 1,end >::value();
    }
};
template <int End>
struct For<End,End> 
{
    static void value()
    {
    }
};


template <int N>
struct data
{
    enum
    {
        res = data<N - 1>::res + data<N - 2>::res
    };
};

template <>
struct data<1>
{
    enum
    {
        res = 1
    };
};

template <>
struct data<2>
{
    enum
    {
        res = 2
    };
};

int main ()
{
    std::cout << data<7>::res << std::endl;
}