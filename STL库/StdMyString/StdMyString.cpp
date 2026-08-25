#include "StdMyString.h"
#include <cstring>
#include <iostream>


StdMyString::StdMyString():capacity(15),size(0)
{
    string = new char[capacity];
}

StdMyString::StdMyString(const char * str)
{
    size = strlen(str);
    capacity = size + 1;
    string = new char[capacity];
    strcpy(string,str);
}

StdMyString::StdMyString(const StdMyString & str)
{
    size = str.size;
    capacity = str.capacity;
    string = new char[capacity];
    strcpy(string,str.string);
}

StdMyString::~StdMyString()
{
    delete []string;
}

StdMyString& StdMyString::operator=(const StdMyString & str)
    {
        if(capacity <= str.size)
        {
            capacity = str.capacity;
            delete []string;
            string = new char[capacity];
        }
            strcpy(string,str.string);
            size = str.size;
            return *this;
    }

    StdMyString& StdMyString::operator+=(const StdMyString &str)
    {
        size += str.size;
        if(capacity <= size)
        {
            capacity = size + 1;
            char *newP = new char[capacity];
            strcpy(newP,string);
            delete []string;
            string = newP;
        }
        strcat(string,str.string);
        return *this;
    }

    StdMyString &StdMyString::operator+=(const char & c)
    {
        if(capacity <= size)
        {
            capacity *= 2;
            char *newP = new char[capacity];
            strcpy(newP,string);
            delete []string;
            string = newP;
        }
        string[size++] = c;
        string[size] = '\0';
        return *this;
    }

    StdMyString StdMyString::operator+(const StdMyString &str)
    {
        StdMyString result = *this;
        result += str;
        return result;
    }

    StdMyString &StdMyString::operator-=(const StdMyString &str)
    {
        char *dest =strstr(string,str.string);
        if(dest != nullptr)
        {
            char *back = dest + str.size;
            while(*back != '\0')
                *dest++ = *back++;
            *dest = '\0';
            dest = strstr(string,str.string);
        }
        return *this;
    }

    StdMyString StdMyString::operator-(const StdMyString &str)
    {
        StdMyString result = *this;
        result -= str;
        return result;
    }

char& StdMyString::operator[](int index)
{
    return string[index];
}

bool StdMyString::operator==(const StdMyString &str)
{
    return strcmp(string,str.string)==0;
}

bool StdMyString::operator>(const StdMyString &str)
{
    return strcmp(string,str.string)>0;
}

bool StdMyString::operator<(const StdMyString &str)
{
    return strcmp(string,str.string)<0;
}

StdMyString::operator int()
{
    return atoi(string); 
}

StdMyString::operator double()
{
    return atof(string);
}

MyStringList StdMyString::split(const StdMyString &str)
    {
        StdMyString CPStr = *this;
        MyStringList list;
        char *dest = strtok(CPStr.string,str.string);
        while(dest != nullptr)
        {
            list += dest;
            dest = strtok(nullptr,str.string);
        }
        return list;
    }
std::ostream& operator <<(std::ostream& os,const StdMyString & str)
{
    os<<str.string;
    return os;
}

std::istream &operator>>(std::istream &is, StdMyString &str)
{
    str.size = 0;
    char temp = 0;
    while((temp = getchar())!= '\n')
    {
        str += temp;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const MyStringList &list)
{
    for(int i = 0 ;i < list.size;i++)
    {
        os<<list.array[i]<<std::endl;
    }
    return os;
}

MyStringList::MyStringList(int capacity):size(0),capacity(capacity)
{
    array = new StdMyString[capacity];

}

MyStringList::~MyStringList()
{
    delete []array;
}

MyStringList & MyStringList::operator+=(const StdMyString & str)
{
    if(size >= capacity)
    {
        capacity *= 2;
        StdMyString *newP = new StdMyString[capacity];
        for(int i = 0;i< size; i++)
        {
            newP[i] = array[i];
        }
        delete []array;
        array = newP;
    }
    array[size++] = str;
    return *this; 
}

MyStringList &MyStringList::operator<<(const StdMyString &str)
{
    *this += str;
    return *this;
}

MyStringList MyStringList::operator+(const MyStringList &list)
{
    MyStringList result;
    for(int i = 0;i < size;i++)
    {
        result += array[i];
    }
    for(int i = 0;i < list.size;i++)
    {
        result += list.array[i];
    }
    return result;
}
