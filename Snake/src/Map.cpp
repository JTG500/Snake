#include "Map.h"

Map::Map()
{
    saveFruitX = FindXPosOfFruit();
    saveFruitY = FindYPosOfFruit();
    score = 0;
}


void Map::Init()
{
     DrawMap();
}

void Map::DrawMap()
{
    for (int i = 0; i < MAP_SIZE_X; i++)
    {
        for (int j = 0; j < MAP_SIZE_Y; j++)
        {
            if (mapCounter == MAP_SIZE_Y)
            {
                printf("\n");
                mapCounter = 0;
            }
            if (map[i][j] == BORDER_SPACE)
            {
                printf("%c",BORDER);
            }
            else if (map[i][j] == EMPTY_SPACE)
            {
                printf(" ");
            }
            else if (map[i][j] == SPECIAL_EMPTY_SPACE)
            {
                printf("|");
            }
            else if (map[i][j] == PLAYER_SPACE)
            {
                printf("%c", snake);
            }
            else if (map[i][j] == TAIL_SPACE)
            {
                printf("%c", TAIL);
            }
            else if (map[i][j] == FRUIT_SPACE)
            {
                printf("@");
            }
            mapCounter++;
        }
    }
}


int Map::FindXPosOfPlayer()
{
    int xPos;
    for(int i = 0; i < MAP_SIZE_X; i++)
    {
        for (int j = 0; j < MAP_SIZE_Y; j++)
        {
            if (map[i][j] == PLAYER_SPACE)
                xPos = i;
        }
    }
    return xPos;
}

int Map::FindYPosOfPlayer()
{
    int yPos;
    for(int i = 0; i < MAP_SIZE_X; i++)
    {
        for (int j = 0; j < MAP_SIZE_Y; j++)
        {
            if (map[i][j] == PLAYER_SPACE)
                yPos = j;
        }
    }
    return yPos;
}

int Map::FindXPosOfFruit()
{
    int xPos;
    for(int i = 0; i < MAP_SIZE_X; i++)
    {
        for (int j = 0; j < MAP_SIZE_Y; j++)
        {
            if (map[i][j] == FRUIT_SPACE)
                xPos = i;
        }
    }
    return xPos;
}

int Map::FindYPosOfFruit()
{
    int yPos;
    for(int i = 0; i < MAP_SIZE_X; i++)
    {
        for (int j = 0; j < MAP_SIZE_Y; j++)
        {
            if (map[i][j] == FRUIT_SPACE)
                yPos = j;
        }
    }
    return yPos;
}

int Map::FindXPosOfTail()
{
    int xPos;
    for(int i = 0; i < MAP_SIZE_X; i++)
    {
        for (int j = 0; j < MAP_SIZE_Y; j++)
        {
            if (map[i][j] == TAIL_SPACE)
                xPos = i;
        }
    }
    return xPos;
}

int Map::FindYPosOfTail()
{
    int yPos;
    for(int i = 0; i < MAP_SIZE_X; i++)
    {
        for (int j = 0; j < MAP_SIZE_Y; j++)
        {
            if (map[i][j] == TAIL_SPACE)
                yPos = j;
        }
    }
    return yPos;

}

int Map::findEndOfTailX()
{
    int xPos = 0;
    for(int i = 0; i < MAP_SIZE_X; i++)
    {
        for (int j = 0; j < MAP_SIZE_Y; j++)
        {
            if (map[i][j] == TAIL_SPACE)
            {
                if (map[i+1][j] == SPECIAL_EMPTY_SPACE)
                {
                    xPos = i;
                    break;
                }
                else if (map[i-1][j] == SPECIAL_EMPTY_SPACE)
                {
                    xPos = i;
                    break;
                }
                else if (map[i][j+1] == SPECIAL_EMPTY_SPACE)
                {
                    xPos = i;
                    break;
                }
                else if (map[i][j-1] == SPECIAL_EMPTY_SPACE)
                {
                    xPos = i;
                    break;
                }
            }
        }
    }
    return xPos;
}

int Map::findEndOfTailY()
{
    int yPos = 0;

    for(int i = 0; i < MAP_SIZE_X; i++)
    {
        for (int j = 0; j < MAP_SIZE_Y; j++)
        {
            if (map[i][j] == TAIL_SPACE)
            {
                if (map[i+1][j] == SPECIAL_EMPTY_SPACE)
                {
                    yPos = j;
                    break;
                }
                else if (map[i-1][j] == SPECIAL_EMPTY_SPACE)
                {
                    yPos = j;
                    break;
                }
                else if (map[i][j+1] == SPECIAL_EMPTY_SPACE)
                {
                    yPos = j;
                    break;
                }
                else if (map[i][j-1] == SPECIAL_EMPTY_SPACE)
                {
                    yPos = j;
                    break;
                }
            }
        }
    }
    return yPos;
}


