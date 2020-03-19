#include "Block.h"
Block::Block()
{
    appearing = " ";
    loc.set(0,0);
}
Block::Block(int x_loc, int y_loc, string another)
{
    appearing=another;
    loc.set(x_loc,y_loc);
}

string Block::get_appearing() const
{   
    return appearing;
}
void Block::set(int x_loc, int y_loc)
{
    loc.set(x_loc,y_loc);
}

void Block::set_appearing(string fig)
{
    appearing = fig;
}

void Block::output()
{
    std::cout<<appearing;
}

Vector2D& Block::get_vector()
{
    return loc;
}