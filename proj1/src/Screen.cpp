#include "Screen.h"
#define DEBUG
#include "input.h"
#include "debug.h"
Screen::Screen()
{
    score = 0;
    gameover = false;
    input_ch = KEY_S;
    len = LEN;     //x
    width = WIDTH; //y
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blocks[i][j].set(i, j);
            if (i == 0 || i == len - 1)
                blocks[i][j].set_appearing("-");
            if (j == 0 || j == width - 1)
                blocks[i][j].set_appearing("|");
        }
    }
    for (int i = 0; i < snake.get_snake_len(); i++)
    {
        blocks[snake.get_loc_x(i)][snake.get_loc_y(i)].set_appearing("■");
    }
    randfood();
    get_block(food_loc).set_appearing("★");
}

string Screen::get_appearing(const Vector2D &loc) const
{
    return blocks[loc.get_x()][loc.get_y()].get_appearing();
}

Block &Screen::get_block(const Vector2D &loc)
{
    return blocks[loc.get_x()][loc.get_y()];
}

void Screen::randfood()
{
    do
    {
        food_loc.set(rand() % (len - 2) + 1, rand() % (width - 2) + 1);
    } while (get_appearing(food_loc) == "|" || get_appearing(food_loc) == "-" || get_appearing(food_loc) == "■");
}

bool Screen::output()
{
    if (!gameover)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < width; j++)
            {
                blocks[i][j].output();
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Your score is " << score << std::endl;
    }
    return gameover;
}

void Screen::input()
{
    char last_input = input_ch;
    clock_t st = clock(), ed;
    do
    {
        input_ch = getch();
        ed = clock();
    } while (!(input_ch == KEY_A || input_ch == KEY_a || input_ch == KEY_W || input_ch == KEY_w || input_ch == KEY_D || input_ch == KEY_d || input_ch == KEY_S || input_ch == KEY_s) && (ed - st) < DELAY); //10^6为1s

    if (!(input_ch == KEY_A || input_ch == KEY_a || input_ch == KEY_W || input_ch == KEY_w || input_ch == KEY_D || input_ch == KEY_d || input_ch == KEY_S || input_ch == KEY_s))
        input_ch = last_input;
    if((input_ch == KEY_w||input_ch ==KEY_W)&&(last_input==KEY_s||last_input==KEY_S))   input_ch = last_input;
    if((input_ch == KEY_S||input_ch ==KEY_s)&&(last_input==KEY_W||last_input==KEY_w))   input_ch = last_input;
    if((input_ch == KEY_A||input_ch ==KEY_a)&&(last_input==KEY_D||last_input==KEY_d))   input_ch = last_input;
    if((input_ch == KEY_D||input_ch ==KEY_d)&&(last_input==KEY_A||last_input==KEY_a))   input_ch = last_input;
}

void Screen::update()
{
    bool longer = false;
    if(snake.is_max()) gameover = true;
    if (input_ch == KEY_d || input_ch == KEY_D)
    {
        if (snake.head_y() + 1 == width - 1)
            gameover = true;
        if (blocks[snake.head_x()][snake.head_y() + 1].get_appearing() == "★")
            longer = true;
        if(snake.in_snake(snake.head_x(),snake.head_y()+1))
            gameover = true;
    }
    else if (input_ch == KEY_a || input_ch == KEY_A)
    {
        if (snake.head_y() - 1 == 0)
            gameover = true;
        if (blocks[snake.head_x()][snake.head_y() - 1].get_appearing() == "★")
            longer = true;
        if(snake.in_snake(snake.head_x(),snake.head_y()-1))
            gameover = true;                        
    }
    else if (input_ch == KEY_s || input_ch == KEY_S)
    {
        if (snake.head_x() + 1 == len - 1)
            gameover = true;
        if (blocks[snake.head_x()+1][snake.head_y()].get_appearing() == "★")
            longer = true;            
        if(snake.in_snake(snake.head_x()+1,snake.head_y()))
            gameover = true;  
    }
    else if (input_ch == KEY_w || input_ch == KEY_w)
    {
        if (snake.head_x() - 1 == 0)
            gameover = true;
        if (blocks[snake.head_x()-1][snake.head_y()].get_appearing() == "★")
            longer = true;
        if(snake.in_snake(snake.head_x()-1,snake.head_y()))
            gameover = true;                          
    }
    


    if (!gameover)
    {
        snake.update(input_ch, longer);
        update_with_snake(snake);
    }
    else
    {

    }
}

void Screen::screen_clear()
{
    system("clear");
}

void Screen::update_with_snake(const Snake &snake)
{
    for (int i = 1; i < len - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            if (blocks[i][j].get_appearing() == "■")
            {
                blocks[i][j].set_appearing(" ");
            }
        }
    }
    for (int i = 0; i < snake.get_snake_len(); i++)
    {
        get_block(snake.get_loc(i)).set_appearing("■");
    }
}
