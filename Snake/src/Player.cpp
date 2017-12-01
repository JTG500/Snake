#include "Player.h"

Player::Player()
{
    key_press = key_event.KeyPressed();
}




int Player::Move()
{

    if (key_press == 'd')
    {
        return 1;
    }
    else if(key_press == 'a')
    {
       return 2;
    }
    else if(key_press == 'w')
    {
        return 3;
    }
    else if (key_press == 's')
    {
        return 4;
    }
}

Player::~Player()
{
    //dtor
}
