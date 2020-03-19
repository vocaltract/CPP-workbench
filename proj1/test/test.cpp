#include <iostream>
#define DEBUG
#include "../include/debug.h"
using namespace std;
#include <termios.h>
#include <unistd.h>
char getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 0;
    newt.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
int main()
{
    clock_t st = clock();
    while(1)
    {
        char ch=getch();
        if(ch=='a') break;
    }
    cout<<clock()-st;

}

#define KEY_W 0b01010111
#define KEY_A 0b01000001
#define KEY_S 0b01010011
#define KEY_D 0b01000100    
#define KEY_w 0b01110111
#define KEY_a 0b01100001
#define KEY_s 0b01110011
#define KEY_d 0b01100100 