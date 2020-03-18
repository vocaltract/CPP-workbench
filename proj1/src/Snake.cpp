#include "Snake.h"
#include "debug.h"
Snake::Snake()
{
    max = MAX_SNAKE_LEN;
    snake_len=2;
    for(int i=0;i<max;i++)
    {
        if(i==0||i==1) 
        {
            valids[i] = true;
            locs[i].set(1,i+1);
        }
        else
        {
            valids[i] = false;
        } 
    }
}
Vector2D Snake::get_loc(int num) const
{
    if(num<=max && valids[num]) 
    {
        return locs[num];
    }
    else
    {
        std::cerr<<"get_loc failed!"<<std::endl;
        assert(0);
    }
}

int Snake::get_loc_x(int num) const
{
    if(num<=max && valids[num]) 
    {
        return locs[num].get_x();
    }
    else
    {
        std::cerr<<"get_loc failed!"<<std::endl;
        assert(0);
    }
}


int Snake::get_loc_y(int num) const
{
    if(num<=max && valids[num]) 
    {
        return locs[num].get_y();
    }
    else
    {
        std::cerr<<"get_loc failed!"<<std::endl;
        assert(0);
    }
}


int Snake::get_snake_len() const
{
    return snake_len;
}