#include <iostream>

class Person
{
public:
    char name;
    int age;
};

class Student:public Person
{
public: 
    int Number;
    char major;
};

class Course
{
public:
    char LessonName;
    int score;
};