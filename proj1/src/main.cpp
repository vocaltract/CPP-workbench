#include "Screen.h"
#include <ctime>
int main()
{
    srand(time(0));
    Screen my_screen;
    my_screen.output();
}