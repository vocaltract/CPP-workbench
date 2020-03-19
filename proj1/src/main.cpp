#include "Screen.h"
int main()
{
    srand(time(0));
    Screen my_screen;
    my_screen.output();
    while(1)
    {
        my_screen.input();
        my_screen.update();
        my_screen.screen_clear();
        my_screen.output();

    }


    
    
    
    
}