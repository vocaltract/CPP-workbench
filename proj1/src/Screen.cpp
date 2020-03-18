#include "Screen.h"
#include "output.h"
Screen::Screen()
{
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

Block& Screen::get_block(const Vector2D &loc)
{
    return blocks[loc.get_x()][loc.get_y()];
}

void Screen::randfood()
{
    do
    {
        food_loc.set(rand() % (len - 2) + 1, rand() % (width - 2) + 1);
    } while (get_appearing(food_loc) == "|" || get_appearing(food_loc)== "-" || get_appearing(food_loc) == "■");
}

void Screen::output()
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