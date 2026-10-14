#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define Size 10

void InitBoard(char (*Board)[Size])
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            Board[i][j] = '-';
        }
    }
}

void PrintBoard(char (*Board)[Size])
{
    printf("      ");
    for (int i = 0; i < Size; i++)
    {
        printf("%3d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < Size; i++)
    {
        printf("%4d ", i + 1);
        for (int j = 0; j < Size; j++)
        {
            printf("%4c", Board[i][j]);
        }
        printf("\n");
    }
}

bool MakeMove(char (*Board)[Size], int row, int column, char player)
{
    if (row < 0 || row >= Size || column < 0 || column >= Size)
    {
        printf("下到棋盘外了，重新输入\n");
        return false;
    }
    if (Board[row][column] != '-')
    {
        printf("这个位置有棋子了，重新输入\n");
        return false;
    }
    Board[row][column] = player;
    return true;
}

bool IsValidPlace(int row, int column)
{
    if (row < 0 || row >= Size || column < 0 || column >= Size)
        return false;
    return true;
}

bool CheckIsWin(char (*Board)[Size], int row, int column, char player)
{
    int direction[4][2] =
        {
            {1, 0},
            {1, 1},
            {0, 1},
            {-1, 1}};

    for (int i = 0; i < 4; i++)
    {
        int count = 1;
        int dx = row + direction[i][0];
        int dy = column + direction[i][1];
        while (IsValidPlace(dx, dy) && Board[dx][dy] == player)
        {
            count++;
            if (count >= 5)
                return true;
            dx += direction[i][0];
            dy += direction[i][1];
        }
        dx = row - direction[i][0];
        dy = column - direction[i][1];
        while (IsValidPlace(dx, dy) && Board[dx][dy] == player)
        {
            count++;
            if (count >= 5)
                return true;
            dx -= direction[i][0];
            dy -= direction[i][1];
        }
    }
    return false;
}

bool CheckIsDraw(char (*Board)[Size])
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if (Board[i][j] == '-')
                return false;
        }
    }
    return true;
}

bool AIMakeMove(char (*Board)[Size], char player, char ai, int PlayerRow, int PlayerColumn)
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if (Board[i][j] == '-')
            {
                Board[i][j] = ai;
                if (CheckIsWin(Board, i, j, ai) == true)
                {
                    return true;
                }
                Board[i][j] = '-';
            }
        }
    }

    rand() % 8;

    int direction[8][2] =
        {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1}};

    while (1)
    {
        srand(time(NULL));
        int i = rand() % 8;
        int dx = PlayerRow + direction[i][0];
        int dy = PlayerColumn + direction[i][1];
        if (IsValidPlace(dx, dy) && Board[dx][dy] == '-')
        {
            Board[dx][dy] = ai;
            return true;
        }
    }
    return false;

}

int main()
{

    char Board[Size][Size] = {0};
    InitBoard(Board);
    char player = 'X';
    int row = 0, column = 0;
    while (1)
    {
        PrintBoard(Board);
        printf("请%c选手下棋！", player);
        if (player == 'X')
        {
            scanf("%d %d", &row, &column);
            if (MakeMove(Board, row - 1, column - 1, player) == false)
            {
                continue;
            }
        }
        else
        {
            printf("ai正在下棋。。。\n");
            if (AIMakeMove(Board, 'X', 'O', row - 1, column - 1) == false)
            {
                continue;
            }
        }

        if (CheckIsWin(Board, row - 1, column - 1, player) == true)
        {
            PrintBoard(Board);
            printf("恭喜|%c|选手获胜\n", player);
            break;
        }

        if (CheckIsDraw(Board) == true)
        {
            PrintBoard(Board);
            printf("平局！\n");
            break;
        }
        player = (player == 'X' ? 'O' : 'X');
    }
    PrintBoard(Board);
    return 0;
}