#include "Block.h"
#define MAX_SNAKE_LEN 40
class Snake
{
public:
    Snake();
    void up();
    void down();
    void left();
    void right();
    Vector2D get_loc(int num) const;
    int get_loc_x(int num) const;
    int get_loc_y(int num) const;
    int get_snake_len() const;
private:
    int snake_len;
    int max;
    bool valids[MAX_SNAKE_LEN];
    Vector2D locs[MAX_SNAKE_LEN];
};





