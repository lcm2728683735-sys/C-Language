#include <stdio.h>
#include <stdbool.h>
#define Size 3

void InitBoard(char (*Board)[Size])
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            Board[i][j] = ' ';
        }
    }
}

void PrintBoard(char (*Board)[Size])
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            printf("%c", Board[i][j]);
            if (j < Size - 1)
                printf(" |");
        }
        printf("\n");
        if (i < Size - 1)
            printf("--|--|--\n");
    }
}

bool MakeMove(char (*Board)[Size], int row, int column, char player)
{
    if (row < 0 || row >= Size || column < 0 || column >= Size)
    {
        printf("下到棋盘外了，重新输入\n");
        return false;
    }
    if (Board[row][column] != ' ')
    {
        printf("这个位置有棋子了，重新输入\n");
        return false;
    }
    Board[row][column] = player;
    return true;
}

bool CheckIsWin(char(*Board)[Size],char player)
{
    for(int i=0;i<Size;i++)
    {
        if(Board[i][0]== player &&
           Board[i][1]== player &&
           Board[i][2]== player)
           {
                return true;
           }
        if((Board[0][i]== player &&
            Board[1][i]== player &&
            Board[2][i]== player))
            {
                return true;
            }
        if((Board[0][0]== player &&
            Board[1][1]== player &&
            Board[2][2]== player))
            {
                return true;
            }
        if((Board[0][2]== player &&
            Board[1][1]== player &&
            Board[2][0]== player))
            {
                return true;
            }
    }
    return false;
}

bool CheckIsDraw(char (*Board)[Size])
{
    for(int i = 0;i<Size;i++)
    {
        for(int j = 0;j<Size;j++)
        {
            if(Board[i][j] == ' ')
            return false;
        }
    }
    return true;
}

int main()
{
    char Board[Size][Size] = {0};
    InitBoard(Board);
    char player = 'X';
    while(1)
    {
        PrintBoard(Board);
        int row = 0 ,column = 0;
        printf("请%c选手下棋！",player);
        scanf("%d %d",&row,&column);
        if(MakeMove(Board,row,column,player)== false)
        {
            continue;
        }

        if(CheckIsWin(Board,player) == true)
        {
            PrintBoard(Board);
            printf("恭喜|%c|选手获胜\n",player);
            break;
        }

        if(CheckIsDraw(Board) == true)
        {
            PrintBoard(Board);
            printf("平局！\n");
            break;
        }
        player =(player =='X' ?'O':'X');
    }
    PrintBoard(Board);
    return 0;
}
