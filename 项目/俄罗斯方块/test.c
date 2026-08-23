#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandomCube()
{
    // 生成随机方块：
    srand((unsigned int)time(NULL));
    int GetRandomNum = rand() % 7 + 1;
    printf("%d\n", GetRandomNum);
    switch (GetRandomNum)
    {
    case 1:
    {
        char CubeShape[4][4] =
            {
                {'X', ' ', ' ', ' '},
                {'X', ' ', ' ', ' '},
                {'X', ' ', ' ', ' '},
                {'X', ' ', ' ', ' '}};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c", CubeShape[i][j]);
            }
            printf("\n");
        }
        return;
    }
    break;
    case 2:
    {
        char CubeShape[4][4] =
            {
                {'X', 'X', ' ', ' '},
                {'X', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' '}};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c", CubeShape[i][j]);
            }
            printf("\n");
        }
        return;
    }
    break;
    case 3:
    {
        char CubeShape[4][4] =
            {
                {' ', 'X', ' ', ' '},
                {'X', 'X', 'X', ' '},
                {' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' '}};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c", CubeShape[i][j]);
            }
            printf("\n");
        }
        return;
    }
    break;
    case 4:
    {
        char CubeShape[4][4] =
            {
                {'X', 'X', ' ', ' '},
                {' ', 'X', 'X', ' '},
                {' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' '}};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c", CubeShape[i][j]);
            }
            printf("\n");
        }
        return;
    }
    break;
    case 5:
    {
        char CubeShape[4][4] =
            {
                {' ', 'X', 'X', ' '},
                {'X', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' '}};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c", CubeShape[i][j]);
            }
            printf("\n");
        }
        return;
    }
    break;
    case 6:
    {
        char CubeShape[4][4] =
            {
                {' ', 'X', ' ', ' '},
                {' ', 'X', ' ', ' '},
                {'X', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '}};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c", CubeShape[i][j]);
            }
            printf("\n");
        }
        return;
    }
    break;
    case 7:
    {
        char CubeShape[4][4] =
            {
                {'X', ' ', ' ', ' '},
                {'X', ' ', ' ', ' '},
                {'X', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '}};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%c", CubeShape[i][j]);
            }
            printf("\n");
        }
        return;
    }
    break;

    default:
        break;
    }

}


void SpinCube(char Cube[4][4])
{
    char temp[4][4];
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            temp[j][3-i] = Cube[i][j];
        }
        printf("\n");
    }
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            Cube[i][j] = temp[i][j];
        }
        printf("\n");
    }
}

int main()
{
    RandomCube();
    SpinCube()
}
