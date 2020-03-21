#include "Block.h"
#define MAX_SNAKE_LEN 100
class Snake
{
public:
    Snake();
    void snake_add(const Vector2D& loc);
    bool in_snake(int x_loc, int y_loc) const;
    Vector2D get_loc(int num) const;
    int get_loc_x(int num) const;
    int get_loc_y(int num) const;
    int get_snake_len() const;
    void update(char direct, bool longer);
    Vector2D& head();
    int head_x() const;
    int head_y() const;
    bool is_max() const;
    void snake_add_head(const Vector2D& loc);
private:
    int snake_len;
    int max;
    Vector2D locs[MAX_SNAKE_LEN];
};





