#include <stdio.h>
#include <stdlib.h>

#define row 10
#define column 20
// void InitBoard(char (*Board)[Size])
// {
//     for (int i = 0; i < Size; i++)
//     {
//         for (int j = 0; j < Size; j++)
//         {
//             Board[i][j] = ' ';
//         }
//     }
// }

void PrintBoard()
{
    //打印棋盘
    for(int i = 0;i < row;i++)
    {
        for(int j = 0; j < column; j++)
        {
        printf("\033[4m");
        printf("| ");
        }
        printf("|");
        printf("\n");
    }
    printf("\033[0m");
}




int main()
{
    PrintBoard();
    return 0;
}