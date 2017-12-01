#include "Refresh.h"

Refresh::Refresh()
{
    //ctor
}

void Refresh::setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    fflush(stdout);
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);

}

void Refresh::Display(const int MAP_SIZE_X, const int MAP_SIZE_Y, int previousMap[50][50])
{
    int map[MAP_SIZE_X][MAP_SIZE_Y];
    char convertMap[MAP_SIZE_X][MAP_SIZE_Y];
    for (int i = 0; i != MAP_SIZE_Y; ++i)
    {
        int runStart = -1;
        for (int j = 0; j != MAP_SIZE_X; ++j)
        {
            if (map[i][j] == previousMap[i][j])
            {
                if (map[i][j] == 0)
                {
                    convertMap[i][j] = ' ';
                }
                else if (map[i][j] == 1)
                {
                    convertMap[i][j] = '#';
                }
                else if (map[i][j] == 2)
                {
                    convertMap[i][j] = '>';
                }
                else if (map[i][j] == 3)
                {
                    convertMap[i][j] = '+';
                }
                else if (map[i][j] == 4)
                {
                    convertMap[i][j] = '@';
                }
                if (runStart != -1)
                {
                    setCursorPosition(runStart, i);
                    printf("%s",&convertMap[i][runStart], j - runStart);
                    runStart = -1;
                }
        }
        else if (runStart == -1)
        {
            runStart = j;
        }
    }
    if (runStart != -1)
    {
        setCursorPosition(runStart, i);
        printf("%s",&convertMap[i][runStart], MAP_SIZE_X - runStart);
    }
}
    fflush(stdout);
    //memcpy()previousMap, (char const*)map, MAP_SIZE_X * MAP_SIZE_Y);

}


Refresh::~Refresh()
{
    //dtor
}
