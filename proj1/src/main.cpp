#include "Screen.h"
int main()
{
    srand(time(0));
    Screen my_screen;
    my_screen.output();
    bool game_continue=true;
    while(game_continue)
    {
        my_screen.input();
        game_continue = my_screen.update();
        my_screen.screen_clear();
        my_screen.output();
    }
}