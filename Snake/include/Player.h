#ifndef PLAYER_H
#define PLAYER_H
#include "KeyboardEvent.h"

class Player
{
    public:
        Player();
        KeyboardEvent key_event;
        char key_press;
        int Move();
        virtual ~Player();

    protected:

    private:
};

#endif // PLAYER_H
