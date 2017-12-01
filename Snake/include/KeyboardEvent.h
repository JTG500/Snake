#ifndef KEYBOARDEVENT_H
#define KEYBOARDEVENT_H
#include <conio.h>


class KeyboardEvent
{
    public:
        KeyboardEvent();
        bool isPolling;
        char KeyPressed();
        virtual ~KeyboardEvent();

    protected:

    private:
};

#endif // KEYBOARDEVENT_H
