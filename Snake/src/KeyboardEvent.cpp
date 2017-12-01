#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent()
{
    isPolling = true;
}

char KeyboardEvent::KeyPressed()
{

    while(isPolling == true)
    {
        if (_kbhit())
        {
            return getch();
        }
    }
}

KeyboardEvent::~KeyboardEvent()
{

}
