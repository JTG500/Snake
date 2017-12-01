#include "Map.h"

int main()
{
    bool isRunning = true;
    Map map;
    map.Init();

    do
    {
        isRunning = map.Update();
    }
    while(isRunning);
    map.gameOverMessage();
    return 0;
}
