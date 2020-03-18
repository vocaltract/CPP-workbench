#include "input.h"

char getch(void)  //网上抄来的代码，自己研究了一下意思。
{
    struct termios oldt, newt;//结构体中包含各种mode flag/
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    //tcgetattr() gets the parameters associated with the object referred by 
    //fd and stores them in the termios structure referenced by termios_p. 
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);// c_lflag指local modes,
    //ECHO flag表示echo input character
    //ICANON表示Enable canonical mode
    //In canonical mode, input is made available line by line, while in 
    //noncanical mode input is available immediately 
    //换言之，将local mode设置为不echo加立即读取的形式
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    //tcsetattr() sets the parameters associated with the terminal from the 
    //structure referred by termios_p
    //Optional_actions  specifies when the changes take effect
    //TCSANOW means the change occurs immediately
    ch = getchar();//标准库函数
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);//将模式改回原样，以免影响
    return ch;
}

