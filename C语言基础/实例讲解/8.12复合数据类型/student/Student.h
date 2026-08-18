#ifndef __STUDENT_H_
#define __STUDENT_H_
struct Student 
{
    char Name[24]; 
    int id;
    int age;
    double score; 
}; 
typedef struct Student Stu;
void PrintStu(const Stu *s);
void SetStuValue(Stu *t,const char *name,int id,int age,double score);

#endif