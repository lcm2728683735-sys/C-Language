#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "book.h"

// enum Menu
// {
//     show,
//     InsertBook,
//     DeleteByName,
//     DeleteByNumber,
//     SearchFuzzy,
// }

int main()
{
    Book a;
    InsertBook(&a,"zhangsan","123456");
    InsertBook(&a,"lisi","67890");
    // SearchFuzzy(&a,"6");
    // SearchFuzzy(&a,"li");
    // DeleteByName(&a,"lisi");
    // DeleteByNumber(&a,"123456");
    // show(&a);
    SearchNameByNumber(&a,"123456");
    SearchNumberByName(&a,"zhangsan");
    ChangeBook(&a,"zhangsan","123456");
    show(&a);
    // printf("1、插入\n");
    return 0;
}