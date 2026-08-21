#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandomCube()
{
    // 随机方块：
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
        return 0;
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
        return 0;
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
        return 0;
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
        return 0;
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
        return 0;
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
        return 0;
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
        return 0;
    }
    break;

    default:
        break;
    }
}
