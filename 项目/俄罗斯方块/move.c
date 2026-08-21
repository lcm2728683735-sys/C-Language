#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum CubeType
{
    CUBE_I = 0,
    CUBE_O = 1,
    CUBE_T = 2,
    CUBE_Z = 3,
    CUBE_S = 4,
    CUBE_J = 5,
    CUBE_L = 6,
};
typedef enum CubeType CubeType;

struct Cube{
    char shape[4][4];
    int x;
    int y;
    CubeType type;
};
typedef struct Cube Cube;

char CubeShape[7][4][4] =
{
    [CUBE_I] = 
    {
                {'X', ' ', ' ', ' '},
                {'X', ' ', ' ', ' '},
                {'X', ' ', ' ', ' '},
                {'X', ' ', ' ', ' '}
    },   
    [CUBE_O] = 
    {
                {'X', 'X', ' ', ' '},
                {'X', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' '}
    },   
    [CUBE_T] = 
    {
                {'X', 'X', 'X', ' '},
                {' ', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' '}
    },   
    [CUBE_Z] = 
    {
                {'X', 'X', ' ', ' '},
                {' ', 'X', 'X', ' '},
                {' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' '}
    },   
    [CUBE_S] = 
    {
                {' ', 'X', 'X', ' '},
                {'X', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' '}
    },   
    [CUBE_J] = 
    {
                {' ', 'X', ' ', ' '},
                {' ', 'X', ' ', ' '},
                {'X', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '}
    },   
    [CUBE_L] = 
    {
                {'X', ' ', ' ', ' '},
                {'X', ' ', ' ', ' '},
                {'X', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '}
    }
};


// void SpinCube()
// {
//     char temp[4][4];
//     for(int i = 0;i<4;i++)
//     {
//         for(int j = 0;j<4;j++)
//         {
            
//         }
//         printf("\n");
//     }
//     return 0;
// }

    srand((unsigned int)time(NULL));
    int GetRandomNum = rand() % 7 + 1;
    printf("%d\n", GetRandomNum);


int main()
{
    char a[4][4]={
    {'X','X','X','X'},
    {'X','X','X','X'},
    {'X','X','X','X'},
    {'X','X','X','X'}
    };
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}