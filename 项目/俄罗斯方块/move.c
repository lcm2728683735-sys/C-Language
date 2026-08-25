#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
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

struct Cube
{
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
                {'X', ' ', ' ', ' '}},
        [CUBE_O] =
            {
                {' ', ' ', ' ', ' '},
                {' ', 'X', 'X', ' '},
                {' ', 'X', 'X', ' '},
                {' ', ' ', ' ', ' '}},
        [CUBE_T] =
            {
                {' ', ' ', ' ', ' '},
                {' ', 'X', ' ', ' '},
                {'X', 'X', 'X', ' '},
                {' ', ' ', ' ', ' '}},
        [CUBE_Z] =
            {
                {' ', ' ', ' ', ' '},
                {' ', 'X', 'X', ' '},
                {' ', ' ', 'X', 'X'},
                {' ', ' ', ' ', ' '}},
        [CUBE_S] =
            {
                {' ', ' ', ' ', ' '},
                {' ', 'X', 'X', ' '},
                {'X', 'X', ' ', ' '},
                {' ', ' ', ' ', ' '}},
        [CUBE_J] =
            {
                {' ', ' ', 'X', ' '},
                {' ', ' ', 'X', ' '},
                {' ', 'X', 'X', ' '},
                {' ', ' ', ' ', ' '}},
        [CUBE_L] =
            {
                {' ', 'X', ' ', ' '},
                {' ', 'X', ' ', ' '},
                {' ', 'X', 'X', ' '},
                {' ', ' ', ' ', ' '}}};

Cube CreateCube()
{

    Cube cube;

    cube.x = 0;
    cube.y = 0;

    cube.type = rand() % 7;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cube.shape[i][j] = CubeShape[cube.type][i][j];
        }
    }
    return cube;
}

void PrintCube(Cube cube)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printw("|%c", cube.shape[i][j]);
        }
        printw("|\n");
    }
    printw("\n");
}

Cube SpinCube(Cube cube)
{
    char temp[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temp[j][3 - i] = cube.shape[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cube.shape[i][j] = temp[i][j];
        }
    }
    return cube;
}

// ��������

Cube KeyboardInput(Cube ActiveCube)
{
    int InputSign;
    InputSign = getch();
    switch (InputSign)
    {
    case KEY_UP:
    case 'w':
    case 'W':
        ActiveCube = SpinCube(ActiveCube);
        break;

    case KEY_LEFT:
    case 'a':
    case 'A':
        ActiveCube.x--;
        break;

    case KEY_RIGHT:
    case 'd':
    case 'D':
        ActiveCube.x++;
        break;

    case KEY_DOWN:
    case 's':
    case 'S':
        ActiveCube.y--;
        break;

    case 'q':
    case 'Q':
        return ActiveCube;
    }

    return ActiveCube;
}

int counter(Cube cube)
{
    int count = 0;
    count++;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cube.shape[i][j] =cube.shape[i][j-1];
        }
    }
    // sleep(1);
    return count;
}
// int main()
// {
//     // 生成随机时间
//     srand((unsigned int)time(NULL));

//     initscr();
//     keypad(stdscr, TRUE);
//     noecho();

//     // 1. 测试随机方块
//     // srand((unsigned int)time(NULL));
//     // Cube myCube = CreateCube();
//     // PrintCube(myCube);

// }

int main()
{
    setlocale(LC_ALL, "");
    srand((unsigned int)time(NULL));

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, TRUE);
    Cube myCube = CreateCube();
    int time = 0;
    while (1)
    {
        counter(myCube);
        myCube = KeyboardInput(myCube);

        clear();

        PrintCube(myCube);

        printw("zuobiao:(%d, %d)\n", myCube.x, myCube.y);
        printw("TIME:%d\n",time);
        time++;

        // myCube.y - counter();

        refresh();

        // napms(50);
        usleep(100000);
    }

    endwin();

    return 0;
}
