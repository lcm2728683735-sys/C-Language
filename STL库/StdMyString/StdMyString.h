#ifndef __STDMYSTRING_H_
#define __STDMYSTRING_H_
#include <cstring>
#include <iostream>


class MyStringList; 
class StdMyString
{
public:
    StdMyString();
    StdMyString(const char* str);
    StdMyString(const StdMyString& str);
    ~StdMyString();
    StdMyString& operator=(const StdMyString & str);
    StdMyString& operator+=(const StdMyString &str);
    StdMyString& operator+=(const char &str);
    StdMyString operator+(const StdMyString &str);
    StdMyString& operator-=(const StdMyString &str);
    StdMyString operator-(const StdMyString &str);
    char& operator[](int index);
    bool operator ==(const StdMyString &str);
    bool operator >(const StdMyString &str);
    bool operator <(const StdMyString &str);
    friend std::ostream& operator <<(std::ostream& os,const StdMyString & str);
    friend std::istream &operator>>(std::istream &is, StdMyString &str);
    operator int();
    operator double();

    MyStringList split(const StdMyString &str);

private:
    char * string ;
    int size ;
    int capacity;

};



std::ostream& operator<<(std::ostream& os,const StdMyString&str);
std::istream& operator>>(std::istream& is,StdMyString& str);

class MyStringList
{
private:
    StdMyString *array;
    int size;
    int capacity;
    
public:
    MyStringList(int capacity= 15); 
    ~MyStringList();
    MyStringList& operator+=(const StdMyString & str);
    MyStringList& operator<<(const StdMyString & str);
    MyStringList operator+(const MyStringList& list);
    friend std::ostream& operator<<(std::ostream& os,const MyStringList& list);
};

std:: ostream& operator<<(std::ostream& os,const MyStringList& list);


#endif