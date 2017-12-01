#ifndef REFRESH_H
#define REFRESH_H
#include "Clear.h"
#include <stdio.h>


class Refresh
{
    public:
        Refresh();
        Clear clear;
        void setCursorPosition(int, int);
        void Display(const int, const int, int [50][50]);
        ~Refresh();

    protected:

    private:
};

#endif // REFRESH_H
