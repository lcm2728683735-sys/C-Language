#ifndef __BOOK_H_
#define __BOOK_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define NameSize 24
#define PhoneNumberSize 12
#define BookSize 512

struct PhoneNumberBookInfo;
struct PhoneNumberBook;

typedef struct PhoneNumberBook Book;
typedef struct PhoneNumberBookInfo BookInfo;

struct PhoneNumberBookInfo
{
    char Name[NameSize];
    char Number[PhoneNumberSize];
};

struct PhoneNumberBook
{
    int Size;
    BookInfo s[BookSize];
};


void show(const Book * a);
void InsertBook(Book* a, const char* name, const char* number);
bool DeleteByName(Book* a, const char* name);
bool DeleteByNumber(Book* a, const char* number);
void SearchFuzzy(const Book* a, const char* keyword);
void SearchNameByNumber(const Book *a,char *number);
void SearchNumberByName(const Book *a,char *name);
bool ChangeBook(Book *a,char *name,char *number); 

#endif