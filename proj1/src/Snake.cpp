#include "Snake.h"
#include "debug.h"
#include "input.h"
Snake::Snake()
{
    max = MAX_SNAKE_LEN;
    snake_len = 2;
    for (int i = 0; i < max; i++)
    {
        if (i == 0 || i == 1)
        {
            locs[i].set(1, i + 1);
        }
    }
}

void Snake::snake_add(const Vector2D& loc)
{
    locs[snake_len].set(loc.get_x(),loc.get_y());
    snake_len++;
}

void Snake::snake_add_head(const Vector2D& loc)
{
    for(int i=snake_len;i>0;i--)
    {
        locs[i] = locs[i-1];
    }
    snake_len++;
    locs[0].set(loc.get_x(),loc.get_y());
}


Vector2D Snake::get_loc(int num) const
{
    if (num <= max)
    {
        return locs[num];
    }
    else
    {
        std::cerr << "get_loc failed!" << std::endl;
        assert(0);
    }
}

int Snake::get_loc_x(int num) const
{
    if (num <= max)
    {
        return locs[num].get_x();
    }
    else
    {
        std::cerr << "get_loc failed!" << std::endl;
        assert(0);
    }
}

int Snake::get_loc_y(int num) const
{
    if (num <= max)
    {
        return locs[num].get_y();
    }
    else
    {
        std::cerr << "get_loc failed!" << std::endl;
        assert(0);
    }
}

int Snake::get_snake_len() const
{
    return snake_len;
}

void Snake::update(char direct, bool longer)
{
    if (!longer)
    {
        for (int i = snake_len-1; i > 0; i--)
        {
            locs[i] = locs[i - 1];
        }
        switch (direct)
        {
        case KEY_a:
            locs[0].dec_y(1);
            break;
        case KEY_A:
            locs[0].dec_y(1);
            break;
        case KEY_w:
            locs[0].dec_x(1);
            break;
        case KEY_W:
            locs[0].dec_x(1);
            break;
        case KEY_s:
            locs[0].inc_x(1);
            break;
        case KEY_S:
            locs[0].inc_x(1);
            break;
        case KEY_d:
            locs[0].inc_y(1);
            break;
        case KEY_D:
            locs[0].inc_y(1);
            break;
        default:
            assert(0);
            break;
        }
    }
    else
    {
        switch (direct)
        {
        case KEY_a:
            snake_add_head(locs[0].y_dec_vec(1));
            break;
        case KEY_A:
            snake_add_head(locs[0].y_dec_vec(1));
            break;
        case KEY_w:
            snake_add_head(locs[0].x_dec_vec(1));
            break;
        case KEY_W:
            snake_add_head(locs[0].x_dec_vec(1));
            break;
        case KEY_s:
            snake_add_head(locs[0].x_inc_vec(1));
            break;
        case KEY_S:
            snake_add_head(locs[0].x_inc_vec(1));
            break;
        case KEY_d:
            snake_add_head(locs[0].y_inc_vec(1));
            break;
        case KEY_D:
            snake_add_head(locs[0].y_inc_vec(1));
            break;
        default:
            assert(0);
            break;
        }

    }
}

Vector2D &Snake::head()
{
    return locs[0];
}

int Snake::head_x() const
{
    return locs[0].get_x();
}
int Snake::head_y() const
{
    return locs[0].get_y();
}

bool Snake::is_max() const
{
    return max==snake_len;
}
bool Snake::in_snake(int x_loc, int y_loc) const
{
    for(int i = 0;i<snake_len;i++)
    {
        if(locs[i].get_x()==x_loc&& locs[i].get_y()==y_loc) return true;
    }
    return false;
}