bool Map::isFruit()
{
    getSnakeX = FindXPosOfPlayer();
    getSnakeY = FindYPosOfPlayer();
    if ((getSnakeY == saveFruitY) && (getSnakeX == saveFruitX))
    {
        return true;
    }
    else
        return false;

}

void Map::populateFruit()
{
    srand(time(NULL));
    do
    {
        randomFruitX = rand()%48;
        randomFruitY = rand()%48;
    }
    while (map[randomFruitX][randomFruitY] != EMPTY_SPACE);
    map[randomFruitX][randomFruitY] = FRUIT_SPACE;
    saveFruitX = randomFruitX;
    saveFruitY = randomFruitY;
}

bool Map::isGameOver(int playerX, int playerY)
{
     if (map[playerX][playerY] == TAIL_SPACE)
     {
         return true;
     }
     if (playerX == 0 || playerX == 49)
     {
        return true;
     }
     else if (playerY == 0 || playerY == 49)
     {
        return true;
     }
    else
        return false;
}

bool Map::isGrow()
{
    if (isFruit() == true)
    {
         tail_count++;
         score++;
         populateFruit();
         return true;
    }
    return false;
}

bool Map::Update()
{
    char key_press = key_event.KeyPressed();
    char previous_key_press;

    if (key_press == 'd')
    {
        snake = '>';
        do
        {
            bool isGrown = isGrow();
            int getSnakeX = FindXPosOfPlayer();
            int getSnakeY = FindYPosOfPlayer();
            int getEndOfTailX = findEndOfTailX();
            int getEndOfTailY = findEndOfTailY();
            clear.ClearScreen();
            printf("%s%d", "SCORE: ",score);

            if (isGameOver(getSnakeX, getSnakeY+1) == false)
            {
                map[getSnakeX][getSnakeY+1] = map[getSnakeX][getSnakeY];
                if (isGrown == true)
                {
                    map[getSnakeX][getSnakeY] = TAIL_SPACE;
                    if (tail_count == 1)
                        map[getSnakeX][getSnakeY-1] = SPECIAL_EMPTY_SPACE;

                }
                else if (isGrown == false && tail_count == 0)
                {
                     for (int i = 0; i < MAP_SIZE_X; i++)
                    {
                        for (int j = 0; j < MAP_SIZE_Y; j++)
                        {
                            if (map[i][j] == SPECIAL_EMPTY_SPACE)
                            {
                                map[i][j] = EMPTY_SPACE;
                                break;
                            }
                        }
                    }
                    map[getSnakeX][getSnakeY] = SPECIAL_EMPTY_SPACE;
                }
                else if (isGrown == false && tail_count > 0)
                {
                    map[getSnakeX][getSnakeY] = TAIL_SPACE;
                    for (int i = 0; i < MAP_SIZE_X; i++)
                    {
                        for (int j = 0; j < MAP_SIZE_Y; j++)
                        {
                            if (map[i][j] == SPECIAL_EMPTY_SPACE)
                            {
                                map[i][j] = EMPTY_SPACE;
                                break;
                            }
                        }
                    }
                    map[getEndOfTailX][getEndOfTailY] = SPECIAL_EMPTY_SPACE;
                }
                previous_key_press = key_press;
                DrawMap();
                Sleep(100);
            }
            else
                return false;
        }
        while (!_kbhit());
    }
    else if(key_press == 'a')
    {
        snake = '<';
        do
        {
            bool isGrown = isGrow();
            int getSnakeX = FindXPosOfPlayer();
            int getSnakeY = FindYPosOfPlayer();
            int getEndOfTailX = findEndOfTailX();
            int getEndOfTailY = findEndOfTailY();
            clear.ClearScreen();
            printf("%s%d", "SCORE: ",score);
            if (isGameOver(getSnakeX, getSnakeY-1) == false)
            {
                map[getSnakeX][getSnakeY-1] = map[getSnakeX][getSnakeY];
                if (isGrown == true)
                {
                    map[getSnakeX][getSnakeY] = TAIL_SPACE;
                    if (tail_count == 1)
                        map[getSnakeX][getSnakeY+1] = SPECIAL_EMPTY_SPACE;

                }
                else if (isGrown == false && tail_count == 0)
                {
                     for (int i = 0; i < MAP_SIZE_X; i++)
                    {
                        for (int j = 0; j < MAP_SIZE_Y; j++)
                        {
                            if (map[i][j] == SPECIAL_EMPTY_SPACE)
                            {
                                map[i][j] = EMPTY_SPACE;
                                break;
                            }
                        }
                    }
                    map[getSnakeX][getSnakeY] = SPECIAL_EMPTY_SPACE;
                }
                else if (isGrown == false && tail_count > 0)
                {
                    map[getSnakeX][getSnakeY] = TAIL_SPACE;
                    for (int i = 0; i < MAP_SIZE_X; i++)
                    {
                        for (int j = 0; j < MAP_SIZE_Y; j++)
                        {
                            if (map[i][j] == SPECIAL_EMPTY_SPACE)
                            {
                                map[i][j] = EMPTY_SPACE;
                                break;
                            }
                        }
                    }
                    map[getEndOfTailX][getEndOfTailY] = SPECIAL_EMPTY_SPACE;
                }
                previous_key_press = key_press;
                DrawMap();
                Sleep(100);
            }
            else
                return false;
        }
        while (!_kbhit());
    }
    else if(key_press == 'w')
    {
        snake = '^';
        do
        {
            bool isGrown = isGrow();
            int getSnakeX = FindXPosOfPlayer();
            int getSnakeY = FindYPosOfPlayer();
            int getEndOfTailX = findEndOfTailX();
            int getEndOfTailY = findEndOfTailY();
            clear.ClearScreen();
            printf("%s%d", "SCORE: ",score);
            if (isGameOver(getSnakeX-1, getSnakeY) == false)
            {
                map[getSnakeX-1][getSnakeY] = map[getSnakeX][getSnakeY];
                if (isGrown == true)
                {
                    map[getSnakeX][getSnakeY] = TAIL_SPACE;
                    if (tail_count == 1)
                        map[getSnakeX+1][getSnakeY] = SPECIAL_EMPTY_SPACE;

                }
                else if (isGrown == false && tail_count == 0)
                {
                     for (int i = 0; i < MAP_SIZE_X; i++)
                    {
                        for (int j = 0; j < MAP_SIZE_Y; j++)
                        {
                            if (map[i][j] == SPECIAL_EMPTY_SPACE)
                            {
                                map[i][j] = EMPTY_SPACE;
                                break;
                            }
                        }
                    }
                    map[getSnakeX][getSnakeY] = SPECIAL_EMPTY_SPACE;
                }
                else if (isGrown == false && tail_count > 0)
                {
                    map[getSnakeX][getSnakeY] = TAIL_SPACE;
                    for (int i = 0; i < MAP_SIZE_X; i++)
                    {
                        for (int j = 0; j < MAP_SIZE_Y; j++)
                        {
                            if (map[i][j] == SPECIAL_EMPTY_SPACE)
                            {
                                map[i][j] = EMPTY_SPACE;
                                break;
                            }
                        }
                    }
                    map[getEndOfTailX][getEndOfTailY] = SPECIAL_EMPTY_SPACE;
                }
                previous_key_press = key_press;
                DrawMap();
                Sleep(100);
            }
            else
                return false;
        }
        while (!_kbhit());
    }
    else if (key_press == 's')
    {
        snake = 'V';
        do
        {
            bool isGrown = isGrow();
            int getSnakeX = FindXPosOfPlayer();
            int getSnakeY = FindYPosOfPlayer();
            int getEndOfTailX = findEndOfTailX();
            int getEndOfTailY = findEndOfTailY();
            clear.ClearScreen();
            printf("%s%d", "SCORE: ",score);
            if (isGameOver(getSnakeX+1, getSnakeY) == false)
            {
                 map[getSnakeX+1][getSnakeY] = map[getSnakeX][getSnakeY];
                if (isGrown == true)
                {
                    map[getSnakeX][getSnakeY] = TAIL_SPACE;
                    if (tail_count == 1)
                        map[getSnakeX-1][getSnakeY] = SPECIAL_EMPTY_SPACE;

                }
                else if (isGrown == false && tail_count == 0)
                {
                     for (int i = 0; i < MAP_SIZE_X; i++)
                    {
                        for (int j = 0; j < MAP_SIZE_Y; j++)
                        {
                            if (map[i][j] == SPECIAL_EMPTY_SPACE)
                            {
                                map[i][j] = EMPTY_SPACE;
                                break;
                            }
                        }
                    }
                    map[getSnakeX][getSnakeY] = SPECIAL_EMPTY_SPACE;
                }
                else if (isGrown == false && tail_count > 0)
                {
                    map[getSnakeX][getSnakeY] = TAIL_SPACE;
                    for (int i = 0; i < MAP_SIZE_X; i++)
                    {
                        for (int j = 0; j < MAP_SIZE_Y; j++)
                        {
                            if (map[i][j] == SPECIAL_EMPTY_SPACE)
                            {
                                map[i][j] = EMPTY_SPACE;
                                break;
                            }
                        }
                    }
                    map[getEndOfTailX][getEndOfTailY] = SPECIAL_EMPTY_SPACE;
                }
                previous_key_press = key_press;
                DrawMap();
                Sleep(100);
            }
            else
            {
                return false;
            }
        }
        while (!_kbhit());
    }
    return true;
}

void Map::gameOverMessage()
{
    clear.ClearScreen();
    printf("%s%d%s","\n\n\n\n\t\tSORRY GAME OVER! YOUR FINAL SCORE IS: ", score ,"\n\n\n");
}

Map::~Map()
{

}
